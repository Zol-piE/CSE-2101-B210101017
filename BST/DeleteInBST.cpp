#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Bst
{
public:
    node *root;
    Bst() { root = NULL; }
    node *rinsert(node *&root,int data);
    void  inorder(node *ptr)
    {
        if(ptr!=NULL)
        {
            inorder(ptr->left);
            cout<<ptr->data<< " ";
            inorder(ptr->right);
        }
    }
    node* ndelete(node *root,int key);
    int height(node *root);
    void levelOrder(node *root);

};
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
node *getsuccessor(node *ptr)
{
    while(ptr!=NULL && ptr->left != NULL) ptr = ptr->left;
    return ptr;
}
node *getpredecessor(node *ptr)
{
    while(ptr!=NULL && ptr->right != NULL) ptr = ptr->right;
    return ptr;
}
int Bst::height(node *root)
{
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
node* Bst:: rinsert(node *&root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }
    if(data< root->data ) root->left = rinsert(root->left,data);
    else root->right = rinsert(root->right,data);
    return root;
}
node* Bst::ndelete(node *ptr,int key)
{
   if(ptr==NULL)
   {
       return NULL;
   }
   if(key < ptr->data ) ptr->left = ndelete(ptr->left,key);
   else if(key > ptr->data ) ptr->right = ndelete(ptr->right,key);
   else
   {
       if(ptr->left == NULL && ptr->right == NULL)
       {
           if(this->root == ptr )
           {
               root = NULL;
           }
           delete ptr;
           return NULL;
       }
       else
       {
           if(height(ptr->left) > height(ptr->right))
           {
               node *temp = getpredecessor(ptr->left);
               ptr->data = temp->data;
               ptr->left = ndelete(ptr->left,temp->data);

           }
           else{
               node *temp = getsuccessor(ptr->right);
               ptr->data = temp->data;
               ptr->right = ndelete(ptr->right,temp->data);

           }
       }
   }
       return ptr;
}
int main()
{
    Bst tree;
    tree.root =tree.rinsert(tree.root,15);
    tree.rinsert(tree.root,10);
    tree.rinsert(tree.root,13);
    tree.rinsert(tree.root,5);
    tree.rinsert(tree.root,7);
    tree.rinsert(tree.root,6);
    tree.rinsert(tree.root,20);
    tree.rinsert(tree.root,18);
    tree.rinsert(tree.root,30);
    tree.rinsert(tree.root,40);
    tree.rinsert(tree.root,35);
    tree.rinsert(tree.root,37);
    tree.rinsert(tree.root,50);







    tree.levelOrder(tree.root);



    tree.ndelete(tree.root,5);


    tree.levelOrder(tree.root);

    tree.ndelete(tree.root,30);

    tree.levelOrder(tree.root);
    return 0;
}
