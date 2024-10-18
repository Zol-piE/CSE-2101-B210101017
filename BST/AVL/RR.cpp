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
    node(int data) : data(data),height(1)
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
    node* rinsert(node *root,int data);
    void inorder(node *ptr);
    void levelOrder(node *ptr);
};
int height(node *ptr)
{
    int left,right;
    left = (ptr && ptr->left ) ? ptr->left->height : 0;
    right = (ptr && ptr->right ) ? ptr->right->height : 0;
    return 1+max(left,right);

}
int bf(node *ptr)
{
    int left,right;
    left = (ptr->left) ? ptr->left->height : 0;
    right = (ptr->right) ? ptr->right->height : 0;
    return left - right ;
}
void Bst :: inorder(node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }
}
void Bst:: levelOrder(node *ptr)
{
    queue<node*> qt;
    qt.push(ptr);
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=0;i<n;i++)
        {
            ptr = qt.front(); qt.pop();
            cout<<ptr->data<<"("<<ptr->height<<","<<bf(ptr)<<") ";
            if(ptr->left)  qt.push(ptr->left);
            if(ptr->right) qt.push(ptr->right);
        }
        cout<<endl;
    }
}
node *RR(node *ptr,node *root)
{
    node *temp = ptr->right;
    ptr->right = temp->left;
    temp->left = ptr;
    if(root==ptr) root = temp;
    ptr->height = height(ptr);
    temp->height = height(temp);
    return temp;
}
node *LL(node *ptr,node *root)
{
    node *temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;
    if(root==ptr) root=temp;
    ptr->height = height(ptr);
    temp->height = height(temp);
    return temp;
}
node* Bst :: rinsert(node *root,int data)
{
    if(root==NULL)
    {
        root = new node(data);
        return root;
    }
    if(data< root->data) root->left = rinsert(root->left,data);
    else root->right = rinsert(root->right,data);
    root->height = height(root);
    if(bf(root)==2 && bf(root->left)==1)
    {
        return LL(root,this->root);
    }
    if(bf(root)==-2 && bf(root->right)==-1)
    {
        return RR(root,this->root);
    }
    return root;
}
int main()
{
    Bst tree;
    int n ;
//    freopen("input.txt","r",stdin);
    string str;
    while(cin>>str && str!="no")
    {
    while(cin>>n && n!=-1)
    {
        tree.root = tree.rinsert(tree.root,n);
    }
    tree.inorder(tree.root); cout<<endl;
    tree.levelOrder(tree.root);
    }
    return 0;
}
