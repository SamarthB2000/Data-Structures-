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

void SinglyLL :: InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;        // newn = (PNODE)malloc(Sizeof(NODE))

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)   // LL is Empty
    {
        First = newn;
    }
    else        // LL Conatins at least 1 Node
    {
        newn->next = First;
        First = newn;
    }

    iCount++;
}

void SinglyLL :: InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;        // newn = (PNODE)malloc(Sizeof(NODE))

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)   // LL is Empty
    {
        First = newn;
    }
    else        // LL Conatins at least 1 Node
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

void SinglyLL :: InsertAtPos(int no , int iPos)
{}

void SinglyLL :: DeleteFirst()
{}

void SinglyLL :: DeleteLast()
{}

void SinglyLL :: DeleteAtPos(int iPos)
{}

void SinglyLL :: Display()
{
    PNODE temp = First;

    cout<<"Elements of Linked List are : "<<"\n";

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int SinglyLL :: Count()
{
    return iCount;
}

SinglyLL :: SinglyLL()      //Constructor
{
    cout<<"Inside Constructor"<<"\n";

    First = NULL;
    iCount = 0;
}

int main()
{
    int iRet = 0;

    SinglyLL obj1;
    SinglyLL obj2;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of Elements are : "<<iRet<<"\n";

    obj2.InsertFirst(30);
    obj2.InsertFirst(20);
    obj2.InsertFirst(10);
   
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of Elements are : "<<iRet<<"\n";

    return 0;
}