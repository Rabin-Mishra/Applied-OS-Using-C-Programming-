#include<stdio.h>
#include<unistd.h>

//shared variable

int g=5;
int main(){
    int pid;
    //creating a parent and child process
    
    pid=fork();
    
    //executed by parent process
    
    if(pid>0){
        int x=g;
        x++;
        sleep(1);
        g=x;
        printf("\n Parent g=%d",g);
    }
    //executed by child process
    else{
        int y=g;
        y--;
        sleep(1);
        g=y;
        printf("\n child g=%d",g);
    }
    //executed by both parent and child process
    
    printf("\n Last g=%d",g);
    return 0;
}