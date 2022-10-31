//Aim: Implement a program for stack that performs following operations using array.
//      PUSH, POP, PEEK, CHANGE, DISPLAY

#include <iostream>

using namespace std;
int MAXSIZE = 8;       
int stack1[8],stack2[8];     
int top1 = -1;
int top2 = -1;

// int isempty(int top) {

//    if(top == -1)
//       return 1;
//    else
//       return 0;
// }
   
// int isfull(int top) {

//    if(top == MAXSIZE)
//       return 1;
//    else
//       return 0;
// }

int peek1() {
   return stack1[top1];
}

int pop1() {
   int data;
	
   if(top1!=(-1)) {
      data = stack1[top1];
      top1 = top1 - 1;   
      return data;
   } 
   else {
      cout<<"Stack is empty.\n";
   }
}

int pop2() {
   int data;
	
   if(top2!=(-1)) {
      data = stack2[top2];
      top2 = top2 - 1;   
      return data;
   } 
   else {
      cout<<"Stack is empty.\n";
   }
}

int push1(int data) {

   if(top1!=MAXSIZE) {
      top1 = top1 + 1;   
      stack1[top1] = data;
   } else {
      cout<<"Stack is full.\n";
   }
}

int push2(int data) {

   if(top2!=MAXSIZE) {
      top2 = top2 + 1;   
      stack2[top2] = data;
   } else {
      cout<<"Stack is full.\n";
   }
}

void print()
{
   while(top1>=0) {
      int data = pop1();
      cout<<data<<endl;
   }
}

int main() {
   // push items on to the stack 
   int n,ele,index;
   cout<<"Enter Number Of Elements: ";
   cin>>n;
   cout<<"Enter Elements: ";
   for(int i=0;i<n;i++)
   {
      cin>>ele;
      push1(ele);
   }
   cout<<"Element at top of the stack:"<<peek1()<<endl;
   cout<<"Enter Index Of Element You Want To Change:"<<endl;
   cin>>index;
   for(int i=top1; i>index; i--)
   {
      int data;
      data=pop1();
      push2(data);
   }
   pop1();
   cout<<"Enter Element: "<<endl;
   cin>>ele;
   cout<<endl<<endl;
   push1(ele);
   for(int i=top2; i>=0; i--)
   {
      int data;
      data=pop2();
      push1(data);
   }
   cout<<endl;
   print();
   // cout<<"Stack full: "<<(isfull()?"true":"false")<<endl;
   // cout<<"Stack empty: "<<(isempty()?"true":"false"); 
   return 0;
}
