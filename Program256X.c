#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Display(PNODE Head)
{
    printf("Elements of Linked List are : \n");

    while(Head != NULL)
    {
        printf("%d\t",Head->data);
        Head = Head->next;
    }
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

void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;
    //Allocate memory for node
    newn = (PNODE)malloc(sizeof(NODE));  //newn = (struct Node*)malloc(sizeof(struct Node));

    //Initialise the node
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)  //LL is Empty
    {
        *Head = newn;
    }   
    else  //LL contains atleast one node
    {
        newn->next = *Head;
        *Head = newn
    }
}

void InsertLast(PPNODE Head , int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    //Allocate memory for node
    newn = (PNODE)malloc(sizeof(NODE));  //newn = (struct Node*)malloc(sizeof(struct Node));

    //Initialise the node
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)  //LL is Empty
    {
        *Head = newn;
    }   
    else  //LL contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE Head , int No , int Pos)
{
    int iLength = 0 , iCnt = 0;
    iLength = Count(*Head);   // Calculate lenght of LL
    
    PNODE newn = NULL;
    PNODE temp = *Head;

    //Filter
    if((iPos < 1) || (iPos > iLength + 1))   // Invalid Position
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
        newn = (PNODE)malloc(sizeof(NODE));  

        newn->data = No;
        newn->next = NULL;

        for(iCnt 1 ; iCnt < (iPos - 1) ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)   // LL is Empty
    {
        return;
    }   
    else if((*Head) ->next == NULL)    // LL contains one node
    { 
        free(*Head);
        *Head = NULL;
    } 
    else     // LL contains more than one node
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)   // LL is Empty
    {
        return;
    }   
    else if((*Head) ->next == NULL)    // LL contains one node
    { 
        free(*Head);
        *Head = NULL;
    } 
    else     // LL contains more than one node
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
}

void DeleteAtPos(PPNODE Head , int Pos)
{
    int iLength = 0;
    iLength = Count(*Head);   // Calculate lenght of LL
    
    PNODE temp = *Head;
    PNODE tempX = NULL;
    int iCnt = 0;

    //Filter
    if((iPos < 1) || (iPos > iLength))   // Invalid Position
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iLength + 1)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt 1 ; iCnt < (iPos - 1) ; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);

    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First , 111);  //InsertFirst(60,111);
    InsertFirst(&First , 101);  //InsertFirst(60,101);
    InsertFirst(&First , 51);   //InsertFirst(60,51);
    InsertFirst(&First , 21);   //InsertFirst(60,21);
    InsertFirst(&First , 11);   //InsertFirst(60,11);

    Display(First);
    
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    InsertLast(&First , 121);
    InsertLast(&First , 151);

    Display(First);

    printf("\n");
    
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}