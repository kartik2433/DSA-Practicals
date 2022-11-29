//Circular QUEUE

#include<iostream>
using namespace std;
#define SIZE 5

int C_QUEUE[SIZE];
int front=-1;
int rear=-1;
int X;

void C_enqueue(int data) {
	if((front == 0 && rear == SIZE-1)||(front == rear+1)) {
		cout<<"Queue Overflow. \n";
	}
	else if(front== -1 && rear == -1) {
		front++;
		rear++;
		C_QUEUE[rear] = data;
		cout<<"Element Inserted. \n";
	}
	else {
		rear=(rear+1) % SIZE;
		C_QUEUE[rear] = data;
		cout<<"Element Inserted. \n";
   }
}

int C_dequeue() {
	if(front == -1 && rear == -1) {
		cout<<"Queue Underflow. \n";
	}
	else if(front==rear) {
		X=C_QUEUE[front];
		front=-1;
		rear=-1;
		cout<<"Deleted Element: ";
		return X;
	}
	else {
		X=C_QUEUE[front];
		front = (front + 1) % SIZE;
		cout<<"Deleted Element: ";
		return X;
	}
}

void PRINT() {
	if(front>rear) {
		for(int i=front; i<=SIZE-1; i++) {
			cout<<C_QUEUE[i]<<"  ";
		}
		for(int i=0; i<=rear; i++) {
			cout<<C_QUEUE[i]<<"  ";
		}
	}
	else
		for(int i=front; i<=rear; i++) {
			cout<<C_QUEUE[i]<<"  ";
		}
	cout<<endl;
}
int main() {
	int num,value,choice;
	cout<<"How Many Numbers You Want To Store...??? \n";
	cin>>num;
	cout<<"Enter Values Now..!!! \n";
	for(int i=0; i<num; i++) {
		cin>>value;
		C_enqueue(value);
	}
	PRINT();
	while(1) {
	cout<<"1.Insert\n2.Delete\n3.Display\n0.EXIT \n";
	cin>>choice;
		switch(choice) {
			case 1:
				cout<<"Enter Element: \n";
				cin>>value;
				C_enqueue(value);
				break;
				
			case 2:
				cout<<C_dequeue()<<endl;
				break;
			case 3:
				PRINT();
				break;
			case 0:
				return 0;
			default:
				cout<<"Enter Valid Choice: \n";
		}
	}
	return 0;
}
