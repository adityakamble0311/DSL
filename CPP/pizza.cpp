#include <iostream>
#include <queue>
using namespace std;

class PizzaParlor {
public:
    queue<string> orders;

    void acceptOrder(const string& vegname) {
        orders.push(vegname);
        cout << "Order for " << vegname << " accepted.\n";
    }

    void deliverOrder(int numOrders) {
        if (orders.empty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Delivering " << numOrders << " orders:\n";
        for (int i = 0; i < numOrders && !orders.empty(); ++i) {
            cout << " - " << orders.front() << "\n";
            orders.pop();
        }

        cout << "Payment due: $" << numOrders * 100 << "\n";
    }

    void displayPendingOrders() const {
        if (orders.empty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending orders:\n";
        queue<string> tempOrders = orders;
        while (!tempOrders.empty()) {
            cout << " - " << tempOrders.front() << "\n";
            tempOrders.pop();
        }
    }
};

int main() {
    PizzaParlor pizzaParlor;
    int choice;

    do {
        cout << "\n*** Welcome To Pizza Parlor ***\n";
        cout << "1. Accept order\n2. Deliver orders\n3. Display pending orders\n4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        string vegname;
        cin >> choice;

        switch (choice) {
            case 1: {
                int ch;
                do{
                	cout<<"1.Veg Pizza"<<endl;
                	cout<<"2.Non-Veg Pizza"<<endl;
                	cout<<"3.Exit"<<endl;
                	cout<<"Enter a choice :";
                	cin>>ch;
                	
                	switch(ch){
                		
                		case 1:
                			
                			cout<<"\n1.Panner\n 2.Capsicum \n 3.Golden Corn \n";
                			cin>>vegname;
                			break;
                		case 2:
                			cout<<"\n1.Chicken \n 2. Tandoor Chicken";
                			break;
					}
				}while(ch!=3);
                pizzaParlor.acceptOrder(vegname);
                break;
            }

            case 2: {
                cout << "How many orders to deliver: ";
                int numOrders;
                cin >> numOrders;
                pizzaParlor.deliverOrder(numOrders);
                break;
            }

            case 3:
                pizzaParlor.displayPendingOrders();
                break;

            case 4:
                cout << "Exiting the Pizza Parlor. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
