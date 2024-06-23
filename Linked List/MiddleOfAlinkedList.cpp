#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    node(int data,node *next)
    {
        this->data = data;
        this->next = next;
    }
};
node *create(int arr[],int Size)
{
    node *temp=NULL,*last=NULL;
    node *first = new node(arr[0],NULL);
    last = first;
    for(int i=1;i<Size;i++)
    {
        temp = new node(arr[i],NULL);
        last->next = temp;
        last = temp;
    }
    last = NULL;
    return first;
}
void display(node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int middle(node *head)
{
    node *p,*q;
    p=q=head;
    while(p)
    {
        p=p->next;
        if(p)q=q->next;

        if(p) p=p->next;
    }
    return q->data;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    node *first = create(arr,9);
    display(first);
    cout<<middle(first)<<endl;
}
