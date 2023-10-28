// # : Newly Added Line

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;      // #
}NODE , *PNODE , **PPNODE; 

void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;   // #

    if(*Head == NULL)    // LL is Empty
    {
        *Head = newn;
    }
    else     // LL contains at-least one Node
    {
        (*Head)->prev = newn;    // #
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head , int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;   // #

    if(*Head == NULL)    // LL is Empty
    {
        *Head = newn;
    }
    else     // LL contains at-least one Node
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;    // #
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)       // LL is Empty
    {
        return;
    }
    else if((*Head)->next == NULL)   // LL has 1 Node
    {
        free(*Head);
        *Head = NULL;
    }
    else     // LL has more than 1 Node
    {
        *Head = (*Head)->next;
        free((*Head)->prev);    // #
        (*Head)->prev = NULL;  // #
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)       // LL is Empty
    {
        return;
    }
    else if((*Head)->next == NULL)   // LL has 1 Node
    {
        free(*Head);
        *Head = NULL;
    }
    else     // LL has more than 1 Node
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE Head)
{
    printf("Elements of Linked list are : \n");

    printf("NULL <=> ");
    while(Head != NULL)
    {
        printf("| %d | <=> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    
    return iCount;
}

void InsertAtPos(PPNODE Head , int No , int iPos)
{
    int iLength = 0;
    PNODE newn = NULL;

    iLength = Count(*Head);
    
    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head , No);
    }
    else if(iPos == iLength + 1)
    {
        InsertLast(Head , No);
    }
    else
    {
        for(iCnt = 1 ; iCnt < iPos - 1 ; iCnt++)
        {
            temp = temp->next;
        }
        
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;   // #

        newn->next = temp->next;       
        temp->next->prev = newn;      // #
        temp->next = newn;
        newn->prev = temp;            // #
    }
}

void DeleteAtPos(PPNODE Head , int iPos)
{
    int iLength = 0;
    iLength = Count(*Head);
    
    int iCnt = 0;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1 ; iCnt < iPos - 1 ; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);      // #
        temp->next->prev = temp;     // #
    }
}

int main()
{
    PNODE First = NULL;

    int iRet = 0;

    InsertFirst(&First , 101);
    InsertFirst(&First , 51);
    InsertFirst(&First , 21);
    InsertFirst(&First , 11);

    iRet = Count(First);
    printf("Number of Elements are : %d\n",iRet);

    Display(First);
    
    printf("\n");

    InsertLast(&First , 111);
    InsertLast(&First , 121);

    iRet = Count(First);
    printf("Number of Elements are : %d\n",iRet);

    Display(First);
    
    printf("\n");

    InsertAtPos(&First , 55 , 4);

    iRet = Count(First);
    printf("Number of Elements are : %d\n",iRet);

    Display(First);
    
    printf("\n");

    DeleteAtPos(&First , 4);
    iRet = Count(First);
    printf("Number of Elements are : %d\n",iRet);

    Display(First);

    printf("\n");

    DeleteFirst(&First);
    DeleteLast(&First);

    iRet = Count(First);
    printf("Number of Elements are : %d\n",iRet);

    Display(First);
    
    printf("\n");

    return 0;
}