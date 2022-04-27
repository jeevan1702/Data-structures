#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Node
{
public:
    int info; 
    Node *next; 
};

class List : public Node
{
 
    Node *first , *last;

public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void create();
    void insert(); 
    void delet();
    void display();
    
};
void List :: create()
{
    Node *temp;
    temp = new Node; 
    int n;
    cout<<"\n Enter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=temp;
    } 
    else                                                               
    {
        last->next=temp;
        last=temp;
    }
}
void List :: insert()
{
    Node *prev,*cur;
    prev=NULL;   
    cur=first;
    int count=1,pos,ch,n;
    Node *temp;
    temp = new Node;
    cout<<"\n Enter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\n INSERT AS \n 1:FIRSTNODE \n 2:LASTNODE \n 3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\n Enter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\n Not Able to Insert";
        break;
 
    }
}
void List::delet()
{
Node *prev,*cur=first;
prev=NULL;
int count=1,pos,ch;
    cout<<"\n DELETE\n 1:FIRSTNODE \n 2:LASTNODE \n 3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\n Deleted Element is "<<first->info;
            first=first->next;
        }
        else
            cout<<"\n Not Able to Delete";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\n Deleted Element is: "<<cur->info;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\n Not Able to Delete";
        break;
    case 3:
        cout<<"\n Enter the Position of Deletion:";
        cin>>pos;
        while(count!=pos)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\n Deleted Element is: "<<cur->info;
            prev->next = cur->next;
        }
        else
            cout<<"\n Not Able to Delete";
        break;
    }
}
void List :: display()
{
Node *temp;
temp = first;
    if(temp==NULL)
    {
        cout<<"\n List is Empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main()
{
    List l;
    int ch;
    while(1)
    {
        cout<<"\n**** MENU ****";
        cout<<"\n1:CREATE\n2:INSERT\n3:DELETE\n4:DISPLAY\n5:EXIT\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.display();
            break;
        
        case 5:cout<<"exit";
              break;
        case 6: cout<<"invalid Option"<<"\n";
            
        }
    }
    return 0;
}

