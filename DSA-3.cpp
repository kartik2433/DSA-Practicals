//Aim: Implement a program for stack that performs following operations using array.
//      PUSH, POP, PEEK, CHANGE, DISPLAY

#include <iostream>
#include <iomanip>
using namespace std;
int MAXSIZE = 8;       
int stack1[8],stack2[8];     
int top1 = -1;
int top2 = -1;

int isEmpty(int top) {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isFull(int top) {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack1[top1];
}

int pop(int stack[],int &top) {
   int data;
   if(!isEmpty(top)) {
      data = stack[top];
      top--;   
      return data;
   } 
   else {
      cout<<"Stack is empty.\n";
   }
}

int push(int stack[],int &top,int data) {
   if(!isFull(top)) {
       top++; 
       stack[top] = data;
   } 
   else {
      cout<<"Stack is full.\n";
   }
}

void print(int top)
{
   while(!isEmpty(top)) {
      int data = pop(stack1,top);
      cout<<data<<endl;
   }
}

int main() {
   // push items on to the stack 
   int n,ele,del,flag=0;
   int choice;
   cout<<"Enter Number Of Elements: ";
   cin>>n;
   cout<<"Enter Elements: ";
   for(int i=0;i<n;i++)
   {
      cin>>ele;
      push(stack1,top1,ele);
   }
   while(top1>=-1) {
   cout<<"1.DISPLAY"<<endl<<"2.PEEK"<<endl<<"3.CHANGE"<<endl<<"4.EXIT"<<endl;
   cin>>choice;
   cout<<endl;
   switch(choice) {
      case 1:
         print(top1);
         break;
      case 2:
         cout<<"Peek Element is: "<<peek()<<endl;
         break;
      case 3:
        { cout<<"Enter Element To Change: ";
         cin>>del;
         while(!isEmpty(top1))
         {
            int data;
            data=pop(stack1,top1);
            if(data==del)
            {
               flag=1;
               break;
            }
            else{
               push(stack2,top2,data);
            }
         }
         if(flag==0)
         {
            cout<<"Not Found: ";
         }
         else
         {
            cout<<"Enter New Element: ";
            cin>>ele;
            push(stack1,top1,ele);
         }
         while(!isEmpty(top2))
         {
            int data;
            data=pop(stack2,top2);
            push(stack1,top1,data);
         }}
         break;
      case 4:
          return 0;
      default:
         cout<<"Enter Valid Choice: "<<endl;
   }
}
}
