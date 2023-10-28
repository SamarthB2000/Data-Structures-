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

class Queue
{
    private:
        PNODE First;
        int iCount;

    public:
        Queue();

        void ENQUEUE(int iNo);     //InsertLast
        int DEQUEUE();             //DeleteFirst
        void Display();
        int Count();
};

Queue :: Queue()
{
    First = NULL;
    iCount = 0;
}

void Queue :: ENQUEUE(int iNo)     //InsertLast
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

int Queue :: DEQUEUE()      // DeleteFirst
{
    int Value = 0;

    if(iCount == 0)     
    {
        cout<<"Queue is Empty"<<"\n";
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

    return Value;
}             

void Queue :: Display()
{
    if(First = NULL)
    {
        cout<<"Nothing to Display as Queue is Empty"<<"\n";
        return;
    }

    cout<<"Elements of Queue are : "<<"\n";

    PNODE temp = First;

    for(int iCnt = 1 ; iCnt <= iCount ; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

int Queue :: Count()
{
    return iCount;
}


int main()
{
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    Queue obj;

    cout<<"-----------------------------------------------------"<<"\n";
    cout<<"Dynamic Implementaion of Queue"<<"\n";
    cout<<"-----------------------------------------------------"<<"\n";

    while(iChoice != 0)
    {
        cout<<"-----------------------------------------------------"<<"\n";
        cout<<"1 : ENQUEUE Element into Queue"<<"\n";
        cout<<"2 : DEQUEUE Element into Queue"<<"\n";
        cout<<"3 : Display Element from Queue"<<"\n";
        cout<<"4 : Count Element from Queue"<<"\n";
        cout<<"0 : Terminate The Appliaction"<<"\n";
        cout<<"-----------------------------------------------------"<<"\n";

        cout<<"Please Enter the Option : "<<"\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter Element at you want to ENQUEUE"<<"\n";
                cin>>iValue;
                obj.ENQUEUE(iValue);
                break;

            case 2:
                iRet = obj.DEQUEUE();
                if(iRet != -1)
                {
                    cout<<"DEQUEUE Element from Queue is "<<iRet<<"\n";
                }
                break;

            case 3:
                obj.Display();
                break;

            case 4:
                iRet = obj.Count();
                cout<<"Number of Elements are : "<<iRet<<"\n";
                break;

            case 0:
                cout<<"Thank You for using App"<<"\n";
                break;
            
            default:
                cout<<"Please Enter Valid Option"<<"\n";
                break;
        }//End of Switch
    }//End of While

    return 0;
}