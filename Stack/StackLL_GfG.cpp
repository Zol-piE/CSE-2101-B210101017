#include<iostream>
#include<time.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class MyStack
{
    public:
    node *top;
    int Size;
    MyStack()
    {
        top=NULL;
        Size=0;
    }
    void push(int value)
    {
        node *temp = new node();
        temp->data = value;
        temp->next = top;
        top = temp;
        Size++;
    }
    int pop()
    {
        if(top==NULL)
        {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        int res = top->data;
        top=top->next;
        Size--;
        return res;
    }
    int SizeOf() { return Size; }
    bool isEmpty()
    {
        return top==NULL;
    }
    int peek()
    {
        return top->data;
    }
    void display()
    {
        node *ptr = top;
        while(ptr!=NULL)
        {
            cout<<"Element : "<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }
};

int main()
{
    MyStack *st = new MyStack();
    srand(time(0));
    for(int i=0;i<5;i++)
    {
        st->push(rand()%10);
    }
    st->display();
    cout<<st->SizeOf()<<endl;
    cout<<st->isEmpty()<<endl;
    cout<<st->peek()<<endl;
    return 0;
}
