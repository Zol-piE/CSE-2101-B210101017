#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(node *p,int d,node *q)
    {
        prev = p;
        data= d;
        next =q;
    }

};
node *create(int arr[],int n)
{
    node *temp,*last;
    node *head = new node(NULL,arr[0],NULL);
    last = head;
    for(int i=1;i<n;i++)
    {
        temp = new node(last,arr[i],NULL);
        last->next = temp;
        last = temp;
    }
    last->next = head;
    head->prev = last;
    return head;
}
void display(node *head)
{
    node *p = head;
    do{
        cout<<p->data<< " ";
        p = p->next;
    }while(p!=head);
    cout<<endl;
}
void insertL(node *&head,int value,int pos)
{

    if(pos==0)
    {
        node *last = head->prev;
        node *temp= new node(last,value,head);
        last->next = temp;
        head->prev = temp;
        head = temp;
    }
    else
    {
        node *prev = head;
        for(int i=0;i<pos-1;i++) prev = prev ->next;
        node *next = prev->next;
        node *temp = new node(prev,value,next);
        prev->next = temp;
        next->prev= temp;

    }
}
int main()
{
    int arr[] = {1,2,3,4,5};
    node *head = create(arr,5);
    display(head);
    for(int i=0 ;i<12;i+=2 )
    {
        insertL(head,99,i);
    display(head);
    }
    return 0;
}
