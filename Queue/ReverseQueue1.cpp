#include<iostream>
using namespace std;
class node
{
public:

    int data;
    node *next;
    node(int data)
    {
        this->data =data;
        next=NULL;
    }
};
class Queue
{
public:

    node *Front,*Rear;
    int Size;
    Queue()
    {
        Front = NULL;
        Rear = NULL;

    }
    void push(int x)
    {
        node *temp = new node(x);
        if(Front==NULL)
        {
            Front = temp;
            Rear = temp;
            return ;
        }

        Rear->next = temp;
        Rear = temp;

    }
    int pop()
    {
        if(Front==NULL)
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int res = Front->data;
        Front = Front->next;
        if(Front==NULL)
        {
            Rear = Front = NULL;
        }
        return res;
    }
    bool isEmpty()
    {
        return (Front==NULL);
    }
};
void Display(Queue qt)
{
    while(!qt.isEmpty())
    {
        cout<<qt.pop()<<" ";

    }
    cout<<endl;
}
void Reverse(Queue &qt)
{
    if(qt.isEmpty()) return;

    int x = qt.pop();

    Reverse(qt);

    qt.push(x);
}
int main()
{
    Queue qt;
    qt.push(1);
    qt.push(2);
    qt.push(3);
    qt.push(4);
    Display(qt);
    Reverse(qt);
    Display(qt);
    return 0;
}
