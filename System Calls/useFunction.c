#include <unistd.h>

int main()
{
    // here write(int fd(0,1,2),const void*buf, size_t count);
    // writes Hello on screen
    write(1, "Hello", 5);
    // writes He on screen
    write(1, "Hello", 2);
    // writes garbage on screen
    write(1, "Hello", 20);
    return 0;
}