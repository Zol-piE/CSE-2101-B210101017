#include<iostream>
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
node *ConvertToTree(int iArr[],int prArr[],int is,int ie)
{
    if(is>ie) return NULL;
    static int preIndex =0;
    node *root = new node(prArr[preIndex++]);
    int i=is;
    for(;i<=ie;i++)
    {
        if(iArr[i]==root->data)
        {
            break;
        }
    }
    root->left = ConvertToTree(iArr,prArr,is,i-1);
    root->right = ConvertToTree(iArr,prArr,i+1,ie);
    return root;

}
void inorder(node *root)
{
    if(root!=NULL){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}
int main()
{
    int iArr[]={5,7,8,9,10,11,17,21};
    int prArr[]={10,7,5,9,8,17,11,21};
    int n = sizeof(iArr) / sizeof(iArr[0]);
    node *root = ConvertToTree(iArr,prArr,0,n-1);
    inorder(root);

    return 0;
}
