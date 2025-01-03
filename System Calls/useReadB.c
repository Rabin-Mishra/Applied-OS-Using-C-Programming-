#include <unistd.h>
#include <stdio.h>

int main()
{

    char buffer[50];
    int count;
    // stores the number of character read from keyboard

    count = read(0, buffer, 5);

    // writes the output of read characters on screen

    write(1, buffer, count);
    printf("\nThe count is %d", count);

    return 0;
}