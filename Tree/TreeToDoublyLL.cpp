#include<iostream>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int data;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
}*p = NULL;

node* create(node *root, int info)
{
    if(root == NULL)
    {
        root = new node(info);
        return root;
    }
    if(root->data >= info)
        root->left = create(root->left, info);
    else
        root->right = create(root->right, info);
    return root;
}

node* TreeToLinkedL(node *root)
{
    if(root == NULL)
        return root;

    node *head = TreeToLinkedL(root->left);

    if(p == NULL)
    {
        head = root;
    }
    else
    {
        root->left = p;
        p->right = root;
    }
    p = root;

    TreeToLinkedL(root->right);

    return head;
}

void inorder(node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void display(node *ptr)
{
    if(ptr == NULL)
        return;

    cout << ptr->data << " ";
    display(ptr->right);
}

int main()
{
    node *tree = NULL;
    int x;
    while(cin >> x && x != -1)
    {
        tree = create(tree, x);
    }

    cout << "Inorder Traversal of the BST: ";
    inorder(tree);
    cout << endl;

    node *listHead = TreeToLinkedL(tree);

    cout << "Doubly Linked List: ";
    display(listHead);
    cout << endl;

    return 0;
}
