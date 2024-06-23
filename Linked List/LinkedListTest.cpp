#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data = data;
        this->next = next;
    }
};
node *create(int arr[],int len)
{
    node *temp,*last;
    node *first = new node(arr[0],NULL);
    last = first;

    for(int i=1;i<len;i++)
    {
        temp = new node(arr[i],NULL);
        last->next = temp;
        last = temp;
    }
    return first;
}
void display(node *p)
{
    if(p==NULL) return;
    display(p->next);
    cout<<p->data<<" ";
}

void InsertLast(node *&head,node *&last,int value)
{
    node *temp = new node(value,NULL);
    if(!(head&&last))
    {
        head = last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}
node *InsertL(node *&first,int pos , int value)
{
    if(pos==0)
    {
        node *temp = new node(value,first);
        first = temp;
        return first;
    }
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);

    node *head = create(arr,len);
    display(head);cout<<endl;
    node *first =NULL,*last =NULL ;
    InsertLast(first,last,10);
    InsertLast(first,last,20);
    InsertLast(first,last,30);
    InsertLast(first,last,40);
    first=InsertL(first,0,100);
    display(first);cout<<endl;
    return 0;
}
