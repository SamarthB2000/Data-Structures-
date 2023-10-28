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
    //Logic
}

int Count(PNODE Head)
{
    //Logic
    return 0;
}

void InsertFirst(PPNODE Head , int No)
{
    //Logic
}

void InsertLast(PPNODE Head , int No)
{
    //Logic
}

void InsertAtPos(PPNODE Head , int No , int Pos)
{
    //Logic
}

void DeleteFirst(PPNODE Head)
{
    //Logic
}

void DeleteLast(PPNODE Head)
{
    //Logic
}

void DeleteAtPos(PPNODE Head , int Pos)
{
    //Logic
}

int main()
{
    PNODE First = NULL;

    return 0;
}