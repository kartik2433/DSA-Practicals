//Simple QUEUE 

#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 10
int front = -1;
int rear = -1;
int QUEUE[SIZE];
void enqueue(int data)
{
    if (rear == SIZE)
    {
        cout << "Queue Is Full.\n";
    }
    if (front == -1)
    {
        front = 0;
    }
    QUEUE[++rear] = data;
}
int dequeue()
{
    if (front == -1)
    {
        cout << "Queue Is Empty. \n";
    }
    else if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        return QUEUE[front++];
    }
}
void PRINT(int f, int r)
{
    for (int i = f; i <= r; i++)
    {
        cout << dequeue() << " ";
    }
    front = f;
    cout << "\n";
}
int main()
{
    int num, value;
    cout << "How Many Numbers You Want To Store ?\n";
    cin >> num;
    cout << "Enter Numbers Now...!!!\n";
    for (int i = 0; i < num; i++)
    {
        cin >> value;
        enqueue(value);
    }
    cout << "1.Enqueue Operation: \n";
    cin >> value;
    enqueue(value);
    PRINT(front, rear);
    cout << "2.Dequeue Operation: \n";
    dequeue();
    PRINT(front, rear);
    cout << "3.Display Queue: \n";
    PRINT(front, rear);
    return 0;
}
