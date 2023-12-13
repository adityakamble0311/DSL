#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int jobno;
    Node *next;
};

class Queue
{
private:
    Node *front=nullptr;
    Node *rear=nullptr;

public:
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};

void Queue::enqueue(int x)
{
    Node *t = new Node;
    if (t == nullptr)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        t->jobno = x;
        t->next = nullptr;
        if (front == nullptr)
        {
            front = t;
            rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue()
{
    int x = -1;
    Node *p;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        p = front;
        front = front->next;
        x = p->jobno;
        delete p;
    }
    return x;
}

bool Queue::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}


void Queue::display()
{
    Node *p = front;
    while (p)
    {
        cout << p->jobno << flush;
        p = p->next;
        if (p != nullptr)
        {
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main()
{
        Queue jobs;

        int choice;
        while(choice!=4)
        {
        cout<<"______________________________________________________________"<<endl;
        cout<<"|_________________Create/Update Linked list__________________|"<<endl;
        cout<<"|                                                            |"<<endl;
        cout<<"|                1. Add job number                           |"<<endl;
        cout<<"|                2. delete job number                        |"<<endl;
        cout<<"|                3. display job queue                        |"<<endl;
        cout<<"|                4. Exit                                     |"<<endl;
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
                   cout<<"Enter the job no. : ";
                   cin>>x;

                   jobs.enqueue(x);
                   cout<<"Job no. inserted"<<endl;
                   
                }
                break;

            case 2:
                {
                    jobs.dequeue();
                    cout<<"job deletion complete"<<endl;
                }
                break;

            case 3:
                {
                    cout<<"---Displaying job queue---"<<endl;
                    jobs.display();
                    cout<<"\n";
                }
                break;

            case 4:
                {
                    choice=4;
                break;
                }
        }

        string x;
        cout<<"\nEnter any key to continue";
        cin>>x;
        system("clear");
    }
    return 0;
}