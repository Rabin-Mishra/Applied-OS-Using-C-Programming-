#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

pthread_mutex_t mutex;
sem_t empty_slots, full_slots;

void* producer(void* arg) {
    int item = 1;
    while (1) {
        // Wait for an empty slot
        sem_wait(&empty_slots);

        // Protect the critical section with a mutex
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item++;

        // Release the mutex
        pthread_mutex_unlock(&mutex);

        // Signal that a slot is now full
        sem_post(&full_slots);

        sleep(1); // Simulate some work
    }
}

void* consumer(void* arg) {
    while (1) {
        // Wait for a full slot
        sem_wait(&full_slots);

        // Protect the critical section with a mutex
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        // Release the mutex
        pthread_mutex_unlock(&mutex);

        // Signal that a slot is now empty
        sem_post(&empty_slots);

        sleep(2); // Simulate some work
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    return 0;
}
