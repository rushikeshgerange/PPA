#include<stdio.h>

int main()
{
    int i= 1;
    int Count = 0;
    
    printf("How many time you want to display Jay Ganesh on screen : ");
    scanf("%d",&Count);

    while(i<=Count)
    {
        printf("Jay Ganesh...\n");
        i++;
    }

    return 0;
}