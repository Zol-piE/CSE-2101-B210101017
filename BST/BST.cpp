#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};
void insertBST(Node *&root,int info)
{
    if(root==NULL)
    {
        root = new Node(info);
        return;
    }
    Node *temp = root;
    Node *prev = NULL;

    while(temp!= NULL)
    {
        if(info < temp->data)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if(prev->data > info ) prev->left = new Node(info);
    else prev->right = new Node(info);
}
bool searchBST(Node *root,int key)
{
    if(root == NULL ) return false;

    if(root->data == key ) return true ;

    if(root->data > key ) return searchBST(root->left,key);

    else return searchBST(root->right,key);

}
void inorder(Node *root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    Node *root = NULL;
    insertBST(root,10);
    insertBST(root,5);
    insertBST(root,8);
    insertBST(root,11);
    insertBST(root,9);
    insertBST(root,20);
    inorder(root);
    int key; cin>>key;
    if(searchBST(root,key)) cout<<key<<" IS Found "<<endl;
    else cout<<"Not Found " <<endl;

    return 0;
}
