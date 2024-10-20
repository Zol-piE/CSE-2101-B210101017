#include <iostream>
#include <queue>
using namespace std;

class RBT
{
public:
    bool ll, rr, lr, rl;

    class node
    {
    public:
        int data;
        node *left;
        node *right;
        node *parent;
        char color;

        node(int data) : data(data), left(NULL), right(NULL), parent(NULL), color('R') {}
    };

    node *root;

    node *predecessor(node *root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }

    node *successor(node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    int height(node *root)
    {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    node *rightRot(node *root)
    {
        node *left = root->left;
        node *lright = left->right;
        left->right = root;
        root->left = lright;
        root->parent = left;
        if (lright != NULL)
            lright->parent = root;
        return left;
    }

    node *leftRot(node *root)
    {
        node *right = root->right;
        node *rleft = right->left;
        right->left = root;
        root->right = rleft;
        root->parent = right;
        if (rleft != NULL)
            rleft->parent = root;
        return right;
    }

    node *insertHelp(node *root, int data)
    {
        bool rc = false;
        if (root == NULL)
            return new node(data);

        if (root->data > data)
        {
            root->left = insertHelp(root->left, data);
            root->left->parent = root;
            if (root != this->root)
            {
                if (root->color == 'R' && root->left->color == 'R')
                    rc = true;
            }
        }
        else
        {
            root->right = insertHelp(root->right, data);
            root->right->parent = root;
            if (root != this->root)
            {
                if (root->color == 'R' && root->right->color == 'R')
                    rc = true;
            }
        }

        if (ll)
        {
            root = rightRot(root);
            root->color = 'B';
            root->right->color = 'R';
            ll = false;

        }
        else if (rr)
        {
            root = leftRot(root);
            root->color = 'B';
            root->left->color = 'R';
            rr = false;
        }
        else if (lr)
        {
            root->left = leftRot(root->left);
            root->left->parent = root;
            root = rightRot(root);
            root->color = 'B';
            root->right->color = 'R';
            lr = false;
        }
        else if (rl)
        {
            root->right = rightRot(root->right);
            root->right->parent = root;
            root = leftRot(root);
            root->left->color = 'R';
            root->color = 'B';
            rl = false;
        }

        if (rc)
        {
            if (root->parent->left == root)
            {
                if (root->parent->right == NULL || root->parent->right->color == 'B')
                {
                    if (root->left != NULL && root->left->color == 'R')
                        ll = true;
                    else if (root->right != NULL && root->right->color == 'R')
                        lr = true;
                }
                else
                {
                    root->color = 'B';
                    root->parent->right->color = 'B';
                    if (root->parent != this->root)
                        root->parent->color = 'R';
                }
            }
            else
            {
                if (root->parent->left == NULL || root->parent->left->color == 'B')
                {
                    if (root->right != NULL && root->right->color == 'R')
                        rr = true;
                    else if (root->left != NULL && root->left->color == 'R')
                        rl = true;
                }
                else
                {
                    root->color = 'B';
                    root->parent->left->color = 'B';
                    if (root->parent != this->root)
                        root->parent->color = 'R';
                }
            }
            rc = false;
        }
        return root;
    }

    RBT() : root(NULL)
    {
        ll = rr = lr = rl = false;
    }

    void insertNode(int data)
    {
        if (root == NULL)
        {
            root = new node(data);
            root->color = 'B';
        }
        else
            root = insertHelp(root, data);
    }

    void levelOrder(node *root);

    node *searchNode(node *root, int data)
    {
        if (root == NULL || root->data == data)
            return root;
        if (root->data > data)
            return searchNode(root->left, data);
        else
            return searchNode(root->right, data);
    }

    void transplant(node *u, node *v)
    {
        if (u->parent == NULL)
        {
            this->root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else if (u == u->parent->right)
        {
            u->parent->right = v;
        }
        if (v != NULL)
        {
            v->parent = u->parent;
        }
    }

    node *replaceNode(node *v)
    {
        if(v->left !=NULL && v->right !=NULL)
        {
            return successor(v->right);
        }

        if(v->left ==NULL && v->right ==NULL) return NULL;

        if(v->left==NULL) return v->right;
        else return v->left;

    }
    node *Sibling(node *x)
    {
        if(x->parent == NULL)
        {
            return NULL;
        }
        if(x->parent->left == x) return x->parent->right;
        else return x->parent->left;
    }
    void fixTree(node *x)
    {
        if(x==this->root) return ;

        node *parent = x->parent;
        node *gparent = parent->parent;
        node *s = Sibling(x);
        if(s==NULL) fixTree(parent); //DB to parent;
        else
        {
            if(s->color =='R')
            {
                s->color = 'B';
                parent->color = 'R';
                if(parent->right==s) //DB is on left
                {
                    s = leftRot(parent);
                    s->parent = gparent;
                    if(gparent!=NULL){
                    if(gparent->left == parent) gparent->left = s;
                    else gparent->right = s;
                    }
                    else this->root = s;

                }
                else
                {
                    s = rightRot(parent);
                    s->parent = gparent;
                    if(gparent!=NULL){
                    if(gparent->left == parent) gparent->left = s;
                    else gparent->right = s;
                    }
                    else this->root = s;
                }
                fixTree(x);
            }
            else
            {
                if((s->left!=NULL && s->left->color == 'R') || (s->right!=NULL && s->right->color == 'R'))
                {
                    if(s->left !=NULL && s->left->color=='R')
                    {

                        if(parent->left==s)//far child is left
                        {
                            s->left->color = s->color;
                            s->color = parent->color;
                            node *temp = rightRot(parent);
                            temp->parent = gparent;
                            if(gparent!=NULL){
                            if(gparent->left == parent) gparent->left = temp;
                            else gparent->right = temp;
                            }
                            else this->root = temp;
                        }
                        else
                        {
                            s->left->color = parent->color;
                            node *temp = rightRot(s);
                            temp->parent = parent;
                            parent->right = temp;
                            temp = leftRot(parent);
                            temp->parent = gparent;
                            if(gparent!=NULL){
                            if(gparent->left == parent) gparent->left = temp;
                            else gparent->right = temp;
                            } else this->root = temp;
                        }
                    }
                    else
                    {
                        if(parent->left ==s)
                        {
                            s->right->color = parent->color;
                            node *temp = leftRot(s);
                            temp->parent = parent;
                            parent->left = temp;
                            temp = rightRot(parent);
                            temp->parent = gparent;
                            if(gparent !=NULL){
                            if(gparent->left == parent) gparent->left = temp;
                            else gparent->right = temp;
                            } else this->root = temp;
                        }
                        else
                        {
                            s->right->color = s->color;
                            s->color = parent->color;
                            node *temp = leftRot(parent);
                            temp->parent = gparent;
                            if(gparent!=NULL){
                            if(gparent->left == parent) gparent->left = temp;
                            else gparent->right = temp;
                            } else this->root = temp;

                        }
                    }
                    parent->color = 'B';
                }
                else
                {
                    s->color = 'R';
                    if(parent->color =='B') fixTree(parent);
                    else parent->color = 'B';
                }
            }
        }

    }
    void deleteHelp(node *v)
    {
        node *u = replaceNode(v);
        bool blackH = ((u==NULL || u->color == 'B') && v->color=='B');
        node *vparent = v->parent;
        if(u==NULL)
        {
            if(v==this->root)
            {
                root = NULL;
                return;
            }
            if(blackH)
            {
                fixTree(v); // v is leaf node
            }
            else
            {
                if(Sibling(v)!=NULL)
                {
                    Sibling(v)->color = 'R';
                }
            }
            if(v->parent->left==v) v->parent->left= NULL;
            else v->parent->right = NULL;
            delete v;
            return ;
        }
        if(v->left ==NULL || v->right ==NULL)//one child
        {
            if(v == this->root)
            {
                v->data = u->data;
                v->left= v->right = NULL;
                delete u;
            }
            transplant(v,u);
            delete v;
            if(blackH) fixTree(u);
            else
            {
                u->color = 'B';
            }
            return;
        }
        //v has two children
        swap(v->data,u->data);
        deleteHelp(u);

    }
    void deleteNode(int data)
    {
        node *v = searchNode(this->root,data);
        if(v==NULL)
        {
            cout<<"Not Found"<<endl;
            return;
        }
        deleteHelp(v);
    }


};

void RBT::levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        int n = qt.size();
        for (int i = 0; i < n; i++)
        {
            root = qt.front();
            qt.pop();
            cout << root->data << "(" << root->color << ")" << " ";
            if (root->left)
                qt.push(root->left);
            if (root->right)
                qt.push(root->right);
        }
        cout << endl;
    }
}

int main()
{
    RBT tree;
//    freopen("input.txt","r",stdin);
    int n;
    while(cin>>n && n!=-1)
    {
        tree.insertNode(n);
        tree.levelOrder(tree.root);
    }
    while(cin>>n && n!=-1)
    {
        cout<<"After Deleting "<<n<<" "<<endl;
        tree.deleteNode(n);
        tree.levelOrder(tree.root);
    }
    return 0;
}
