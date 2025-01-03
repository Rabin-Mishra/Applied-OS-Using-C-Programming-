#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

const int BUFFER_SIZE = 5;

class Monitor {
private:
    std::queue<int> buffer;
    int count;
    std::mutex mutex;
    std::condition_variable not_full;
    std::condition_variable not_empty;

public:
    Monitor() : count(0) {}
        
    // Inserts an item into the buffer
    void insertItem(int item) {
        std::unique_lock<std::mutex> lock(mutex);
        not_full.wait(lock, [this] { return count < BUFFER_SIZE; });

        buffer.push(item);
        count++;

        lock.unlock();
        not_empty.notify_one(); // Signal that buffer is not empty
    }

    // Removes an item from the buffer
    int removeItem() {
        std::unique_lock<std::mutex> lock(mutex);
        not_empty.wait(lock, [this] { return count > 0; });

        int item = buffer.front();
        buffer.pop();
        count--;

        lock.unlock();
        not_full.notify_one(); // Signal that buffer is not full

        return item;
    }
};

// Producer function
void producer(Monitor& monitor) {
    for (int i = 0; i < 100; i++) {
        monitor.insertItem(i);
        std::cout << "Producer produced item: " << i << std::endl;
        // Simulates some work being done
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }
}

// Consumer function
void consumer(Monitor& monitor) {
    for (int i = 0; i < 100; i++) {
        int item = monitor.removeItem();
        std::cout << "Consumer consumed item: " << item << std::endl;
        // Simulate some work being done
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Monitor monitor;

    std::thread producerThread(producer, std::ref(monitor));
    std::thread consumerThread(consumer, std::ref(monitor));

    producerThread.join();
    consumerThread.join();

    return 0;
}
//first ma use huney vaneko encapsulation