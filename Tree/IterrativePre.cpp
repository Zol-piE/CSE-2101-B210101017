#include<iostream>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};
node *createBST(node *root,int info)
{
    if(root == NULL)
    {
        root = new node(info);
        return root;
    }
    if( root->data>=info ) root->left = createBST(root->left,info);
    else root->right = createBST(root->right,info);
    return root;
}
void preorderRec(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<< " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }
}
void iterativePreorder(node *root)
{
    if(root == NULL ) return ;
    stack<node*> st;
    st.push(root);
    node *curr = NULL;
    while( !st.empty() )
    {
        curr = st.top(); st.pop();
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            if(curr->right != NULL) st.push(curr->right);
            curr = curr->left;
        }
    }
    cout<<endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    int x;
    node *root = NULL;
    while(cin>>x && x!=-1)
    {
        root = createBST(root,x);
    }
    preorderRec(root); cout<<endl;
    iterativePreorder(root);
    return 0;
}
