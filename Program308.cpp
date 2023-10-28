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
        ~SinglyLL();

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

void SinglyLL :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next = NULL)
    {
        delete First;   // free(First);
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        
        First = First->next;
        delete temp;
    }
    iCount--;
}

void SinglyLL :: DeleteLast()
{
    if(First == NULL)   //Empty LL
    {
        return;
    }
    else if(First->next = NULL)     // LL conatis 1 Node
    {
        delete First;   // free(First);
        First = NULL;
    }
    else    // More than 1 Node
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

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

SinglyLL :: ~SinglyLL()      //Constructor
{
    cout<<"Inside Destructor"<<"\n";
}

void SinglyLL :: InsertAtPos(int no , int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position"<<"\n";
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos = iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp = First

        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

        iCount++
    }
}

void SinglyLL :: DeleteAtPos(int iPos)
{}

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

    obj1.InsertAtPos(55,4);
    
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of Elements are : "<<iRet<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of Elements are : "<<iRet<<"\n";

    return 0;
}