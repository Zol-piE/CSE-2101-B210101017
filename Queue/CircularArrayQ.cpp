#include<iostream>
using namespace std;
class Queue
{
public:
    int cap,Size,Front;
    int *arr;
    Queue(int cap)
    {
        this->cap = cap;
        Size =0;
        Front =0;
        arr = new int[cap];
    }
    bool isempty()
    {
        return (Size==0);
    }

    bool isfull()
    {
        return Size == cap;
    }
    int gearRear()
    {
        if(isempty()) return -1;
        return (Front+Size-1)%cap;
    }
    int getfront()
    {
        if(isempty()) return -1;
        return Front;
    }
    void enqueue(int value)
    {
        if(isfull())
        {
            cout<<"Overflow"<<endl;
            return;
        }
        int rear = gearRear();
        rear = (rear+1) %cap;
        arr[rear] = value;
        Size++;
    }
    int Dequeue()
    {
        if(isempty())
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int res = arr[Front];
        Front = (Front+1) % cap;
        Size --;
        return res;
    }
    void display()
    {
        int rear = gearRear()+1;
        for(int i=0;i<Size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int SizeOF()
    {
        return Size;
    }
};
int main()
{
    Queue qt(5);
    qt.enqueue(1);
    qt.enqueue(2);
    qt.enqueue(3);
    qt.enqueue(4);
    qt.enqueue(5);
    qt.display();
    qt.enqueue(6);
    cout<<"Dequeue "<<qt.Dequeue()<<endl;
    qt.enqueue(6);
    qt.display();
    qt.enqueue(6);




    return 0;
}
