#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};
node *create(node *temp,int info)
{
    if(temp == NULL)
    {
        temp = new node(info);
        return temp;
    }
    if(temp->data >= info) temp->left = create(temp->left,info);
    else temp->right = create(temp->right,info);
    return temp;
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
void leftPrint(node *temp)
{
    queue<node*> qt;
    qt.push(temp);
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=0;i<n;i++)
        {
            node *pt = qt.front(); qt.pop();
            if(i==0) cout<<pt->data<< " ";
            if(pt->left!=NULL) qt.push(pt->left);

            if(pt->right!=NULL)  qt.push(pt->right);
        }
    }
    cout<<endl;
}
void leftPrintPre(node *root,int level)
{
    static int maxlevel =0;
    if(root==NULL) return;
    if(maxlevel < level)
    {
        cout<<root->data<< " ";
        maxlevel = level;
    }
    leftPrintPre(root->left,level+1);
    leftPrintPre(root->right,level+1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    node *root = NULL;
    int x;
    while(cin>>x && x!=-1)
    {
        root = create(root,x);
    }
    inorder(root); cout<<endl;
    leftPrint(root);
    leftPrintPre(root,1);
    return 0;
}
