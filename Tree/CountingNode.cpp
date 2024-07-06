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
int countNode(node *t)
{
	if(t != NULL)
	{
		int x = countNode(t->left);
		int y = countNode(t->right);

		return x+y+1;
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
	cout<<"Count Node "<<countNode(obj->root)<<endl;

	return 0;
}
