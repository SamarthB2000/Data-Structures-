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
        int POP();             //DeleteLast
        void Display();
        int Count();
};

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

int Stack :: POP()      // DeleteLast
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
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

    return iValue;
}             

void Stack :: Display()
{
    if(First = NULL)
    {
        cout<<"Nothing to Display as Stack is Empty"<<"\n";
        return;
    }

    cout<<"Elements of Stack are : "<<"\n";

    PNODE temp = First;

    for(int iCnt = 1 ; iCnt <= iCount ; iCnt++)
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
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    Stack obj;

    cout<<"-----------------------------------------------------"<<"\n";
    cout<<"Dynamic Implementaion of Stack"<<"\n";
    cout<<"-----------------------------------------------------"<<"\n";

    while(iChoice != 0)
    {
        cout<<"-----------------------------------------------------"<<"\n";
        cout<<"1 : PUSH Element into Stack"<<"\n";
        cout<<"2 : POP Element into Stack"<<"\n";
        cout<<"3 : Display Element from Satck"<<"\n";
        cout<<"4 : Count Element from Stack"<<"\n";
        cout<<"0 : Terminate The Appliaction"<<"\n";
        cout<<"-----------------------------------------------------"<<"\n";

        cout<<"Please Enter the Option : "<<"\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter Element at you want to PUSH"<<"\n";
                cin>>iValue;
                obj.PUSH(iValue);
                break;

            case 2:
                iRet = obj.POP();
                if(iRet != -1)
                {
                    cout<<"POP Element from Stack is "<<iRet<<"\n";
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