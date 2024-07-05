#include<iostream>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int data) : node()
    {
        this->data = data;
    }
};
class qnode
{
public:
    node *data;
    qnode *next;
    qnode(node *var)
    {
        this->data = var;
        next = NULL;
    }
};
class Queue
{
public:
    qnode *Front ,*Rear;
    Queue()
    {
        Front = NULL;
        Rear =NULL;
    }
    void enqueue(node *var)
    {
        qnode *temp = new qnode(var);
        if(Front ==NULL && Rear == NULL)
        {
            Front = temp;
            Rear = temp;
            return ;
        }
        Rear->next = temp;
        Rear = temp;
    }
    node *dequeue()
    {
        if(Front==NULL) return NULL;

        node *temp = Front->data;
        Front = Front ->next;
        if(Front==NULL) Rear = NULL;
        return temp;
    }
    bool isEmpty()
    {
        return (Front ==NULL && Rear==NULL );
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
    void Create()
    {
        Queue *qt = new Queue();
        int x; cout<<"Enter Root Node ";
        cin>>x; cout<<endl;
        root = new node(x);
        qt->enqueue(root);
        while(!qt->isEmpty())
        {
            node *ptr = qt->dequeue();
            cout<<ptr->data<<" Node Left Child or -1 ";
            cin>>x;cout<<endl;
            if(ptr->left==NULL && x!= -1)
            {
                node *temp = new node(x);
                ptr->left = temp;
                qt->enqueue(temp);
            }
            cout<<ptr->data<<" Node Right Child or -1 ";
            cin>>x;cout<<endl;
            if(ptr->right==NULL && x!= -1)
            {
                node *temp = new node(x);
                ptr->right = temp;
                qt->enqueue(temp);
            }
        }
    }
};
void preorder(node *temp)
{
    stack<node*> st;
    while(temp!=NULL || !st.empty())
    {
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            temp = st.top();
            st.pop();
            temp=temp->right;
        }
    }
}

void inorder(node *temp)
{
    stack<node*> st;
    while(temp!=NULL || !st.empty())
    {
        if(temp!=NULL)
        {
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}
int main()
{
    tree *obj = new tree();
    obj->Create();
    preorder(obj->root);
    cout<<endl;
    inorder(obj->root);
    return 0;
}

