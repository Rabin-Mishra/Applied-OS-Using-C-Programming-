#include <unistd.h>
#include <stdio.h>

int main()
{
    int count;
    count = write(1, "Hello", 5);

    printf("\n The write system call wrote %d charactes", count);
//here the statement will show the number of buffer printed
    return 0;
}