// Write A Program To Create Linked List & Insert Node In Ascending Order. 

#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;

    Node(int value)
    {
        this->data = value;
        this->Next = NULL;
    }
};

void Insert_At_Head(Node *&head, int value)
{
    Node *temp = new Node(value);
    temp->Next = head;
    head = temp;
}

void Insert_As_Asc(Node *&head, int value)
{
    if ((head->data) > value)
    {
        Insert_At_Head(head, value);
    }
    else
    {
        Node *temp = head;
        while (temp->Next != NULL && value > (temp->Next->data))
        {
            temp = temp->Next;
        }
        Node *node = new Node(value);
        node->Next = temp->Next;
        temp->Next = node;
    }
}

void Display_List(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->Next;
    }
    cout << endl;
}

int main()
{
    int choice;
    int value;
    int pos;
    cout << "Program To Create Sorted Linked List \n";
    cout << "Enter Value For First Node: ";
    cin >> value;
    Node *head = new Node(value);
    cout << "Enter Choice:- \n";
    cout << "1.Insert Node In Linked List \n";
    cout << "2.Display Linked List \n";
    cout << "0.Exit \n";

    while (1 < 2)
    {
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            Insert_As_Asc(head, value);
            cout << endl;
            break;
        case 2:
            Display_List(head);
            cout << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Enter Valid Input...\n ";
        }
    }
}
