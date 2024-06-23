#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int d,node *n)
    {
        data = d;
        next = n;
    }
} *first ;
int Count(node *p)
{
    int x=0;
    while(p!=NULL)
    {
        x++;
        p=p->next;
    }
    return x;
}
void inserting(int pos,int value)
{
    if(first==NULL && pos > 0)
    {
        cout<<"NO Node "<<endl;
        return;
    }
    if(pos==0 && first == NULL)
    {
        first = new node(value,NULL);
        return;
    }
    int len = Count(first);
    if(pos>=0 && pos<len)
    {
        node *temp = new node(value,NULL);
        if(pos==0)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            node *p = first;
            for(int i =0;i<pos-1 && p ;i++)
            {
                p=p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
    }
}
void Display(node *p)
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
    inserting(0,20);
    Display(first);
    inserting(0,30);
    inserting(1,55);
    inserting(2,88);
    Display(first);
    return 0;
}
