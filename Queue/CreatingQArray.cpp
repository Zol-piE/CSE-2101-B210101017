#include<iostream>
using namespace std;
class Queue
{
    public:
    int Front,cap,rear;
    int *arr;
    Queue(int cap)
    {
        this->cap = cap;
        Front = 0;
        rear = 0;
        arr = new int[cap];
    }
    ~Queue()
    {
        delete []arr;
    }
    bool isFull()
    {
        return (cap==rear);
    }
    bool isEmpty()
    {
        return (rear==0);
    }
    void enqueue(int value)
    {
        if(isFull())
        {
            cout<<"Is Full"<<endl;
            return;
        }
        arr[rear++] = value;
    }
    int Dequeue()
    {
        if(isEmpty())
        {
            cout<<"is Empty"<<endl;
            return INT_MIN;
        }
        int res = arr[Front];

        for(int i=Front;i<rear-1;i++)
        {
            arr[i]=arr[i+1];
        }
        rear--;
        return res;
    }
    void display()
    {
        if(isEmpty()) { cout<<"EMPTY"<<endl; return ; }
        for(int i=0;i<rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Queue qt(5);
    qt.enqueue(1);
    qt.enqueue(2);
    qt.enqueue(2);
    qt.enqueue(2);
    qt.enqueue(2);
    qt.display();
    cout<<"POP "<<qt.Dequeue()<<endl;
    qt.display();
    qt.enqueue(2);
    cout<<"POP "<<qt.Dequeue()<<endl;
    qt.display();
    cout<<"POP "<<qt.Dequeue()<<endl;
    cout<<"POP "<<qt.Dequeue()<<endl;
    cout<<"POP "<<qt.Dequeue()<<endl;
    cout<<"POP "<<qt.Dequeue()<<endl;
    cout<<"POP "<<qt.Dequeue()<<endl;
    cout<<"POP "<<qt.Dequeue()<<endl;
    cout<<"POP "<<qt.Dequeue()<<endl;


    return 0;
}
