#include<iostream>
#include<vector>
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
    if(info<= root->data) root->left = createBST(root->left,info);
    else root->right = createBST(root->right,info);
    return root;

}
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";

        preorder(root->left);

        preorder(root->right);
    }
}
void Serial(node *&root,vector<int> &vect)
{
    if(root==NULL) vect.push_back(-1);
    else{
        vect.push_back(root->data);
        Serial(root->left,vect);
        Serial(root->right,vect);
    }
}
node *deSerial(node *root,vector<int> &vect)
{
    static int i =0;
    if(vect[i]==-1)
    {
        i++;
        return NULL;
    }
    root = new node(vect[i++]);
    root->left = deSerial(root->left,vect);
    root->right = deSerial(root->right,vect);
    return root;
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
    cout<<"Preorder : "; preorder(root); cout<<endl;
    vector<int> vect;
    Serial(root,vect);
    for(int x : vect)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    node *root2= deSerial(root,vect);
    preorder(root2);
    return 0;
}
