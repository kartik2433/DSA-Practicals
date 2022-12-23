//Write Menu Driven Program To Do BAsic Operation On Doubly Linked List.

#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;
    Node *Prev;

    Node(int value)
    {
        this->data = value;
        this->Next = NULL;
        this->Prev = NULL;
    }
};

void Insert_At_Head(Node *&head, int value)
{
    Node *temp = new Node(value);
    temp->Next = head;
    head->Prev = temp;
    head = temp;
}

void Insert_At_Tail(Node *&head, int value)
{
    Node *node = new Node(value);
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = node;
    node->Prev = temp;
}

void Insert_At_POS(Node *&head, int pos, int value)
{
    if (pos == 1)
    {
        Insert_At_Head(head, value);
    }
    else
    {
        int count = 2;
        Node *temp = head;
        while (count != pos)
        {
            if (temp->Next == NULL)
            {
                Insert_At_Tail(head, value);
                return;
            }
            temp = temp->Next;
            count++;
        }
        if (temp->Next == NULL)
        {
            Insert_At_Tail(head, value);
            return;
        }
        Node *node = new Node(value);
        (temp->Next)->Prev = node;
        node->Next = temp->Next;
        temp->Next = node;
        node->Prev = temp;
    }
}

void Delete_Node(Node *&head, int pos)
{
    if (pos == 0)
    {
        cout << "Error: Invalid Position \n";
        return;
    }
    else if (pos == 1)
    {
        head = head->Next;
        head->Prev = NULL;
    }
    else
    {
        int count = 1;
        Node *Current = head;
        Node *NEXT;
        while (count != pos)
        {
            if (Current->Next == NULL)
            {
                cout << "Error: Invalid Position \n";
                return;
            }
            NEXT = Current;
            Current = Current->Next;
            count++;
        }
        NEXT->Next = Current->Next;
        ((Current->Next)->Prev) = NEXT;
        Current->Next = NULL;
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
    cout << "NULL." << endl;
}

void Display_List_Prev(Node *&head)
{
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    cout << "NULL";
    while(temp != NULL){
        cout<<" <- "<<temp->data;
        temp=temp->Prev;
    }
    cout<<endl;
}

int main()
{
    int value;
    int choice;
    int pos;
    cout<<"Enter First Value: ";
    cin>>value;
    Node *head = new Node(10);
    cout << "Enter Choice:- \n";
    cout << "1.Insert Node In Front Of Doubly Linked List \n";
    cout << "2.Insert Node At The End Of The Doubly Linked List \n";
    cout << "3.Delete Node Before Specific Node \n";
    cout << "4.Delete Node After Specific Node \n";
    cout << "5.Display Linked List \n";
    // cout << "6.Insert At Any Position \n";
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
            Insert_At_Head(head, value);
            cout << endl;
            break;
        case 2:
            cout << "Enter Value: ";
            cin >> value;
            Insert_At_Tail(head, value);
            cout << endl;
            break;
        case 3:
            cout << "Give Position: ";
            cin >> pos;
            Delete_Node(head, pos - 1);
            cout << endl;
            break;
        case 4:
            cout << "Give Position: ";
            cin >> pos;
            Delete_Node(head, pos + 1);
            cout << endl;
            break;
        case 5:
            Display_List(head);
            cout << endl;
            break;
        case 0:
            return 0;
        // case 6:
        //     cout << "Enter Value: ";
        //     cin >> value;
        //     cout << "Give Position: ";
        //     cin >> pos;
        //     Insert_At_POS(head,pos,value);
        //     break;
        default:
            cout << "Enter Valid Input...\n ";
        }
    }
}
