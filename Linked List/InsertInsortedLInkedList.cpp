#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data=data;
        this->next =next;
    }
}*first=NULL,*last=NULL;
void insertLast(int x)
{
    node *temp = new node(x,NULL);
    if(!(first && last) )
    {
        first = last = temp;
    }
    else{
        last->next = temp;
        last = temp;
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
void insertSort(int x)
{

    if(first==NULL)
    {
        first = new node(x,NULL);

    }
    else{

        node *last=first,*prev;
        node *temp = new node(x,NULL);
        while(last && last->data<x)
        {
            prev = last ;
            last =last->next;
        }
        if(last==first)
        {
            temp->next = first;
            first = temp;

        }
        else
        {
            temp->next = last;
            prev->next =temp;
        }
    }

}
int main()
{
    for(int i=5;i<30;i=i+5)
    {
        insertLast(i);
    }
    Display(first);
    insertSort(16);
    Display(first);
    insertSort(33);
    Display(first);
    insertSort(1);
    Display(first);

    return 0;
}
