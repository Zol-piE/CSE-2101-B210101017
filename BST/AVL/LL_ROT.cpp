#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    int height;
    node *left;
    node *right;
    node(int data) : data(data), height(1), left(NULL), right(NULL) {}
};
class Bst
{
public:
    node *root;
    Bst()
    {
        root = NULL;
    }
    node* rinsert(node *root,int data);
    void inorder(node *ptr);
};
void Bst :: inorder(node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<< " ";
        inorder(ptr->right);
    }
}
int bf(node *ptr)
{
    int left,right;
    left = (ptr && ptr->left) ? ptr->left->height : 0;
    right = (ptr && ptr->right) ? ptr->right->height : 0;
    return (left - right);
}
int nodeHeight(node *ptr)
{
    int left , right;
    left =(ptr && ptr->left) ? ptr->left->height : 0;
    right =(ptr && ptr->right) ? ptr->right->height : 0;

    return 1+max(left,right);

}
node *LL(node *ptr,node *root)
{
    node *temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;
    if(root==temp) root = temp;
    ptr->height = nodeHeight(ptr);
    temp->height = nodeHeight(temp);
    return temp;
}
node* Bst :: rinsert(node *root,int data)
{
    if(root==NULL)
    {
        root = new node(data);
        return root;
    }
    if(data < root->data ) root->left = rinsert(root->left,data);
    else root->right = rinsert(root->right,data);

    root->height = nodeHeight(root);
    if(bf(root)==2 && bf(root->left)==1)
    {
        return LL(root,this->root);
    }
    return root;
}
void levelOrder(node *root)
{
    queue<node*> qt;
    qt.push(root);
    node *ptr=NULL;
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=0;i<n;i++)
        {
            ptr = qt.front(); qt.pop();
            cout<<ptr->data<<"("<<ptr->height<<")"<<" ";
            if(ptr->left != NULL) qt.push(ptr->left);
            if(ptr->right != NULL) qt.push(ptr->right);
        }
        cout<<endl;
    }
}
int main()
{
    Bst tree;
    int n;
    while(cin>>n && n!=-1)
    {
        tree.root = tree.rinsert(tree.root,n);
    }
    cout<<nodeHeight(tree.root)<< " " <<nodeHeight(tree.root->left)<<" "<<nodeHeight(tree.root->right)<<endl;
    cout<<bf(tree.root)<< " " <<bf(tree.root->left)<<" "<<bf(tree.root->right)<<endl;
    levelOrder(tree.root);
    cin>>n;
    tree.rinsert(tree.root,n);
    tree.inorder(tree.root); cout<<endl;
    levelOrder(tree.root);
    return 0;
}
