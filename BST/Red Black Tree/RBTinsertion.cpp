#include<iostream>
#include<queue>
using namespace std;
class RBT
{
    class node
    {
    public:
        int data;
        node *left;
        node *right;
        node *parent;
        char color;
        node(int data) : data(data),left(NULL),right(NULL),parent(NULL),color('R') { }
    };
public:
    node *root;
    bool ll,rr,lr,rl;
    RBT() : root(NULL){ ll = rr =lr = rl = false; }
    node *LL(node *root)
    {
        node *left = root->left;
        node *l_right = left->right;
        left->right = root;
        root->left = l_right;
        root->parent = left;
        if(l_right!=NULL) l_right->parent = root;
        return left;

    }
    node *RR(node *root)
    {
        node *right = root->right;
        node *r_left = right->left;
        right->left = root;
        root->right = r_left;
        root->parent = right;
        if(r_left !=NULL ) r_left->parent = root;
        return right;
    }
    node *insertHelp(node *root,int data)
    {
        bool rc = false ; // for red-red conflict


        if(root == NULL) return new node(data);
        if(root->data > data )
        {
            root->left = insertHelp(root->left,data);
            root->left->parent = root;

            if(root != this->root)
            {
                if(root->color == 'R' && root->left->color == 'R')  rc = true;
            }
        }
        else
        {
            root->right = insertHelp(root->right,data);
            root->right->parent = root;
            if(root != this->root)
            {
                if(root->color == 'R' && root->right->color == 'R')  rc = true;
            }
        }
        if(ll)
        {
            root = LL(root);
            root->color = 'B';
            root->right->color = 'R';
            ll = false;
        }
        else if(rr)
        {
            root = RR(root);
            root->color = 'B';
            root->left->color = 'R';
            rr = false;

        }
        else if(lr)
        {
            root->left = RR(root->left);
            root->left->parent = root;
            root = LL(root);
            root->color = 'B';
            root->right->color = 'R';
            lr = false;
        }
        else if(rl)
        {
            root->right = LL(root->right);
            root->right->parent = root;
            root = RR(root);
            root->color = 'B';
            root->left->color = 'R';
            rl = false;
        }

        if(rc)
        {
            if(root->parent->left == root )
            {
                if(root->parent->right == NULL || root->parent->right->color == 'B')
                {
                    if(root->left !=NULL && root->left->color=='R') ll = true;
                    else if(root->right != NULL && root->right->color =='R' ) lr = true;
                }
                else //recolor
                {
                    root->color = 'B';
                    root->parent->right->color = 'B';
                    if(root->parent!=this->root) root->parent->color = 'R';
                }
            }
            else
            {
                if(root->parent->left==NULL || root->parent->left->color=='B')
                {
                    if(root->right !=NULL && root->right->color == 'R')  rr = true;
                    if(root->left !=NULL && root->left->color == 'R')  rl = true;
                }
                else
                {
                    root->color= 'B';
                    root->parent->left->color='B';
                    if(root->parent != this->root ) root->parent->color = 'R';
                }
            }
            rc = false;
        }
        return root;

    }
    void insertNode(int data )
    {
        if(root == NULL)
        {
            root = new node(data);
            root->color = 'B';
        }
        else root = insertHelp(root,data);
    }
    void levelOrder(node *root);

};
void RBT :: levelOrder(node *root)
{
    if(root==NULL) return ;
    queue<node*> qt;
    qt.push(root);
    while(!qt.empty())
    {
        int n = qt.size();
        for(int i=0;i<n;i++)
        {
            root = qt.front(); qt.pop();
            cout<<root->data<<"("<<root->color<<") ";
            if(root->left) qt.push(root->left);
            if(root->right) qt.push(root->right);
        }
        cout<<endl;
    }
}
int main()
{
    RBT tree;

    int n;
    while(cin>>n && n!=-1)
    {
        tree.insertNode(n);
        tree.levelOrder(tree.root);
    }
    return 0;
}
