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
int main()
{
    for(int i=0;i<10;i++)
    {
        insertLast(i);
    }
    insertSort(16);
    Display(first);

    return 0;
}
