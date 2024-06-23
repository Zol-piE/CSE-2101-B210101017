#include<iostream>
using namespace std;
class node
{
public :
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data = data;
        this->next = next;
    }
};
node *create(int arr[],int Size)
{
    node *temp,*last;
    node *head = new node(arr[0],NULL);
    last = head;
    for(int i=1;i<Size;i++)
    {
        temp = new node(arr[i],NULL);
        last->next = temp;
        last = temp;
    }
    return head;

}
void display(node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
node *Reverse(node *first)
{
    node *r=NULL,*q=NULL,*p = first;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
    return first;
}
node *rreverse(node *prev,node *curr)
{
    if(curr==NULL) return prev;
    node *next = curr->next;
    curr->next = prev;
    return rreverse(curr,next);
}
int main()
{
    int arr[]={1,2,3,4,5};
    node *first = create(arr,5);
    display(first);
    first =Reverse(first);
    display(first);
    first=rreverse(NULL,first);
    display(first);
    return 0;
}
