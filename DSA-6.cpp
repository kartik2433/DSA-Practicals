// Write A Menu Driven Program To Do Linked List Basic Operations. 
// Insert Node At Head,Tail & At Any Position.
// Delete Node From Specific Location.(Assume Head Has 1st Position Not 0.)

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

void Insert_At_Tail(Node *&head, int value)
{
    Node *node = new Node(value);
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = node;
}

// void Insert_At_POS(Node *&head, int pos, int value)
// {
//     if (pos == 1)
//     {
//         Insert_At_Head(head, value);
//     }
//     else
//     {
//         int count = 2;
//         Node *temp = head;
//         while (count != pos)
//         {
//             if (temp->Next == NULL)
//             {
//                 Insert_At_Tail(head, value);
//                 return;
//             }
//             temp = temp->Next;
//             count++;
//         }
//         Node *node = new Node(value);
//         node->Next = temp->Next;
//         temp->Next = node;
//     }
// }

void Delete_Node(Node *&head, int pos)
{

    if(pos == 0){
        cout<<"Error: Invalid Position \n";
        return;
    }
    else if (pos == 1)
    {
        head = head->Next;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        Node *Prev;
        while (count != pos)
        {
            if(temp->Next == NULL){
                cout<<"Error: Invalid Position \n";
                return;
            }
            Prev = temp;
            temp = temp->Next;
            count++;
        }

        Prev->Next = temp->Next;
        temp->Next = NULL;
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
    cout <<" NULL."<< endl;
}

int main()
{
    int choice;
    int value;
    int pos;
    cout << "Enter Value For First Node: ";
    cin >> value;
    Node *head = new Node(value);
    cout << "Enter Choice:- \n";
    cout << "1.Insert Node In Front Of Linked List \n";
    cout << "2.Insert Node At The End Of The Linked List \n";
    cout << "3.Delete Specific Node \n";
    cout << "4.Delete Node Before Specific Node \n";
    cout << "5.Delete Node After Specific Node \n";
    cout << "6.Display Linked List \n";
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
            Delete_Node(head, pos);
            cout << endl;
            break;
        case 4:
            cout << "Give Position: ";
            cin >> pos;
            Delete_Node(head, pos - 1);
            cout << endl;
            break;
        case 5:
            cout << "Give Position: ";
            cin >> pos;
            Delete_Node(head, pos + 1);
            cout << endl;
            break;
        case 6:
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
