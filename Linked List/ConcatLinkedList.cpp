#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data=data;
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
        last->next = temp;
        last = temp;
    }
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
void concat(node *&first,node *&second)
{
    node *p = first;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next = second;
    second=NULL;

}
node *Merge(node *f,node *s)
{
    node *t=NULL,*l=NULL;
    if(f->data<s->data)
    {
        t = l = f;
        f = f->next;
        l->next = NULL;
    }
    else
    {
        t = l =s ;
        s = s->next;
        l->next=NULL;
    }
    while(f&&s)
    {
        if(f->data<s->data)
        {
            l->next = f;
            l = f;
            f= f->next;
            l->next=NULL;

        }
        else
        {
            l->next = s;
            l = s;
            s= s->next;
            l->next=NULL;
        }

    }
    if(f) l->next = f;
    if(s) l->next = s;
    return t;
}
bool isloop(node *head)
{
    node *p=NULL,*q=NULL;
    p=q=head;
    do
    {
        p = p->next;
        q = q->next;
        q = (q) ? q->next : NULL;

    }while( p && q && p!=q);
    if(p==q) return true;
    else return false;
}
int main()

{
    int arr[]={1,2,3,4,5};
    node *first = create(arr,5);
    node *t1,*t2;
    t1=first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1; // first is a lOOp
    cout<<isloop(first)<<endl;


    return 0;
}
