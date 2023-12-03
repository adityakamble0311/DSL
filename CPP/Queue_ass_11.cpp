#include<iostream>
using namespace std;
struct node{
	node * next;
	int jobNumber;
	
};

void addjob(node* &head, int jobNumber){
	node* newnode = new node;
	newnode->jobNumber = jobNumber;
	newnode->next=NULL;
	
	if(head==NULL){
		
		head = newnode;
		
	}else{
		node * temp = head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		
		temp->next=newnode;
		
	}
	
	cout<<"Job - "<<jobNumber<<" Added to the Queue\n";
}

void deletejob(node* & head, int jobNumber){
	
	if(head==NULL){
		cout<<"Queue is empty";
		return;
	}
	
	if(head->jobNumber == jobNumber){
		node * temp = head;
		head = head->next;
		delete temp;
		cout<<"Job - "<<jobNumber<<" Deleted a job\n";
		return;
	}
	node* temp = head;
    node* prev = NULL;
    while (temp != NULL && temp->jobNumber != jobNumber) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Job " << jobNumber << " not found in the queue." << endl;
    } else {
        prev->next = temp->next;
        delete temp;
        cout << "Job " << jobNumber << " deleted from the queue." << endl;
    }
}



void display(node * head){
	while(head != NULL){
		cout<<"|\t"<<head->jobNumber<<"\t|"<<endl;
		head = head->next;
	}
	cout<<"-----------------";
	cout<<endl;
}

int main(){
	
	node * head = NULL;
	int choice , jobNumber;
	
	do{
		cout<<"1.Add New Job "<<endl;
		cout<<"2.Delete Job"<<endl;
		cout<<"3.Display Job"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter a choice : ";
		cin>>choice;
		
		
		switch(choice){
			
			
			case 1:
				cout<<"Enter job number to add : ";
				cin>>jobNumber;
				addjob(head,jobNumber);
				
				break;
				
			case 2:
				cout<<"Enter job number to delete : ";
				cin>>jobNumber;
				deletejob(head,jobNumber);
				break;
				
				
			case 3:
				cout<<"-------Display Job-------- \n\n";
			
				display(head);
				cout<<" _______________\n";
				
				break;
				
			case 4:
				cout<<"Exit Program !";
				
				break;
			}
		}while(choice!=4);
		
		while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
		
		return 0;
		
	}
	
	
