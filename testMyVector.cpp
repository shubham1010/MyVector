#include <iostream>
#include"myVector.h"
using namespace std;

void doOperations(void);
void pushNElements(MyVector<int> &v1,int totEle);

int main() {
	doOperations();
	cout << endl;
}

void doOperations(void) {
	unsigned int ch,n;
	MyVector<int> v1;

	while(1) {
		cout << "____________________________________________________________" << endl;
		cout << "1: Push From Back\n2: Reserve\n3: Size\n4: Capacity\n5: isEmpty\n6: Display\n7:Pop From Back\n8:Exit"<<endl;
		cout << "____________________________________________________________" << endl;
		cout << "Enter your choice: ";
		cin >> ch;

		if (ch==8)
			break;
		switch(ch){
			case 1:
				cout << "How many elements you want to insert?: ";
				cin >> n;

				pushNElements(v1,n);
				break;
			case 2:
				cout << "Enter how many bytes you want to reserve?: ";
				cin >> n;
				v1.reserve(n);
				break;
			case 3:
				cout << "Size of Vector: "<<v1.size()<<endl;
				break;
			case 4:
				cout << "Capacity of vector: "<<v1.capacity()<<endl;
				break;
			case 5:
				if(v1.empty())
					cout << "Vector is empty..!";
				else
					cout << "Vector is not empty..!";
				cout << endl;
				break;

			case 6:
				v1.display();
				break;
			case 7:
				v1.pop_back();
		}
		cout << endl;
	}
}

void pushNElements(MyVector<int> &v1,int totEle) {
	int e;
	cout << "Enter " << totEle << " elements: \n";
	for(int i=0 ; i<totEle ; i++) {
		cout << "Enter " << i+1 << "th elements: ";
		cin >> e;
		v1.push_back(e);
	}
}
