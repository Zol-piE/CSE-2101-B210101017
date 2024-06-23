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
node *create(int arr[],int Size)
{
    node *temp,*last;
    node *first = new node(arr[0],NULL);
    last = first;
    for(int i=1;i<Size;i++)
    {
        temp = new node(arr[i],NULL);
        last -> next = temp;
        last = temp;
    }
    last->next = first;
    return first;
}
void display(node *head)
{
    node *p =head;
    do
    {
        cout<< p -> data<< " ";
        p = p->next;
    }while(p!=head);
    cout<<endl;
}
int  Count(node *head)
{
    int x=0;
    node *p = head;
    do
    {
        x++;
        p=p->next;

    }while(p!=head);
    return x;
}
void Insert(node *&head,int value,int pos)
{
    node *p = head;

    if(pos==0)
    {

        while(p->next != head ) p = p->next;
        node *temp = new node(value,p->next);
        p->next = temp;
        head = temp;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p =p->next;
        }
        node *temp = new node(value,p->next);
        p->next = temp;
    }
}
void Delete(node *&head,int pos)
{
    int length = Count(head);
    node *p= head;
    if(pos< 0 || pos>length) return;
    if(pos==0)
    {
        while(p->next !=head) p = p->next;
        if(p==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            node *q = head;
            head = head->next;
            p->next = head;
            delete q;
            q = NULL;
        }
    }
    else
    {
        for(int i=0;i<pos-2;i++) p = p->next;

        node *q = p->next;
        cout<<p->data<<" "<<q->data<<endl;
        p->next = q->next;
        delete q;
        q=NULL;
    }
}
int main()
{
    int arr[]= {1,2,3,4,5};
    node *first = create(arr,5);
    cout<<"Creating " <<endl;
    display(first);
    cout<<Count(first)<<endl;
    cout<<"Inserting "<<endl;
    Insert(first,66,3);
    display(first);
    cout<<Count(first)<<endl;
    cout<<"Delete "<<endl;
    Delete(first,0);
    display(first);
    cout<<Count(first)<<endl;
    cout<<"Delete "<<endl;
    Delete(first,2);
    display(first);
    cout<<Count(first)<<endl;
    return 0;
}
