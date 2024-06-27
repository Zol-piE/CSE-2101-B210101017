#include<iostream>
using namespace std;
class Deque
{
public:
    int Size,cap;
    int *arr;
    Deque(int cap)
    {
        this->cap = cap;
        Size =0;
        arr = new int[cap];
    }
    bool isEmpty()
    {
        return Size == 0;
    }
    bool isFull()
    {
        return (Size==cap);
    }
    void insertFront(int val)
    {
        if(isFull())
        {
            cout<<"Overflow"<<endl;
            return;
        }
        for(int i = Size-1; i>=0; i--) arr[i+1] = arr[i];
        arr[0] = val;
        Size++;
    }
    void insertRear(int val)
    {
        if(isFull())
        {
            cout<<"Overflow"<<endl;
            return;
        }
        arr[Size++] = val;
    }
    int deleteFront()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return -1;
        }

        int res = arr[0];

        for(int i=0;i<Size-1;i++) arr[i] = arr[i+1];

        Size--;

        return res;
    }
    int deleteRear()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return -1;
        }

        return arr[Size];
    }
};
int main()
{
    Deque dq(5);
    dq.insertFront(1);
    dq.insertFront(3);
    dq.insertRear(0);
    cout<<dq.deleteRear()<<endl;
    cout<<dq.deleteFront()<<endl;
    dq.insertFront(5);
    dq.insertFront(7);
    dq.insertFront(9);
    dq.insertRear(4);

    return 0;
}
