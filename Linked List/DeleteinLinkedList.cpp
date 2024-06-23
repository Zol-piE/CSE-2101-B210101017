#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data=data;
        this->next=next;
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
    if(p== NULL) return;
    cout<<p->data<<" ";
    return display(p->next);
}
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
node *Delete(node *first,int pos)
{

    if(pos<0 || pos > Count(first) ) return first;
    if(pos==0)
    {
        node *last = first;
        first = first->next;
        delete last;
        return first;
    }
    else
    {
        node *prev = NULL;
        node *last = first;
        for(int i=0;i<pos && last;i++)
        {
            prev = last;
            last = last->next;
        }
        prev->next = last->next;
        delete last;
    }
        return first;
}
int main()
{
    int arr[] = {1,2,3,4,5},brr[]={9,8,7,6,4};
    node *head =create(arr,5);
    display(head); cout<<endl;
    node *first = create(brr,5);

    first = Delete(first,0);
    display(first); cout<<endl;
    first = Delete(first,2);
    display(first);
    cout<<endl;
    return 0;
}
