#include<iostream>
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
class tree
{
public:
    node *root;
    tree()
    {
        root=NULL;
    }
    void create()
    {
        int x;
        queue<node*> qt;
        cout<<"Enter Root "; cin>>x; cout<<endl;
        root = new node(x);
        qt.push(root);
        while(!qt.empty())
        {
            node *ptr = qt.front();
            qt.pop();
            cout<<ptr->data<<" node Left or -1 "; cin>>x; cout<<endl;
            if(ptr->left== NULL && x!=-1)
            {
                node *temp = new node(x);
                ptr->left = temp;
                qt.push(temp);
            }
            cout<<ptr->data<<" node Right or -1 "; cin>>x; cout<<endl;
            if(ptr->right==NULL && x!=-1)
            {
                node *temp = new node(x);
                ptr->right = temp;
                qt.push(temp);
            }
        }

    }
};
void levelTraverse(node *temp)
{
    queue<node*> qt;
    qt.push(temp);
    cout<<temp->data<<" ";
    while(!qt.empty())
    {
        temp = qt.front();
        qt.pop();
        if(temp->left != NULL)
        {
            cout<<temp->left->data<<" ";
            qt.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            cout<<temp->right->data<<" ";
            qt.push(temp->right);
        }
    }
}
int main()
{
    tree *obj = new tree();
    obj->create();
    levelTraverse(obj->root);
    return 0;
}
