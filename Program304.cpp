#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

class SinglyLL
{
    private:
        PNODE First;    // Char
        int iCount;     // Char
    
    public:
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

// Implementation of all Behaviours

int main()
{
    SinglyLL obj1();

    return 0;
}