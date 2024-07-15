#include<iostream>
#include<vector>
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
bool findPath(node *root,vector<int> &v,int key)
{
    if(root== NULL) return false;
    v.push_back(root->data);
    if(root->data == key) return true;
    if(findPath(root->left,v,key) || findPath(root->right,v,key)) return true;
    v.pop_back();
    return false;
}
node *create(node *root,int info)
{
    if(root==NULL)
    {
        root = new node(info);
        return root;
    }
    if(root->data >= info ) root->left = create(root->left,info);
    else root->right = create(root->right,info);
    return root;

}
void levelOrder(node *root)
{
    queue<node*> qt;
    qt.push(root);
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=0;i<n;i++)
        {
            node *temp = qt.front(); qt.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL) qt.push(temp->left);
            if(temp->right!=NULL) qt.push(temp->right);
        }
        cout<<endl;
    }
}
int main()
{
    node *root = NULL;
    int x;
    while(cin>>x && x!=-1)
    {
        root = create(root,x);
    }
    levelOrder(root);
    vector<int> vect;
    cout<<"KEy : "; cin>>x;cout<<endl;

    if(!findPath(root,vect,x)) cout<<"NOt Found"<<endl;
    else
    {
        for(int i=0;i<vect.size();i++)
        {
            cout<<vect[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
