#include<iostream>
using namespace std;
class Stack
{
public:
    int data;
    int Size=0;
    Stack *next;
}*top=NULL;
void push(int value)
{
    Stack *node = new Stack();
    node->data = value;
    node->next = top;
    node->Size = (top==NULL) ? 1 : top->Size+1;
    top=node;

}
int pop()
{
    Stack *temp=top;
    int res = top->data;
    top=top->next;
    delete temp;
    return res;

}
int stackTop()
{
    return top->data;
}
void Display()
{
    Stack *ptr=top;
    while(ptr!=NULL)
    {
        cout<<"Element " <<ptr->data<<" Size "<<ptr->Size<<endl;
        ptr=ptr->next;
    }
}
int main()
{
    for(int i=1;i<=5;i++)
    {
        push(rand()%10);
    }
    Display();
    for(int i=0;i<5;i++)
    {
        cout<<top->Size<<" "<<pop()<<endl;
    }
    return 0;
}
