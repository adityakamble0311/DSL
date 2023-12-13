#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

struct Node
{
    bool data;
    struct Node *next;
    struct Node *prev;
};

class BinaryLL
{
    struct Node *Head=nullptr , *Tail=nullptr , *temp;

    public:
        friend BinaryLL operator +(BinaryLL & , BinaryLL &);
        void insert(bool data);
        void insertp(bool data);  
        BinaryLL Ones();
        void Twos(BinaryLL B);
        void display();
};

void BinaryLL :: insert(bool data)
{
    struct Node* newnode;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->next=nullptr;
    newnode->prev=nullptr;
    
    if(Head==nullptr)
    {
        Head=newnode;
        Tail=newnode;

        newnode->data=data;
    }
    else
    {
        newnode->prev=Tail;
        Tail->next=newnode;
        Tail=newnode;

        newnode->data=data;
    }
}

void BinaryLL :: insertp(bool data)
{
    struct Node* newnode;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->next=nullptr;
    newnode->prev=nullptr;
    
    if(Head==nullptr)
    {
        Head=newnode;
        Tail=newnode;

        newnode->data=data;
    }
    else
    {
        newnode->next=Head;
        Head->prev=newnode;
        Head=newnode;

        newnode->data=data;
    }

}

BinaryLL BinaryLL :: Ones()
{
    BinaryLL Ones;

    temp=Head;
    while(temp!=nullptr)
    {
        if(temp->data==0)
        {
            Ones.insert(1);
        }
        else
        {
            Ones.insert(0);
        }
        temp=temp->next;
    }
    cout<<"Ones compliment ";

    return Ones;
}

void BinaryLL :: Twos(BinaryLL B)
{   
    BinaryLL Ones;
    Ones=B.Ones();

    BinaryLL Twos;

    Ones.temp=Ones.Tail;
    int carry=1;
    while(Ones.temp!=nullptr)
    {
        if(Ones.temp->data==1 && carry==1)
        {
            Twos.insertp(0);
        }
        else if (Ones.temp->data==0 && carry==1)
        {
            Twos.insertp(1);
            carry=0;
        }
        else
        {
            Twos.insertp(Ones.temp->data);
        }
        Ones.temp=Ones.temp->prev;
        
    }
    cout<<"Twos compliment ";
    Twos.display();
}

BinaryLL operator +(BinaryLL &a , BinaryLL &b)
{
    BinaryLL Add;
    int carry=0 , re;

    a.temp=a.Tail;
    b.temp=b.Tail;

    while (a.temp!=nullptr && b.temp!=nullptr)
    {
        re=carry;

        if(a.temp->data==1)
            re=re+1;
        else
            re=re+0;
        
        if(b.temp->data==1)
            re=re+1;
        else
            re=re+0;

        if(re%2==1)
            Add.insertp(1);
        else
            Add.insertp(0);

        if(re<2)
            carry=0;
        else
            carry=1;

        a.temp=a.temp->prev;
        b.temp=b.temp->prev;
    }

    if(carry!=0)
        Add.insertp(1);

    return Add;
    
}

void BinaryLL :: display()
{
    struct Node *t;
    t=Head;

    cout<<"\nBinary no. : ";
    while(t!=nullptr)
    {
        cout<<t->data;
        t=t->next;
    }
    cout<<endl;
}

int main()
{
        BinaryLL B;
        
        int choice;
        while(choice!=5)
        {
        cout<<"______________________________________________________________"<<endl;
        cout<<"|_________________Create/Update Linked list__________________|"<<endl;
        cout<<"|                                                            |"<<endl;
        cout<<"|                1. Insert binary no.                        |"<<endl;
        cout<<"|                2. Get 1's compliment                       |"<<endl;
        cout<<"|                3. Get 2's compliment                       |"<<endl;
        cout<<"|                4. Add binary numbers                       |"<<endl;
        cout<<"|                5. Exit                                     |"<<endl;
        cout<<"|____________________________________________________________|"<<endl;

        cout<<"\n _____________________________________________";
        cout<<"\n|     Enter Choice : ";
        cin>>choice;
        cout<<" ____________________________________________|"<<endl<<endl;
       
        switch(choice)
        {
            case 1:
                {
                    int x;
                    cout<<"Enter no. of bits : ";
                    cin>>x;
                    cout<<endl;

                    cout<<"Enter binary no. : ";
                    for(int i=0 ; i<x ; i++)
                    {
                        bool b;
                        cin>>b;
                        B.insert(b);
                    }
                    cout<<"\n";
                }
                break;

            case 2:
                {
                    BinaryLL One;
                    One=B.Ones();
                    One.display();
                }
                break;

            case 3:
                {
                    B.Twos(B);
                }
                break;

            case 4:
                {
                    BinaryLL a , b , add;

                    int x;
                    cout<<"Enter no. of bits : ";
                    cin>>x;
                    cout<<endl;

                    cout<<"Enter 1st binary no. : ";
                    for(int i=0 ; i<x ; i++)
                    {
                        bool y;
                        cin>>y;
                        a.insert(y);
                    }
                    cout<<"\n";

                    cout<<"Enter 2nd binary no. : ";
                    for(int i=0 ; i<x ; i++)
                    {
                        bool y;
                        cin>>y;
                        b.insert(y);
                    }
                    cout<<"\n";

                    add= a+b;
                    cout<<"Addition complete ";
                    add.display();
                }
                break;

            case 5:
                {
                    choice=5;
                }
                break;
        }
        char x;
        cout<<"\nEnter any key to continue";
        cin>>x;
        system("clear");
    }
}