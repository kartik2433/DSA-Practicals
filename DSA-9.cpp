#include <iostream>
#include <iomanip>
using namespace std;

class tree
{
public:
    int data;
    tree *left;
    tree *right;

    tree(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

tree *Insert(tree *root, int value)
{
    tree *node = root;
    if (root == NULL)
    {
        tree *temp = new tree(value);
        return temp;
    }
    if (value < root->data)
    {
        node->left = Insert(node->left, value);
    }
    if (value > node->data)
    {
        node->right = Insert(node->right, value);
    }
    return node;
}

void preorder(tree *root)
{
    tree *node = root;
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(tree *root)
{
    tree *node = root;
    if (root == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(tree *root)
{
    tree *node = root;
    if (root == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main()
{
    int value;
    int nodes;
    int choice;
    tree *root = NULL;
    cout << "How Many Nodes: ";
    cin >> nodes;
    cout << "Enter Root Node Value: ";
    cin >> value;
    root = Insert(root, value);
    cout << "Enter Values: \n";
    for (int i = 0; i < nodes - 1; i++)
    {
        cin >> value;
        Insert(root, value);
    }
    cout << "Traversal Menu \n";
    cout << "1.Inorder Traversal \n";
    cout << "2.Preorder Traversal \n";
    cout << "3.Postorder Traversal \n";
    cout << "0.Exit \n";
    while (1 < 2)
    {
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "1.Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 2:
            cout << "2.Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 3:
            cout << "3.Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Enter Valid Input...\n";
        }
    }
}
