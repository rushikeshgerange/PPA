#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    char Arr[] = "Pre-Placement Activity";
    int iRet = 0;

    fd = open("Marvellous.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file \n");
    }
    else
    {
        iRet = write(fd,Arr,22);
        printf("%d number of bytes gets successfully written into the file \n ",iRet);

        close(fd);
    }

    return 0;
}