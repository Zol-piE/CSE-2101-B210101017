#include<iostream>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data,node *next)
    {
        this->data = data;
        this->next = next;
    }
};
class Queue
{
public:
    node *Front,*rear;
    int Size;
    Queue()
    {
        Front = NULL;
        rear = NULL;
        Size=0;
    }
    void enqueue(int value)
    {
        node *temp = new node(value,NULL);
        if(Front==NULL)
        {
            Front = rear = temp;
            Size++;
            return;
        }
        rear->next = temp;
        rear = temp;
        Size++;
    }
    int  dequeue()
    {
        if(Front==NULL)
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int res = Front->data;
        Front = Front->next;
        Size--;
        if(Front==NULL)
        {
            Front = rear = NULL;
        }
        return res;
    }
};
template<class T>
void display(T var)
{
    while(var.Front!=NULL) cout<<var.dequeue()<< " ";

    cout<<endl;
}

template<class T, typename t>
void Reverse(T &var) {
    stack<t> st;
    while (var.Front != NULL) st.push(var.dequeue());
    while (!st.empty()) {
        var.enqueue(st.top());
        st.pop();
    }
}



int main()
{
    Queue qt;
    qt.enqueue(1);
    qt.enqueue(2);
    qt.enqueue(3);
    cout<<qt.Size<<endl;
    display(qt);
    Reverse<Queue,int>(qt);
    display(qt);


    return 0;
}
