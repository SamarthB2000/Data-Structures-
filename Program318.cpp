#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        node *next;
        node *prev;

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
        PNODE First;
        int iCount;

        LinkedList()
        {
            First = NULL;
            iCount = 0;
        }

        virtual void InsertFirst(int iNo) = 0;
        virtual void InsertLast(int iNo) = 0;
        virtual void InsertAtPos(int iNo , int iPos) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int iPos) = 0;

        void Display()
        {
            PNODE temp = First;

            cout<<"Elements of Linked List are : "<<"\n";

            for(int iCnt = 1 ; iCnt <= iCount ; iCnt++)
            {
                cout<<"| "<<temp->data<<" |->";
                temp = temp->next;
            }
            cout<<"NULL"<<"\n";
        }
        
        int Count()
        {
            return iCount;
        }
};

class DoublyCL : public LinkedList
{
    private:
        PNODE Last;
    
    public:

        DoublyCL();
        ~DoublyCL();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL :: DoublyCL()
{
    Last = NULL;
}

DoublyCL :: ~DoublyCL()
{}

void DoublyCL :: InsertFirst(int iNo)
{
    PNODE newn = new NODE(iNo);

    /*
        PNODE newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;
    */

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }

    Last->next = First;
    First->prev = Last;
    iCount++;
}

void DoublyCL :: InsertLast(int iNo)
{    
    PNODE newn = new NODE(iNo);

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = Last->next;
    }

    Last->next = First;
    First->prev = Last;
    iCount++;
}

void DoublyCL :: InsertAtPos(int iNo , int iPos)
{}

void DoublyCL :: DeleteFirst()
{}

void DoublyCL :: DeleteLast()
{}

void DoublyCL :: DeleteAtPos(int iPos)
{}

int main()
{
    DoublyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    cout<<"Length of Linked List is : "<<obj.Count()<<"\n";
    return 0;
}