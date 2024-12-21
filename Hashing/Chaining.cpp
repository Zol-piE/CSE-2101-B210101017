#include<iostream>
#include<vector>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data): data(data),next(NULL){}

};
class Hashing
{
public:
    vector<node*> vect;
    int Hashsize;
    Hashing(int n) : Hashsize(n), vect(Hashsize,NULL) {}
    int HashFun(int data)
    {
        return data%Hashsize;
    }
    node *insertIntoSortedList(node *root,int data);
    void insertHash(int data);
    void print();
};
node* Hashing :: insertIntoSortedList(node *root,int data)
{
    node *temp = new node(data);
    if(root==NULL)
    {
        return root = temp;
    }
    node *p = root,*q=NULL;
    while(p!=NULL&&p->data < data)
    {
        q = p;
        p = p->next;
    }
    temp->next = p;
    if(q==NULL)
    {
        root = temp;
    }
    else
    {
        q->next = temp;
    }
    return root;
}
void Hashing :: insertHash(int data)
{
    int index = HashFun(data);
    vect[index] = insertIntoSortedList(vect[index],data);
}
void Hashing :: print()
{
    for(int i=0;i<Hashsize;i++)
    {
        cout<<"Index " <<i<<"-- ";
        node *temp = vect[i];
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    Hashing arr(10);
    arr.insertHash(16);
    arr.insertHash(12);
    arr.insertHash(25);
    arr.insertHash(39);
    arr.insertHash(6);
    arr.insertHash(122);
    arr.insertHash(5);
    arr.insertHash(68);
    arr.insertHash(75);
    arr.print();
    return 0;
}
