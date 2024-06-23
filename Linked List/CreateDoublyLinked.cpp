#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(node *prev,int data,node *next)
    {
        this->data = data;
        this->next = next;
        this->prev=prev;
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
    return head;

}
void display(node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;

    }
    cout<<endl;
}
void reverseL(node *&head)
{
    node *p= head, *q=NULL;
    if(head==NULL || head->next == head ) return ;
    else
    {
        while(p!=NULL)
        {
            q=p;
            swap(p->next,p->prev);
            p = p->prev;
        }
        head= q;
//        return head;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    node *first = create(arr,5);
    display(first);
    reverseL(first);
    display(first);
    return 0;
}
