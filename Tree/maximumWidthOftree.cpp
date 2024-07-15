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
        left= NULL;
        right = NULL;
    }
};
void create(node *&root)
{
    int x; cin>>x;
    queue<node*> qt;
    root = new node(x);
    qt.push(root);
    while(!qt.empty())
    {
        node *ptr = qt.front(); qt.pop();
        cin>>x;
        if(ptr->left== NULL && x !=-1 )
        {
            node *temp = new node(x);
            ptr->left = temp;
            qt.push(temp);
        }
        cin>>x;
        if(ptr->right == NULL && x!=-1)
        {
            node *temp = new node(x);
            ptr->right = temp;
            qt.push(temp);
        }
    }
}
int isBalanced(node *root)
{
    if(root==NULL) return 0;
    int left = isBalanced(root->left);
    if(left == -1 ) return -1;
    int right = isBalanced(root->right);
    if(right == -1) return -1;
    if(abs(left - right) > 1 ) return -1;
    else return max(left,right) + 1 ;
}
void inorder(node *ptr)
{

    if(ptr!=NULL)
    {
    inorder(ptr->left);
    cout<<ptr->data<<" ";
    inorder(ptr->right);
    }
}
int width(node *root)
{
    queue<node*> qt;
    qt.push(root);
    int res= INT_MIN;
    while(!qt.empty())
    {
        int n = qt.size();
        res = max(n,res);
        for(int i=0;i<n;i++)
        {
            node *temp = qt.front(); qt.pop();
            if(temp->left!=NULL) qt.push(temp->left);
            if(temp->right!=NULL) qt.push(temp->right);
        }
    }
    return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node *root;
    create(root);
    inorder(root); cout<<endl;
    if(isBalanced(root)!=-1) cout<<"Height Balanced "<<endl;
    else cout<<"Not"<<endl;
    cout<<width(root)<<endl;
    return 0;
}
