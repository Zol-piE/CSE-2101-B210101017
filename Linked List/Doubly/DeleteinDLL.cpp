#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        this->data = x;
        next = NULL;
        prev = NULL;
    }
};
class doubly
{
public:
    node *head;
    doubly()
    {
        head = NULL;
    }
    void insertfirst(int x)
    {
        node *temp = new node(x);
        if(head ==NULL)
        {
            head = temp ;
            return ;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    int removefirst()
    {
        if(head==NULL ) return -1;
        int res = head->data;
        head = head ->next;
        if(head!=NULL)
        {
            head->prev = NULL;
        }
        return res;
    }
    int removepos(int pos)
    {
        if(head == NULL) return -1;
        if(pos==1) return removefirst();

        node *ptr = head;
        for(int i=1;i<pos;i++)
        {

            ptr=ptr->next;
        }
        int res = ptr->data;
        (ptr->prev)->next = ptr->next;
        if(ptr->next!=NULL)
        {
            (ptr->next)->prev = ptr->prev;
        }
        return res;

    }
    void display()
    {
        node *ptr = head;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};
int main()
{
    doubly *ll = new doubly();
    for(int i=5;i>=1;i--) ll->insertfirst(i);
    ll->display();
    ll->removepos(2);
    ll->display();
    return 0;
}
