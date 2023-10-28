#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        node *next;

        node(int Value)
        {
            data = Value;
            next = NULL;
        }
    
}NODE , *PNODE;

class Stack
{
    private:
        PNODE First;
        int iCount;

    public:
        Stack();

        void PUSH(int iNo);     //InsertLast
        int POP();             //DeleteFirst
        void Display();
        int Count();
}

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

void Stack :: PUSH(int iNo)     //InsertLast
{
    PNODE newn = new NODE(iNo);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}     

int Stack :: POP()      // DeleteFirst
{
    int Value = 0;

    if(iCount == 0)     
    {
        cout<<"Stack is Empty"<<"\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        Value = First->data;

        PNODE temp = First;

        First = First->next;
        delete temp;
    }

    iCount--;
}             

void Stack :: Display()
{
    cout<<"Elements of Stack are : "<<"\n";

    PNODE temp = First;

    for(int iCnt = 1 ; iCnt <= iCount : iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

int Stack :: Count()
{
    return iCount;
}


int main()
{
    return 0;
}