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
		left=  NULL;
		right = NULL;
		this->data = data;
	}
};
class tree
{
public:
	node *root;
	tree()
	{
		root = NULL;
	}
	void create()
	{
		int x ;
		queue<node*>qt;
		cout<<"Enter Root Node ";
		cin>>x; cout<<endl;
		root = new node(x);
		qt.push(root);
		while(!qt.empty())
		{
			node *ptr = qt.front();qt.pop();
			cout<<ptr->data<<" Node Left Child Or -1"; cin>>x; cout<<endl;
			if(ptr->left == NULL && x!=-1)
			{
				node *temp = new node(x);
				ptr->left = temp;
				qt.push(temp);
			}
			cout<<ptr->data<<" Node right Child Or -1"; cin>>x; cout<<endl;
			if(ptr->right == NULL && x!=-1)
			{
				node *temp = new node(x);
				ptr->right = temp;
				qt.push(temp);
			}

		}
	}
};
int Height(node *p)
{
	if(p!=NULL)
	{
		int x = Height(p->left);
		int y = Height(p->right);
		if(x>y) return x+1;
		else return y+1;
	}
	return 0;
}
int sumOfNodes(node *p)
{
    if(p!=NULL)
    {
        int x = sumOfNodes(p->left);
        int y = sumOfNodes(p->right);
        return x+y+ p->data;
    }
    return 0;
}
void postorder(node *p)
{
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<" ";
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	tree *obj = new tree();
	obj->create();
	cout<<"postorder : ";
	postorder(obj->root);cout<<endl;

	cout<<"Height Of Tree : "<<Height(obj->root)<<endl;
	cout<<"Sum of Nodes : "<<sumOfNodes(obj->root)<<endl; 
	return 0;
}
