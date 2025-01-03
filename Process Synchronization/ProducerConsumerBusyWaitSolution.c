#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in=0,out=0;

//flags to include whether a slot is empty or full

int empty_slots=BUFFER_SIZE;
int full_slots=0;

void* producer(void* arg){
    int item=1;
    while(1){
        //wait until there is an empty slot
        while(empty_slots==0);
        
        buffer[in]=item;
        printf("Produced item %d at index %d\n",item,in);
        in=(in+1)%BUFFER_SIZE;
        item++;
        
        //update empty and full slot counts
        empty_slots--;
        full_slots++;
        sleep(1);//simulate some work
    }
    pthread_exit(NULL);
}
void* consumer(void* arg){
    while(1){
        //wait until there is full slots
        while(full_slots==0);
        int item=buffer[out];
        printf("consumed item %d from index %d \n",item,out);
        out=(out+1)%BUFFER_SIZE;
        
        //update empty and full slot counts
        empty_slots++;
        full_slots--;
        
        sleep(2);//simulate some work
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t producer_thread, consumer_thread;

    // create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

