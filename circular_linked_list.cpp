#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value=val;
        Next =NULL;
    }
};
void insert_node_tail(Node *&head, int val)
{
    Node *newnode= new Node(val);
    if(head==NULL)
    {
        head=newnode;
        newnode->Next=head;
    }
    else
    {
        Node *temp = head;
        while(temp->Next!=head)
        {
            temp=temp->Next;
        }
        temp->Next=newnode;
        newnode->Next=head;
    }
}
void insert_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if(head==NULL)
    {
        head=newnode;
        newnode->Next=head;
    }
    else
    {
        Node *temp = head;
        while(temp->Next!=head) // temp is carrying first head value;
        {
            temp=temp->Next;
        }

        newnode->Next=head;
         head=newnode;
         temp->Next =newnode;

    }
}
void Display(Node *&head)
{
    if(head==NULL)
    {
        cout<<"There is no value"<<endl;
    }
    else
    {
        Node * temp=head;
        do
        {
            cout<<temp->value<<endl;
            temp=temp->Next;
        }while (temp!=head);
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
        int i=1;
        Node *temp = head;
        while(temp->Next!=head)
        {
            i++;
            temp=temp->Next;
        }
        return i;
    }
}

//insert node by position
void insert_node_by_position(Node *&head, int pos, int val)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        int len = length(head);
        if(pos<0 || pos>len)// question  says position starts from 0
        {
            cout<<"Invalid Position"<<endl;
        }
        else if(pos == 0)
        {
            insert_head(head,val);
        }
        else
        {
            Node *temp=head;
            int i=0;
            while(i<pos-1)
            {
                temp=temp->Next;
                i++;
            }
            Node *newnode = new Node(val);
            Node*nextnode = temp->Next;
            temp->Next = newnode;
            newnode->Next = nextnode;
        }
    }
}
void delete_node_from_head(Node*&head)
{
    Node *temp = head;

    if(temp!=NULL)
    {
        Node *deltemp =temp;


       while(temp->Next!=head)
       {
           temp=temp->Next;
       }

       temp->Next=deltemp->Next;
       head=deltemp->Next;
       /*if(head==temp->Next)
        head==NULL;*/

        delete deltemp;
    }
     else
    {
         cout<<"Linked list is empty"<<endl;
    }
}
void delete_from_tail(Node *&head)
{
    Node *temp=head;


    if(temp!=NULL && temp->Next!=head)
    {

        while(temp->Next->Next!=head)
        {
            temp=temp->Next;
        }
        Node *delnode = temp->Next;
        temp->Next=delnode->Next;
        delete delnode;
    }
   else
    {
        if(temp==NULL)
        {
              cout<<"Linked list is empty"<<endl;
        }
        else
        {
            delete_from_tail(head);
        }


    }
}
void delete_node_by_position(Node *&head, int pos)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        int len = length(head);
        if(pos<0 || pos>len)// question  says position starts from 0
        {
            cout<<"Invalid Position"<<endl;
        }
        else if(pos == 0)
        {
            delete_node_from_head(head);
        }
        else
        {
            Node *temp=head;
            int i=0;
            while(i<pos-1)
            {
                temp=temp->Next;
                i++;
            }
            Node * tobedeleted = temp->Next;
            Node * store = temp->Next->Next;
            temp->Next=store;
            delete(tobedeleted);
        }
    }
}
void move_tail(Node *&head)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {
        Node *temp = head;
        Node * second_head = head;
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        head=temp->Next;
        temp->Next = NULL;
        head->Next=second_head;
    }
}
int main()
{
    Node *head=NULL;
    cout<<"enter your choice"<<endl;
    cout<<"choice 0: exist"<<endl;
    cout<<"choice 1: insert value at tail"<<endl;
    cout<<"choice 2: insert value at head"<<endl;
    cout<<"choice 3: insert value at specific position"<<endl;
    cout<<"choice 4: Delete node from head"<<endl;
    cout<<"choice 5: Delete node from a specific position"<<endl;
    cout<<"choice 6: move tail to head "<<endl;
     cout<<"choice 7: Delete node from tail"<<endl;



    int choice;
    cin>>choice;
    while(choice!=0)
    {
        int value;
        int position;
        switch(choice)
        {
        case 1:
            cout<<"enter value"<<endl;
            cin>>value;
            insert_node_tail(head,value);
            break;

        case 2:
            cout<<"enter value"<<endl;
            cin>>value;
            insert_head(head,value);
            break;
        case 3:
            cout<<"enter position"<<endl;
            cin>>position;
            cout<<"enter value"<<endl;
            cin>>value;
            insert_node_by_position(head,position,value);
            break;

        case 4:
            delete_node_from_head(head);
            cout<<"Linked list after deletion : "<<endl;
            Display(head);
            break;

        case 5:
            cout<<"enter position"<<endl;
            cin>>position;
            delete_node_by_position(head,position);
            cout<<"Linked list after dletion"<<endl;
            Display(head);
            break;

            case 6:
            move_tail(head);
            cout<<"Linked list now: "<<endl;
            Display(head);
            break;

            case 7:
                delete_from_tail(head);
                cout<<"Linked list now: "<<endl;
            Display(head);
            break;

        default:
            break;

        }


        cout<<"enter next choice"<<endl;
        cin>>choice;
    }

    cout<<"Linked list"<<endl;
    Display(head);
    int len = length(head);
    if(len==-1)
    {
        cout<<"Length is 0"<<endl;
    }
    else
    {
        cout<<"length of linked list is "<<len<<endl;
    }
}
