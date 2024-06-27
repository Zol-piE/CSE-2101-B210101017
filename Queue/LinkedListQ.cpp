#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data=data;
        this->next=next;
    }
};
class Queue
{
public:
    node *Front,*rear;
    Queue() { Front = NULL ; rear = NULL; }
    void enqueue(int val)
    {
        node *temp = new node(val,NULL);
        if(Front==NULL)
        {
            Front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear=temp;
        }
    }
    int dequeue()
    {

        if(Front==NULL)
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int temp = Front->data;
        Front = Front->next;
        if(Front == NULL)
        {
            Front = rear= NULL;
        }
        return temp;
    }
};
int main()
{
    Queue qt;
    qt.enqueue(10);
    qt.enqueue(11);
    qt.enqueue(12);
    qt.enqueue(13);
    for(int i=0;i<3;i++) cout<<qt.dequeue()<<endl;
    qt.enqueue(14);
    qt.enqueue(15);
    qt.enqueue(17);


    for(int i=0;i<3;i++) cout<<qt.dequeue()<<endl;

    return 0;
}
