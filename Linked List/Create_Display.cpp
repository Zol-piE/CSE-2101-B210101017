#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first;
void create(int arr[],int Size)
{
    first = new Node;
    struct Node *t,*last;
    first->data = arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<Size;i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next =t ;
        last = t;
    }
}
void Display(struct Node *p)
{

    if(p!=NULL)
    {
        cout<<p->data<< " ";
        Display(p->next);
//        cout<<p->data<< " ";
    }

}
int Count(struct Node *p)
{
    int x =0;
    if(p!=NULL)
    {
        x=Count(p->next);
        return x+1;
    }
    else return x;
}
int Sum(struct Node *p)
{
    if(p==NULL) return 0;
    return Sum(p->next)+p->data;
}
int FindMax(struct Node *p)
{
    int x;
    if(p==NULL) return INT_MIN;
    x  = FindMax(p->next);
    if(x > p->data) return x;
    else return p->data;
}
bool Search(struct Node *p,int key)
{
    if(p==NULL) return false;

    if(p->data == key ) return true;

    return Search(p->next,key);
}
Node *LSearch(struct Node *p,int key)
{
    Node *q= NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next = p->next;
            p->next = first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
int main()
{
    int arr[]={2,3,55,4,5,6};

    create(arr,6);
    Display(first);
    cout<<endl;
    cout<<Count(first)<<endl;
    cout<<Sum(first)<<endl;
    cout<<FindMax(first)<<endl;
    cout<<Search(first,100)<<endl;
    if(LSearch(first,55)!= NULL) cout<<"Value is Found "<<endl;
        else cout<<"Not "<<endl;
    Display(first);
    return 0;
}
