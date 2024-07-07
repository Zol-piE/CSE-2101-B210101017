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
node *create(node *temp,int info)
{
    if(temp==NULL)
    {
        temp = new node(info);
        return temp;
    }
    if(temp->data >= info ) temp->left = create(temp->left,info);
    else temp->right = create(temp->right,info);
    return temp;
}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
void kDistance(node *temp,int k)
{
    if(temp==NULL) return;
    if(k==0) cout<<temp->data<<" ";
    else
    {
        kDistance(temp->left,k-1);
        kDistance(temp->right,k-1);
    }
}
void printLevel(node *temp)
{
    queue<node*> qt;
    qt.push(temp);

//    cout << temp->data << " " << endl;
    qt.push(NULL);
    while (qt.size() > 1)
    {
        temp = qt.front(); qt.pop();
        if (temp == NULL)
        {
            cout << endl;
            qt.push(NULL);
            continue;
        }
        cout << temp->data << " ";
        if (temp->left != NULL) qt.push(temp->left);
        if (temp->right != NULL) qt.push(temp->right);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node *tree =NULL;
    int x;
    while(cin>>x && x!=-1)
    {
        tree = create(tree,x);
    }
    inorder(tree); cout<<endl;
    kDistance(tree,2);cout<<endl;
    kDistance(tree,3);cout<<endl;
    printLevel(tree);
    return 0;
}
