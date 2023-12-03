#include<iostream>
using namespace std;

struct node {
    node* next;
    int jobNumber;
};

void addJob(node*& head, int jobNumber) {
    node* newnode = new node;
    newnode->jobNumber = jobNumber;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    cout << "JOB : " << jobNumber << " Added in Queue" << endl;
}

void display(node* head) {
    while (head != NULL) {
        cout << "|\t" << head->jobNumber << "\t|" << endl;
        head = head->next;
    }
    cout << "|_______________|" << endl;
}

int main() {
    node* head = NULL;
    int choice, jobNumber;

    do {
        cout << "1.Insert Job" << endl;
        cout << "2.Delete Job" << endl;
        cout << "3.Display Job" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter a choice :" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a job :" << endl;
                cin >> jobNumber;
                addJob(head, jobNumber);
                break;

            case 2:
               
                cout << "Enter a delete job :" << endl;
                cin >> jobNumber;
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "Exit Program !" << endl;
                break;
        }

    } while (choice != 4);

  
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

