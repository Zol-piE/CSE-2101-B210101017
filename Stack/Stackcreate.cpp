#include<iostream>
using namespace std;
struct node
{
    int *arr;
    int Capacity;
    int top;
    node(int cap)
    {
        arr = new int[cap];
        Capacity = cap;
        top=-1;
    }
    void push(int value)
    {
        if(top==(Capacity-1))
        {
            cout<<"Stack is Full"<<endl;
            return;
        }
        top++;
        arr[top]=value;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Is Empty"<<endl;
            return INT_MIN;
        }
        int val = arr[top];
        top--;
        return val;
    }
    int peek()
    {
        if(top==(-1)) return INT_MIN;
        return (arr[top]);
    }
    int Size()
    {
        return (top+1);
    }
    bool isEmpty()
    {
        return (top==-1);
    }
};
int main()
{
    node *myStack=new node(5);
    myStack->push(10);
    myStack->push(55);
    myStack->push(89);
    myStack->push(96);
    myStack->push(350);
    int len = myStack->Size();
    cout<<"Stack Peek "<<myStack->peek()<<endl;
    myStack->push(66);
    for(int i=0;i<len;i++)
    {
        cout<<"Stack Value "<<myStack->pop()<<endl;
    }
    if(myStack->pop()==INT_MIN)
    {
        cout<<"yooo"<<endl;
    }
    return 0;
}
