#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchBST(Node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    else if (key < root->data)
        return searchBST(root->left, key);

    else
        return searchBST(root->right, key);
}

int main()
{
    Node* root = NULL;
    int choice, key;

    int arr[] = {6, 9, 5, 7, 15, 14, 10, 8, 5, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Create BST of n integers\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Preorder traversal\n";
        cout << "4. Postorder traversal\n";
        cout << "5. Search for an element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (root == NULL)
                {
                    for (int i = 0; i < n; i++)
                        root = insertBST(root, arr[i]);

                    cout << "BST created with given integers\n";
                }
                else
                    cout << "BST already created\n";
                break;

            case 2:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> key;

                if (searchBST(root, key))
                    cout << "Element found in BST\n";
                else
                    cout << "Element not found\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again\n";
        }
    }
    while (choice != 6);

    return 0;
}