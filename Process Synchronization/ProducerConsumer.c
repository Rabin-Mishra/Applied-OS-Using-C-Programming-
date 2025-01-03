#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in=0,out=0;

void* producer(void* arg){
    int item=1;
    while(1){
        //produce item and add to buffer without synchronization
        buffer[in]=item;
        printf("\nProduced item %d at index %d\n",item,in);
        in=(in+1)%BUFFER_SIZE;
        item++;
        
        sleep(1);//simuate some work
    }
    pthread_exit(NULL);
}

void* consumer(void* arg){
    while(1){
        //consume item from buffer without synchronization
        int item=buffer[out];
        printf("\nconsumed item %d from index %d\n",item,out);
        out=(out+1)%BUFFER_SIZE;
        
        sleep(2);//simulate some work
    }
    pthread_exit(NULL);
}
int main(){
    pthread_t producer_thread,consumer_thread;
    //create producer and consumer threads
    
    pthread_create(&producer_thread,NULL,producer,NULL);
    pthread_create(&consumer_thread,NULL,consumer,NULL);
    
    //join threads
    pthread_join(producer_thread,NULL);
    pthread_join(consumer_thread,NULL);
    
    return 0;
}