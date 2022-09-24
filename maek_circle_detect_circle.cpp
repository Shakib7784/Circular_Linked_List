#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node * Next;
    Node (int val)
    {
        value=val;
        Next=NULL;
    }
};
void insert_at_tail(Node *&head,int val)
{
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node *temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newnode;
    }
}
int length(Node *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        Node *temp=head;
        int i=1;
        while(temp->Next!=NULL)
        {
            i++;
            temp=temp->Next;
        }
        return i;
    }
}
void Display(Node *&head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {

         Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value;
            if(temp->Next!=NULL)
                cout<<"->";
            temp=temp->Next;
        }
        cout<<endl;


    }
}

int findMid(Node *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        Node *fast=head;
        Node *slow=head;
        while(fast!=NULL && fast->Next!=NULL) // fast!=NULL is handaling even number, it will give use mid value (length/2)+1. suppose we have 6 value it will give use
            // mid value 4th position's value. because in even  number mid value can be 2 value.
        {
            fast=fast->Next->Next;
            slow = slow->Next;
        }
        return slow->value;
    }
}


void make_circle(Node *&head, int pos)
{
    if(head==NULL)
    {
        cout<<"linked list is empty"<<endl;
    }
    else
    {
        Node *temp=head;
        Node *cycle_start;
        int i=1;
        while(temp->Next!=NULL)
        {
            if(i==pos)
            {
                cycle_start = temp; // making the starting position of cycle
            }
            temp=temp->Next;
            i++;
        }
        temp->Next=cycle_start; // pointing tail to starting position of cycle instead of pointing to null
    }
}
bool detect_circle(Node * &head)
{

        Node *fast=head;
        Node *slow = head;
        while(fast!=NULL && fast->Next!=NULL)
        {
            fast=fast->Next->Next;
            slow = slow->Next;
            if(fast==NULL) // in case of even number fast become null earlier that is why if fast become null earlier that means there is no circle
            {
                return false;
            }
           else if(fast->Next==slow->Next)
            {
                return true;
            }

        }
        return false;

}

void remove_circle(Node *&head)
{
    if(head==NULL)
    {
        cout<<"linked list is empty"<<endl;
    }
    else
    {
        Node *fast = head;
        Node *slow = head;
        // step 1: make fast and slow same
        do
        {
            fast=fast->Next->Next;
            slow=slow->Next;
        }while(fast!=slow);
        //step 2 : pointing fast/slow to head;
        fast = head;
        // step 3: move fast and slow by 1 until fast->next not equal to slow->next;
        while(fast->Next!=slow->Next)
        {
            fast=fast->Next;
            slow =slow->Next;
        }
        //step 4 : make slow next to null  if you put head into fast in step 2;
        slow->Next=NULL;

    }
}

int main()
{
    Node *head=NULL;
    int choice;
    cout<<"enter your choice"<<endl;
    cout<<"choice 1: insert at tail"<<endl;
    cout<<"choice 2: Find mid"<<endl;
    cout<<"choice 3: Make circle"<<endl;
    cout<<"choice 4: Detect circle"<<endl;
   cout<<"choice 5: Remove circle"<<endl;
    cin>>choice;

    while(choice!=0)
    {
        int value,result,position;
        bool res;
        switch(choice)
        {
        case 1:
            cout<<"enter value:"<<endl;
            cin>>value;
            insert_at_tail(head,value);
            break;
        case 2:
             result = findMid(head);
            if(result ==-1)
            {
                cout<<"there is no value"<<endl;
            }
            else
            {
                cout<<"Mid value is : "<<result<<endl;
            }

            break;

        case 3:
            cout<<"enter position"<<endl;
            cin>>position;
            make_circle(head,position);
            break;
        case 4:
            res = detect_circle(head);
            if(res==true)
            {
                 cout<<"there is a cycle in the list"<<endl;
            }

            else if(res==false)
            {
                cout<<"there is no cycle in the list"<<endl;
            }

            break;

        case 5:
            remove_circle(head);
            break;

        default:
            break;

        }
        cout<<"Next choice"<<endl;
        cin>>choice;
    }
    cout<<"Linked List : "<<endl;
    Display(head);

    int len = length (head);
    if(len==-1)
    {
        cout<<"Length is 0"<<endl;
    }
    else
    {
        cout<<"Length is "<<len<<endl;
    }
}


