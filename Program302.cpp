#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class SinglyLL
{
    public:
        PNODE First;    // Char
        
        SinglyLL();     //Constructor

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();    
};

int main()
{

    return 0;
}