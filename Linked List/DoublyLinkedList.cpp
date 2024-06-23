#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(node *p,int d,node *n)
    {
        data = d;
        prev = p;
        next = n;
    }
};
node *create(int arr[],int Size)
{
    node *temp,*last;
    node *head = new node(NULL,arr[0],NULL);
    last = head;
    for(int i=1;i<Size;i++)
    {
        temp = new node(last,arr[i],NULL);
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
int main()
{
    int arr[]={1,2,3,4,5};
    node *first = create(arr,5);
    display(first);
    return 0;
}
