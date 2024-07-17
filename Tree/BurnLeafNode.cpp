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
node *create(node *root,int info)
{
    if(root == NULL)
    {
        root = new node(info);
        return root;
    }
    if(info<=root->data) root->left = create(root->left,info);
    else root->right = create(root->right,info);
    return root;
}
void inorder(node *root)
{
    stack<node*>st;
    while(!st.empty() || root != NULL )
    {

        if(root != NULL)
        {
            st.push(root);
            root= root->left;
        }
        else
        {
            root = st.top(); st.pop();
            cout<<root->data<< " ";
            root= root->right;
        }
    }
    cout<<endl;
}
int res = INT_MIN;
int Burnleaf(node *root,int leaf,int &dist)
{
    if(root == NULL) return 0;
    if(root->data == leaf )
    {
        dist =0;
        return 1;
    }
    int left_dist =-1,right_dist = -1;
    int lh = Burnleaf(root->left,leaf,left_dist);
    int rh = Burnleaf(root->right,leaf,right_dist);
    if(left_dist!=-1)
    {
        dist = left_dist +1;
        res = max(res,rh+dist);
//        cout<<rh<<" "<<dist<<" "<<res<<endl;
    }
    else if(right_dist!=-1)
    {
        dist = right_dist + 1;
        res = max(res,dist+lh);
//        cout<<lh<<" "<<dist<<" "<<res<<endl;
    }
    return max(lh,rh)+1;
}
int main()
{
    freopen("input.txt","r",stdin);

    int x ;
    node *root = NULL;
    while(cin>>x && x!=-1)
    {
        root = create(root,x);
    }
    inorder(root);
    cin>>x;
    int dist=-1;
    cout<<"Height Of Tree "<<Burnleaf(root,x,dist)<<endl;
    cout<<"Time to Burn Tree "<<res<<endl;
    return 0;
}
