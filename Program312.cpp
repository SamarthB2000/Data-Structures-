#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE , *PNODE;

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
        return;
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
        PNODE temp = First;

        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos = iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempX = NULL;

        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }
}

int main()
{
    SinglyLL obj;

    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;

    cout<<"Marvellous LinkedList Appliaction"<<"\n";

    while(1)
    {
        cout<<"------------------------------------------------"<<"\n";
        cout<<"Please Enter Your Choice : "<<"\n";
        cout<<"1 : Insert Node at First Position"<<"\n";
        cout<<"2 : Insert Node at Last Position"<<"\n";
        cout<<"3 : Insert Node at Given Position"<<"\n";
        cout<<"4 : Delete Node From First Node"<<"\n";
        cout<<"5 : Delete Node From Last Node"<<"\n";
        cout<<"6 : Delete Node From Given Node"<<"\n";
        cout<<"7 : Display Elements of Linked List"<<"\n";
        cout<<"8 : Count Number of Nodes of Linked List"<<"\n";
        cout<<"9 : Terminate the Application"<<"\n";

        cin>>iChoice;

        cout<<"------------------------------------------------"<<"\n";

        switch(iChoice)
        {
            case 1:
                cout<<"Enter Value that you want to insert : "<<"\n";
                cin>>iValue;
                obj.InsertFirst();
                break;
        
            case 2:
                cout<<"Enter Value that you want to insert : "<<"\n";
                cin>>iValue;
                obj.InsertLast();
                break;

            case 3:
                cout<<"Enter Value that you want to insert : "<<"\n";
                cin>>iValue;

                cout<<"Enter the Position : "<<"\n";
                cin>>iPosition;

                obj.InsertAtPos(iValue , iPosition);
                break;

            case 4:
                obj.DeleteFirst();
                break;
            
            case 5:
                obj.DeleteLast();
                break;

            case 6:
                cout<<"Enter the Position :"<<"\n";
                cin>>iPosition;

                obj.DeleteAtPos(iPosition);
                break;

            case 7:
                obj.Display();
                break;

            case 8:
                cout<<"Number of Elements are : "<<obj.Count()<<"\n";
                break;
            
            case 9 :
                cout<<"Thank You for using the Application"<<"\n";
                return 0;

            default:
                cout<<"Invalid Choice"<<"\n";
                break;

        }
    }

    return 0;
}