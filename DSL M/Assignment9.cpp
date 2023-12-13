#include<iostream>
#include<string>

using namespace std;

struct Node
{
    struct Node *next;
    char data;
};

class stack
{
    struct Node *top=nullptr;

    public:
        void push(char );
        char pop();
        void display();   
};

void stack:: push(char a)
{
    struct Node* newnode;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->next=nullptr;
    
    if(top==nullptr)
    {
        top=newnode;
        newnode->data=a;
    }
    else
    {
        newnode->next=top;
        top=newnode;

        newnode->data=a;
    }

}

char stack :: pop()
{
    struct Node *del;
    del=top;

    char d=top->data;

    top=top->next;

    delete del;

    return d;
}

void stack :: display()
{
    struct Node *t;
    t=top;

    cout<<"\n -- Displaying Stack Linked List ----------------"<<endl;
    while(t!=nullptr)
    {
        cout<<" "<<t->data;

        t=t->next;
    }
}


int main()
{
    string str1;
    cin.ignore();
    cout<<"Input string : ";
    getline(cin,str1);

    stack S1;
    int i=0;
    while(str1[i])
    {
        S1.push(str1[i]);
        i++;
    }
    S1.display();
    cout<<endl;

    bool flag=0;
    int len=str1.length();
    for(int i=len, j=0 ; i>len/2 ; i-- , j++)
    {
        char p=S1.pop();
        if(p==str1[j])
            flag=1;
        else
            flag=0;
    }

    if(flag)
        cout<<"string is palindrome"<<endl;
    else
        cout<<"string is not palindrome"<<endl;

    return 0;

}

