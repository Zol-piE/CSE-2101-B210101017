#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int data) : data(data),left(NULL),right(NULL),height(1) {}

};

class Bst
{
public:
    node *root;
    Bst() : root(NULL) {}
    void levelOrder();
    node* rinsert(node *root,int data);

};
int height(node *root)
{
    int left,right;
    left = (root && root->left) ? root->left->height : 0;
    right = (root && root->right ) ? root->right->height : 0;
    return 1+ max(left,right);

}
int bf(node *root)
{
    int left, right;
    left = (root->left) ? root->left->height : 0;
    right = (root->right) ? root->right->height : 0;
    return left - right;

}
void Bst:: levelOrder()
{
    queue<node*> qt;
    qt.push(this->root);
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=0;i<n;i++)
        {
            node *ptr = qt.front(); qt.pop();
            cout<<ptr->data<<"("<<ptr->height<<","<<bf(ptr)<<") ";

            if(ptr->left) qt.push(ptr->left);
            if(ptr->right) qt.push(ptr->right);

        }
        cout<<endl;
    }
}
node *LL(node *ptr,node *root)
{
    node *temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;
    if(root==ptr) root = temp;
    ptr->height = height(ptr);
    temp->height = height(temp);
    return temp;
}
node *RR(node *ptr,node *root)
{
    node *temp = ptr->right;
    ptr->right = temp->left;
    temp->left = ptr;
    if(root==ptr ) root = temp;
    ptr->height = height(ptr);
    temp->height = height(temp);
    return temp;
}
node *LR(node *ptr,node *root)
{
    node *pl = ptr->left;
    node *plr = pl->right;

    ptr->left=plr->right;
    pl->right=plr->left;

    plr->left = pl;
    plr->right = ptr;

    pl->height = height(pl);
    ptr->height = height(ptr);
    plr->height = height(plr);

    return plr;

}
node *RL(node *ptr,node *root)
{
    node *rptr = ptr->right;
    node *lptr = rptr->left;
    ptr->right = lptr->left;
    rptr->left = lptr->right;
    lptr->right =rptr;
    lptr->left = ptr;
    if(root == ptr ) root = lptr;
    ptr->height = height(ptr);
    rptr->height = height(rptr);
    lptr->height = height(lptr);
    return lptr;
}
node* Bst :: rinsert(node *root,int data)
{
    if(root==NULL)
    {
        root= new node(data);
        return root;
    }
    if(data<root->data) root->left = rinsert(root->left,data);
    else root->right = rinsert(root->right,data);
    root->height = height(root);
    if(bf(root)==2 && bf(root->left)==1) return LL(root,this->root);
    if(bf(root)==-2 && bf(root->right)==-1) return RR(root,this->root);
    if(bf(root)==2 && bf(root->left)==-1) return LR(root,this->root);
    if(bf(root)==-2 && bf(root->right)==1) return RL(root,this->root);
    return root;
}
int main()
{
    string str;
    Bst tree;

    while(cin>>str && str !="no")
    {
        int n;
        while(cin>>n && n!=-1)
        {
            tree.root = tree.rinsert(tree.root,n);
        }
        tree.levelOrder();
    }
    return 0;
}
