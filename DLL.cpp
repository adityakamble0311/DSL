#include<iostream>
#include<string>
using namespace std;
class binary;
class node{

	node * prev;
	node * next;
	bool n;

	public:
	node():prev(nullptr),next(nullptr),n(false){}
	node(bool b):n(b),prev(nullptr),next(nullptr){}

	friend class binary;



};
class binary{

	node * start;
	public:

		binary():start(nullptr){}

		void generateBinary(int no);
		void displayBinary();
		void onesComplement();
		void twosComplement();

		binary operator+(const binary& n1);

		bool addBitAtBegin(bool val){
			node * nodee = new node(val);

			if(start==nullptr){

				start = nodee;
			}
			else{

				nodee->next=start;
				start->prev=nodee;
				start=nodee;
			}

			return true;
		}
};
void binary :: generateBinary(int no){

	bool rem;
	node * p;
	rem = no % 2;
	start = new node(rem);
	no = no / 2;

	while(no!=0){

		rem = no % 2;
		no = no / 2;

		p = new node(rem);
		p->next=start;
		start->prev=p;
		start = p ;

	}
}

void binary::displayBinary(){

	node * t = start;
	while(t!=NULL){
		cout<<t->n;
		t = t->next;
	}
}
binary binary::operator+(const binary& n1){
	binary sum;
	node * a = start;
	node * b = n1.start;
	bool carry = false;

	while(a->next!=NULL){
		a = a->next;
	}
	while(b->next!=NULL){
		b = b->next;
	}

	while(a!= NULL && b!=NULL){

		sum.addBitAtBegin((a->n)^(b->n)^carry);
		carry = ((a->n && b->n )||(a->n && carry) || (b->n && carry));

		a = a->prev;
		b = b->prev;
	}

	while(a!=NULL){
		sum.addBitAtBegin(a->n^carry);
			a = a->prev;
	}
	while(b!=NULL){
		sum.addBitAtBegin(b->n^carry);
		b = b -> prev;
	}
	sum.addBitAtBegin(carry);
	return sum;
}

void binary::onesComplement(){
	node * t = start;
	while(t!=NULL){
		t->n = !t->n;
		t = t->next;
	}
}
void binary::twosComplement(){

	onesComplement();
	node * t = start;
	bool carry = 1;
	while(t->next!=NULL){
		t = t->next;
	}
	while(t!=nullptr){
		if(t->n == 1 && carry == 1){
			t->n = 0;
			carry = 1;

		}
		else if(t->n == 0 && carry == 1){
			t->n = 1;
			carry = 0;
		}
		else if (carry==0)
		break;
		t = t->prev;
	}
}
int main(){

	int num1,num2,ch;
	binary n1,n2,n3;

	do{
		cout<<"\n 1.Generate Binary \n 2.One Complement \n 3.Two Complement \n 4.Addtion Binary \n 5.Exit \n";
		cout<<"Enter The Chooice : ";
		cin>>ch;


		switch(ch){

			case 1:
			cout << "Enter Number of bits for the first number : ";
			cin>>num1;
			cout<<"Binary Number :";
			n1.generateBinary(num1);
			n1.displayBinary();
			break;
			case 2:
			cout<<"Enter The Decimal Number : ";
			cin>>num1;
			cout<<"Binary Number : ";
			n1.generateBinary(num1);
			n1.displayBinary();
			cout<<"\nOne's Complement : ";
			n1.onesComplement();
			n1.displayBinary();
			break;

			case 3:
			cout<<"\nEnter The Decimal Number For First Number : ";
			cin>>num1;
			n1.generateBinary(num1);
			cout<<"\nBinary Number : ";
			n1.displayBinary();

			cout<<"\nTwo's Complement : ";
			n1.twosComplement();
			n1.displayBinary();

			break;

			case 4:
			cout<<"\nEnter The First Number To addition : ";
			cin>>num1;

			cout<<"\nEnter The Second Number To Addtion : ";
			cin>>num2;

			n1.generateBinary(num1);
			n2.generateBinary(num2);

			cout<<"\nAdditons : ";
			n1.displayBinary();
			cout<<" + ";
			n2.displayBinary();
			cout<<" = ";
			n3 = n1 + n2 ;
			n3.displayBinary();
			break;

		}

	}while(ch!=5);

	return 0;
}
