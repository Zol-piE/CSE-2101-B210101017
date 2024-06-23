#include<iostream>
using namespace std;
class node{
public:
    int Data;
    node *next;
    node(int data,node *next)
    {
        this->Data = data;
        this->next = next;
    }
};
int Count(node *p)
{
    if(p==NULL) return 0;
    return Count(p->next)+1;
}
node *create(int arr[],int Size)
{
    node *temp,*last;
    node *first = new node(arr[0],NULL);

    last=first;
    for(int i=1;i<Size;i++)
    {
        temp = new node(arr[i],NULL);
        last->next = temp;
        last = temp;
    }
    return first;
}
void Display(node *p)
{
    if(p==NULL) return;
    cout<<p->Data<<" ";
    return Display(p->next);
}
node *Insert(node *first,node *temp,int pos)
{
   int len = Count(first);
   if( pos< 0 ||pos >len) return first;
   if(pos==0)
   {
       temp->next = first;
       first = temp;
   }
   else
   {

       node *p = first;
       for(int i=0;i<pos-1 && p;i++)
       {
           p=p->next;
       }
       if(p!=NULL)
       {
           temp->next = p->next;
           p->next=temp;
       }

   }
   return first;
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    node *first = create(arr,6);
    node *temp = new node(55,NULL);
    Display(first);
    cout<<endl;
    first = Insert(first,temp,0);
    Display(first); cout<<endl;
    node *temp2 = new node(1020,NULL);
    first = Insert(first,temp2,7);
    Display(first); cout<<endl;

    return 0;
}
