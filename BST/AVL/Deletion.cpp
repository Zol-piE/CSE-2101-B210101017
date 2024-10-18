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

    node(int data) : data(data),left(NULL),right(NULL),height(1) { }

};
class Bst
{
public:
    node *root;
    Bst() : root(NULL) {}
    node* rinsert(node *root,int data);
    void levelOrder();
    node* deleteNode(node *root,int data);
    void inorder(node *root);
};
void Bst :: inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int height(node *root)
{
    int left,right;
    left = (root&&root->left) ? root->left->height : 0;
    right = (root&& root->right) ? root->right->height : 0;
    return 1 + max(left,right);
}
int bf(node *root)
{
    int left,right;
    left = (root&&root->left) ? root->left->height : 0;
    right = (root&& root->right) ? root->right->height : 0;
    return left - right;

}
node* LL(node *ptr,node *&root)
{
    node *temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;
    if(ptr==root) root=temp;
    ptr->height = height(ptr);
    temp->height = height(temp);
    return temp;
}
node *RR(node *ptr,node *&root)
{
    node *temp = ptr->right;
    ptr->right = temp->left;
    temp->left = ptr;
    if(ptr==root) root = temp;
    ptr->height = height(ptr);
    temp->height = height(temp);
    return temp;
}
node *LR(node *ptr,node *&root)
{
    node *leftP = ptr->left;
    node *rightP = leftP->right;

    ptr->left = rightP->right;
    leftP->right = rightP->left;

    rightP->right = ptr;
    rightP->left = leftP;
    if(ptr==root) root = rightP;
    ptr->height = height(ptr);
    leftP->height = height(leftP);
    rightP->height = height(rightP);

    return rightP;
}
node* RL(node *ptr,node *&root)
{
    node *rightP = ptr->right;
    node *leftP = rightP->left;

    ptr->right=leftP->right;
    rightP->left=leftP->left;

    leftP->right = rightP;
    leftP->left = ptr;
    if(root == ptr ) root = leftP;
    ptr->height = height(ptr);
    rightP->height = height(rightP);
    leftP->height = height(leftP);
    return leftP;

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

    root->height = height(root);

    if(bf(root)==2 && bf(root->left)==1) return LL(root,this->root);
    if(bf(root)==-2 && bf(root->right)==-1) return RR(root,this->root);
    if(bf(root)==2&& bf(root->left)==-1) return LR(root,this->root);
    if(bf(root)==-2&& bf(root->right)==1) return RL(root,this->root);

    return root;
}
void Bst:: levelOrder()
{
    if(this->root==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }
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
node *predecessor(node *root)
{
    while(root!=NULL && root->right != NULL) root = root->right;
    return root;
}
node *successor(node *root)
{
    while(root !=NULL &&root->left != NULL ) root = root->left;
    return root;
}
node* Bst :: deleteNode(node *root,int data)
{
    if(root==NULL) return NULL;

    if(data < root->data ) root->left = deleteNode(root->left,data);

    else if(data > root->data ) root->right = deleteNode(root->right,data);

    else
    {
        if(root->left==NULL && root->right==NULL )
        {
            return NULL;
        }
        if((root->left!=NULL && root->right==NULL) ||(root->left->height)>(root->right->height))
        {
            node *temp = predecessor(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left,temp->data);
        }
        else
        {
            node *temp = successor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    root->height = height(root);
    if(bf(root)==2 && bf(root->left)==1) return LL(root,this->root);
    if(bf(root)==2 && bf(root->left)==-1) return LR(root,this->root);
    if(bf(root)==2 && bf(root->left)==0) return LR(root,this->root);
    if(bf(root)==-2 && bf(root->right)==-1) return RR(root,this->root);
    if(bf(root)==-2 && bf(root->right)==1) return RL(root,this->root);
    if(bf(root)==-2 && bf(root->right)==0) return RL(root,this->root);

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
        tree.inorder(tree.root); cout<<endl;
        cout<<"Delete Node"<<endl;
        int key;
        while(cin>>key && key !=-1)
        {
            tree.root=tree.deleteNode(tree.root,key);
            tree.levelOrder();
            tree.inorder(tree.root); cout<<endl;
            if(tree.root==NULL) break;
            cout<<"Delete Node"<<endl;
        }
    }


    return 0;
}
