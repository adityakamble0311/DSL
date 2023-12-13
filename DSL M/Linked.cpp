#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    struct Node* next;
    int roll_no;
    char name[50];
};

class linked_list
{
    struct Node *Head=nullptr ,*temp=nullptr;

    public:
        friend linked_list operator +(linked_list & , linked_list &);
        void insertp();
        void insertm(int index);
        void inserts();
        void removep();
        void removes();
        void removem(int index);
        void display();
        int length();
        void conc(linked_list a , linked_list b , linked_list &c);
};

linked_list operator +(linked_list &a , linked_list &b)
{
    linked_list c;
    c.Head=a.Head;
    c.temp=b.Head;
    a.temp->next=b.Head;

    return c;
}


void linked_list :: insertm(int index)
{
    struct Node* newnode , *t;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->next=nullptr;

    t=Head;
    for(int i=1 ; i<index ; i++)
    {   
            t=t->next;
    }

    newnode->next=t->next;
    t->next=newnode;

    cout<<"Enter the Roll No. : ";
    cin>>newnode->roll_no;

    cout<<"Enter the Name : ";
    cin>>newnode->name;
    cout<<"\n";
}


void linked_list :: insertp()
{
    struct Node* newnode;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->next=nullptr;
    
    if(Head==nullptr)
    {
        Head=newnode;
        temp=newnode;

        cout<<"Enter the Roll No. of President : ";
        cin>>newnode->roll_no;

        cout<<"Enter the Name of President : ";
        cin>>newnode->name;
        cout<<"\n";
    }
    else
    {
        newnode->next=Head;
        Head=newnode;

        cout<<"Enter the Roll No. of President : ";
        cin>>newnode->roll_no;

        cout<<"Enter the Name of Precident : ";
        cin>>newnode->name;
        cout<<"\n";
    }

}

void linked_list :: inserts()
{
    struct Node* newnode;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->next=nullptr;
    
    if(Head==nullptr)
    {
        Head=newnode;
        temp=newnode;

        cout<<"Enter the Roll No. of Secratary : ";
        cin>>newnode->roll_no;

        cout<<"Enter the Name of Secratary : ";
        cin>>newnode->name;
        cout<<"\n";
    }
    else
    {
        temp->next=newnode;
        temp=newnode;

        cout<<"Enter the Roll No. of Secratory : ";
        cin>>newnode->roll_no;

        cout<<"Enter the Name of Secratory: ";
        cin>>newnode->name;
        cout<<"\n";
    }

}

void linked_list :: removep()
{
    struct Node *del;
    del=Head;
    Head=Head->next;

    delete del;
}

void linked_list :: removes()
{
    struct Node *t;
    t=Head;

    while(t->next->next!=nullptr)
    {
        t=t->next;
    }

    delete temp;
    temp=t;
    temp->next=nullptr;
}

void linked_list :: removem(int index)
{
    struct Node *t;
    t=Head;

    for(int i=1 ; i<index ; i++)
    {
        t=t->next;
    }

    struct Node *del;
    del=t->next;

    t->next=del->next;
    delete del;
}


void linked_list :: display()
{
    struct Node *t;
    t=Head;

    cout<<"\n -- Displaying Linked List ----------------"<<endl;
    while(t!=nullptr)
    {
        cout<<"    Roll No. : "<<t->roll_no<<endl;
        cout<<"    Name     : "<<t->name<<endl;
        cout<<"\n";

        t=t->next;
    }
}

int linked_list :: length()
{
    struct Node *t;
    t=Head;
    int count=1;

    while(t->next!=nullptr)
    {
        t=t->next;
        ++count;
    } 
    cout<<"Length of linked list : "<<count<<endl;
    return count;
}

