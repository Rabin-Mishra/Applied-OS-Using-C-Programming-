/*
NAME
open - open and possibly create a file
SYNOPSIS
    #include <sys/types.h>
    #include <sys/stat.h>
#include <sys/fcntl.h>

    int open(const char *pathname, int flags);
    int open(const char *pathname, int flags, mode_t mode);
DESCRIPTION
    open() opens/creates a file and returns the file descriptor of such files.

*/
#include <stdio.h>     //required for perror function
#include <sys/types.h> //required for mode_t(file attributes),ssize_t(signed long)
#include <fcntl.h>     //Required for opent function and flag constants
#include <sys/stat.h>  //requred for mode_t type and permission constants
#include <unistd.h>    //required for close function

int main()
{
    const char *filename = "example.txt";

    int flags = O_WRONLY | O_CREAT;  // open for writing and create
    mode_t mode = S_IRUSR | S_IWUSR; // user had read and write permissions

    int fd = open(filename, flags, mode);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // file is open and can be written to or  read from  using file descriptor (fd)
    write(fd, "Hello World ", 11);

    // close the file when done

    close(fd);
    return 0;
}
