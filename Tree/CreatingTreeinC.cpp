#include<iostream>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    node()
    {
        left =NULL;
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

    int Size;
    int Front;
    int Rear;
    node **Q;
    qnode(int S)
    {
        this->Size =S;
        Q= new node*[Size];
        Front = 0;
        Rear = 0;
    }
    void enqueue(node *add)
    {

        if((Rear +1)%Size == Front )
        {
            cout<<"Overflow"<<endl;
            return;
        }
        Rear = (Rear +1 )%Size;

        Q[Rear] = add;
    }
    node *dequeue()
    {
        node *temp = NULL;
        if(Front == Rear )
        {
            cout<<"uNDERFLOW"<<endl;
        }
        else
        {
            Front = (Front+1) % Size ;
            temp = Q[Front];
        }
        return temp;
    }
    bool isempty()
    {
        return (Front==Rear);
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
        int size;
        cout << "Enter the initial queue size: ";
        cin >> size;
        qnode *qt = new qnode(size);
        int x;
        cout<<"Creating Root ";
        cin>>x; cout<<endl;
        root = new node(x);
        qt->enqueue(root);
        while(!qt->isempty())
        {
            node *ptr = qt->dequeue();
            cout<<"node "<<ptr->data<<" Left Child ";
            cin>>x; cout<<endl;
            if(ptr->left==NULL && x!=-1)
            {
                node *temp = new node(x);
                ptr->left = temp;
                qt->enqueue(temp);
            }
            cout<<"node "<<ptr->data<<" Right Child ";
            cin>>x; cout<<endl;
            if(ptr->right==NULL && x!=-1)
            {
                node *temp = new node(x);
                ptr->right = temp;
                qt->enqueue(temp);
            }
        }



    }
};
int main()
{
    tree *obj = new tree();
    obj->create();
    return 0;
}
