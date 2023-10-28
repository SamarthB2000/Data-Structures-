#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        struct node *next;
        struct node *prev;

        node()
        {
            data = 0;
            next = NULL;
            prev = NULL;
        }
        
        node(int Value)
        {
            data = Value;
            next = NULL;
            prev = NULL;
        }

}NODE , *PNODE;

class LinkedList
{
    public:
        virtual void InsertFirst(int iNo) = 0;
        virtual void InsertLast(int iNo) = 0;
        virtual void InsertAtPos(int iNo , int iPos) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int iPos) = 0;

        virtual void Display() = 0;
        virtual int Count() = 0;
};

class DoublyCL : public LinkedList
{
    private:
        PNODE First;
        PNODE Last;
        int iCount;

    public:

        DoublyCL();
        ~DoublyCL();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

DoublyCL :: DoublyCL()
{}

DoublyCL :: ~DoublyCL()
{}

void DoublyCL :: InsertFirst(int iNo)
{}

void DoublyCL :: InsertLast(int iNo)
{}

void DoublyCL :: InsertAtPos(int iNo , int iPos)
{}

void DoublyCL :: DeleteFirst()
{}

void DoublyCL :: DeleteLast()
{}

void DoublyCL :: DeleteAtPos(int iPos)
{}

void DoublyCL :: Display()
{}

int DoublyCL :: Count()
{
    return 0;
}

int main()
{

    return 0;
}