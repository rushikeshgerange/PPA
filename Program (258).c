// To close the file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    fd = open("Program283.c", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file \n");
    }
    else
    {
        printf("File is successfully open with fd : %d\n",fd);
        close(fd);
        printf("File gets successfully closed.");
    }

    return 0;
}