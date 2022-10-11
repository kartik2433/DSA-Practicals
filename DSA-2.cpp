// Aim: Introduction To Pointers. Call By Value And Call By Reference.

#include<iostream>
#include<conio.h>
using namespace std;

// Call By Value Swap Function
void swapv(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"A= "<<a<<endl<<"B= "<<b<<endl;
}
// Call By Reference Swap Function
void swapr(int *c,int *d)
{
    int temp;
    temp=*c;
    *c=*d;
    *d=temp;
}
int main()
{
    int A,B;
    int *c,*d;
    cout<<"Enter Two Values: "<<endl;
    cin>>A>>B;
    c=&A;
    d=&B;
    cout<<"Before Swap: "<<endl;
    cout<<"A= "<<A<<endl<<"B= "<<B<<endl;
    cout<<"Swap: Call By Value "<<endl;
    swapv(A,B);
    cout<<"Before Swap: "<<endl;
    cout<<"A= "<<*c<<endl<<"B= "<<*d<<endl;
    cout<<"Swap: Call By Reference "<<endl;
    swapr(c,d);
    cout<<"A= "<<*c<<endl<<"B= "<<*d;
    return 0;
}
