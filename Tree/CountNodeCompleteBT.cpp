#include<iostream>
#include<stack>
#include<queue>
#include<math.h>
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
node *create()
{
    queue<node*> st;
    int x ; cin>>x;
    node *root = new node(x);
    st.push(root);
    while(!st.empty())
    {
        node *ptr = st.front(); st.pop();
        cin>>x;
        if(x!=-1)
        {
            node *temp = new node(x);
            ptr->left = temp;
            st.push(temp);
        }
        cin>>x;
        if(x!=-1)
        {
            node *temp = new node(x);
            ptr->right = temp;
            st.push(temp);
        }
    }
    return root;
}
node *createBst(node *root,int data)
{
    if(root == NULL )
    {
        root = new node(data);
        return root;
    }
    if(data <= root->data) root->left = createBst(root->left,data);
    else root->right = createBst(root->right,data);
    return root;
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
int countNode(node *root)
{
    if(root==NULL) return 0;
    node *ptr = root;
    int lh = 0,rh =0;
    while(ptr!=NULL)
    {
        ptr=ptr->left;
        lh++;
    }
    ptr= root;
    while(ptr!=NULL)
    {
        rh++;
        ptr = ptr->right;
    }
    if(lh==rh) return pow(2,lh)-1;
    else  return 1 + countNode(root->left) + countNode(root->right) ;

}
int main()
{
    freopen("input.txt","r",stdin);
    node *root = create();
    inorder(root);cout<<endl;
    countNode(root);
    cout<<countNode(root)<<endl;
    int x;
    root = NULL;
    while(cin>>x && x!=-1)
    {
        root = createBst(root,x);
    }
    inorder(root);cout<<endl;
    cout<<countNode(root)<<endl;
    return 0;
}
