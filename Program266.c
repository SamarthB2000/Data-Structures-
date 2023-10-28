#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct node * next;
}NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));  

    newn->data = No;
    newn->next = NULL;       

    if(*Head == NULL)        
    {
        *Head = newn;        
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }

}

void InsertLast(PPNODE Head , int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));  

    PNODE temp = *Head;

    newn->data = No;
    newn->next = NULL;       

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
    }

}

void Display(PNODE Head)
{
    printf("Elements of Linked List are : \n");

    while(Head != NULL)
    {
        printf("| %d | ->",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
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

void DeleteFirst(PPNODE Head)
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
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head , int No , int iPos)
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

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertLast(&First , 11);
    InsertLast(&First , 21);
    InsertLast(&First , 51);
    InsertLast(&First , 101);
    
    Display(First);

    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    printf("\n");

    InsertFirst(&First , 10);
    InsertFirst(&First , 20);

    Display(First);

    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    InsertAtPos(&First , 25 , 5)

    DeleteFirst(&First);

    printf("\n");

    Display(First);

    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&First);

    printf("\n");

    Display(First);

    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&First);

    printf("\n");

    Display(First);

    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}