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
        prev = NULL;
        next = NULL;
    }
    friend class doubly;
};
class doubly
{
public:
    node *head;
    node *last;
    int Size=0;
    doubly()
    {
        head = NULL;
        last = NULL;
    }
    void addfront(int x)
    {
        node *temp = new node(x);
        if(head == NULL)
        {
            head = last = temp;
            /* temp ->next = head;
               head = temp;
               last = temp;
            */
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void addlast(int x)
    {
        node *temp = new node(x);
        if(head == NULL)
        {
            head = last = temp;
        }
        else
        {
            last ->next = temp;
            temp->prev = last;
            last = temp;
        }
    }

    bool isEmpty() { return (head==NULL ); }

};

void display(doubly *ll)
{
    node *ptr = ll->head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main()
{
    doubly *ll = new doubly();
    for(int i=1;i<=5;i++)
    {
        ll->addfront(i*2);
    }
    display(ll);
    for(int i=1;i<=5;i++)
    {
        ll->addlast(i);
    }
    display(ll);
    return 0;
}
