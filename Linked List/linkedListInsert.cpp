#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
} *first;
void create(int arr[],int Size)
{
    node *t,*last;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i<Size;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t ;
    }
}
void Display(node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<< " ";
        p=p->next;
    }
}
int main()
{
    int arr[] = {1,4,6,8,4};
    int Size = sizeof(arr)/ sizeof(arr[0]);
    create(arr,Size);
    Display(first);

    return 0;
}
