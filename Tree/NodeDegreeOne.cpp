#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	int data;
	node * left;
	node *right;
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
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
		int x;
		queue<node*>qt;
		cout<<"Enter Root node ";cin>>x; cout<<endl;
		root = new node(x);
		qt.push(root);
		while(!qt.empty())
		{

			node *ptr = qt.front();
			qt.pop();
			cout<<ptr->data<<" Enter left Node Or -1 "; cin>>x;cout<<endl;
			if(ptr->left == NULL && x!=-1)
			{
				node *temp = new node(x);
				ptr->left = temp;
				qt.push(temp);
			}
			cout<<ptr->data<<" Enter Right Node Or -1 "; cin>>x;cout<<endl;
			if(ptr->right==NULL && x!=-1)
			{
				node *temp = new node(x);
				ptr->right = temp;
				qt.push(temp);
			}
		}
	}
};
void postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->data<<" ";
	}
}
int nodeDegreeOne(node *ptr)
{
	if(ptr!=NULL)
	{
		int x = nodeDegreeOne(ptr->left);
		int y = nodeDegreeOne(ptr->right);
		if(ptr->left!=NULL ^ ptr->right!=NULL)
		{
			return x+y+1;
		}
		else return x+y;
	}
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	tree *obj = new tree();
	obj->create();
	postorder(obj->root);cout<<endl;
	cout<<nodeDegreeOne(obj->root)<<endl;
	return 0;
}