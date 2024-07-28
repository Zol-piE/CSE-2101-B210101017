#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};
class Bst
{
public:
    node *root;
    Bst() { root = NULL; }
    node* insertNode(node *root,int key);
    node* Delete(node *root,int key);
    void inorder(node *root);
    void levelOrder(node *root);

};
node* Bst ::  insertNode(node *root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }
    if(root->data > data ) root->left = insertNode(root->left,data);
    else root->right = insertNode(root->right,data);
    return root;
}
void Bst :: inorder(node *root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        cout<<root->data<< " ";
        inorder(root->right);
    }
}
void Bst::levelOrder(node *root)
{
    queue<node*> qt;
    qt.push(root);
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=1;i<=n;i++)
        {
            node *temp = qt.front();qt.pop();
            cout<<temp->data<< " ";
            if(temp->left != NULL) qt.push(temp->left);
            if(temp->right!=NULL) qt.push(temp->right);
        }
        cout<<endl;
    }
}
node *findMax(node *root)
{
    while(root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node* Bst :: Delete(node *root,int key)
{
    if(root==NULL) return NULL;

    //Searching
    if(root->data > key) root->left = Delete(root->left,key);
    else if(root->data < key ) root->right = Delete(root->right,key);
    //key matches
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(this->root == root)
            {
                this->root = NULL;
            }
            delete(root);
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            node *temp  = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *temp = findMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left,root->data);
            return root;
        }

    }
    return root;

}
int main()
{
    Bst tree;
    tree.root = tree.insertNode(tree.root,15);
    tree.insertNode(tree.root,10);
    tree.insertNode(tree.root,20);
    tree.insertNode(tree.root,5);
    tree.insertNode(tree.root,13);
    tree.insertNode(tree.root,18);
    tree.insertNode(tree.root,30);
    tree.insertNode(tree.root,7);
    tree.insertNode(tree.root,40);
    tree.insertNode(tree.root,6);
    tree.insertNode(tree.root,35);
    tree.insertNode(tree.root,50);
    tree.insertNode(tree.root,37);

    tree.levelOrder(tree.root);

    cout<<"After Deleting"<<endl;
    tree.Delete(tree.root,37);
    tree.Delete(tree.root,5);
    tree.Delete(tree.root,20);
    tree.levelOrder(tree.root);

    return 0;
}
