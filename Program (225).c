// Doubly linear Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;      // #
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;           // #
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE temp = *Head;

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;          // #
    }
}

void InsertAtPos(PPNODE Head, int No, int ipos)
{
    
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)    // LL is empty
    {
        return;
    }
    else if(((*Head)->next == NULL) && ((*Head)->prev == NULL))     // #    single node in it
    {
        free(*Head);
        *Head = NULL;
    }
    else                   // LL contain 2 or more node in it
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)    // LL is empty
    {
        return;
    }
    else if(((*Head)->next == NULL) && ((*Head)->prev == NULL))     // #    single node in it
    {
        free(*Head);
        *Head = NULL;
    }
    else                   // LL contain 2 or more node in it
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }   
}

void DeleteAtPos(PPNODE Head, int ipos)
{
    
}

void Display(PNODE Head)
{
    printf("Contents of the linked list are : \n");

    printf("NULL <=>");

    while(Head != NULL)
    {
        printf("| %d | <=> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;
    PNODE First = NULL;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);

    iRet = Count(First);

    printf("Total number of nodes in the linked list are : %d \n", iRet);

    InsertLast(&First,101);
    InsertLast(&First,111);
    InsertLast(&First,121);

    Display(First);

    iRet = Count(First);

    printf("Total number of nodes in the linked list are : %d \n", iRet);

    DeleteFirst(&First);

    Display(First);

    iRet = Count(First);

    printf("Total number of nodes in the linked list are : %d \n", iRet);

    DeleteLast(&First);

    Display(First);

    iRet = Count(First);

    printf("Total number of nodes in the linked list are : %d \n", iRet);

    return 0;
}