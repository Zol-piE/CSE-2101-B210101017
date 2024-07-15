#include <iostream>
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
}
void create(node *temp,int data)
{
	if(temp==NULL)
	{
		temp = new node(data);
		return temp;
	}
	else 
	{
		temp->left = create(temp->left,info);
		temp->right = create(temp->right,info);
	}
	return temp;

}
int main()
{
	return 0;
}