void menu()
{
        cout<<"______________________________________________________________"<<endl;
        cout<<"|_________________Linked List System Menu____________________|"<<endl;
        cout<<"|                                                            |"<<endl;
        cout<<"|                1. Create/Update 1st Linked list            |"<<endl;
        cout<<"|                2. Create/Update 2nd Linked list            |"<<endl;
        cout<<"|                3. Display Linked list                      |"<<endl;
        cout<<"|                4. Add two Linked list                      |"<<endl;
        cout<<"|                5. Count length of lInked list              |"<<endl;
        cout<<"|                6. Create/Update Concanated Linked list     |"<<endl;
        cout<<"|                7. Exit                                     |"<<endl;
        cout<<"|____________________________________________________________|"<<endl;
}

void option1(linked_list &l)
{
        cout<<"______________________________________________________________"<<endl;
        cout<<"|_________________Create/Update Linked list______________|"<<endl;
        cout<<"|                                                            |"<<endl;
        cout<<"|                1. insert president                         |"<<endl;
        cout<<"|                2. insert member                            |"<<endl;
        cout<<"|                3. insert secratory                         |"<<endl;
        cout<<"|                4. delete president deteils                 |"<<endl;
        cout<<"|                5. delete member details                    |"<<endl;
        cout<<"|                6. delete secratory deteils                 |"<<endl;
        cout<<"|                7. Exit                                     |"<<endl;
        cout<<"|____________________________________________________________|"<<endl;

        int choice;
        while(choice!=7)
        {
        cout<<"\n _____________________________________________";
        cout<<"\n|     Enter Choice : ";
        cin>>choice;
        cout<<" ____________________________________________|"<<endl<<endl;
       
        switch(choice)
        {
            case 1:
                {
                    l.insertp();
                }
                break;

            case 2:
                {
                    int index , len;
                    len=l.length();
                    if(index<len)
                    {
                        cout<<"Enter the index : ";
                        cin>>index;
                        l.insertm(index);
                    }
                    else
                        cout<<"Invalid index"<<endl;
                }
                break;

            case 3:
                {
                    l.inserts();
                }
                break;

            case 4:
                {
                    l.removep();
                }
                break;

            case 5:
                {
                    int index, len;
                    len=l.length();
                    if(index<len)
                    {
                        cout<<"Enter the index : ";
                        cin>>index;
                        l.removem(index);
                    }
                    else
                        cout<<"Invalid index"<<endl;
                }
                break;

             case 6:
                {
                    l.removes();
                }
                break;

            case 7:
                {
                    choice=7;
                }
                break;
        }
    }
}



int main()
{
        linked_list l[3];

        

        int choice;
        while(choice!=7)
        {
        menu();
        cout<<"\n _____________________________________________";
        cout<<"\n|     Enter Choice : ";
        cin>>choice;
        cout<<" ____________________________________________|"<<endl<<endl;
       
        switch(choice)
        {
            case 1:
                {
                    option1(l[0]);
                }
                break;

            case 2:
                {
                    option1(l[1]);
                }
                break;

            case 3:
                {
                    int x;
                    cout<<"Enter the no. of linked list you want to display : ";
                    cin>>x;

                    if(x==1)
                    {
                        l[0].display();
                    }
                    else if (x==2)
                    {
                        l[1].display();
                    }
                    else if(x==3)
                    {
                        l[2].display();
                    }
                    
                }
                break;

            case 4:
                {
                    l[2] = l[0] + l[1];
                    cout<<"Linked list concatenated"<<endl;
                    l[2].display();
                }
                break;

            case 5:
                {
                    int x;
                    cout<<"Enter the no. of linked list you want length of : ";
                    cin>>x;

                    if(x==1)
                    {
                        l[0].length();
                    }
                    else if (x==2)
                    {
                        l[1].length();
                    }
                    else if(x==3)
                    {
                        l[2].length();
                    }
                    
                }
                break;
            case 6:
                {
                    option1(l[2]);   
                }
                break;

            case 7:
                {
                    choice=7;
                }
                break;
        }
        }
}