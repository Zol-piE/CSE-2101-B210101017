#include<iostream>
using namespace std;
struct Stack
{
    int Size;
    int top;
    int *s;
    Stack(int Size)
    {
        this->Size=Size;
        top=-1;
        s = new int[Size];
    }
    void push(int value)
    {
        if(top==Size-1)
        {
            cout<<"Overflow"<<endl;
        }
        else
        {
            top++;
            s[top]=value;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        else
        {
            int x = s[top];
            top--;
            return x;
        }
    }
    int peek(int position)
    {
        int index = top - position +1;
        if(index<0)
        {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else
        {
            return s[index];
        }
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
       return top==Size-1;
    }
    int SIZE()
    {
        return top+1;
    }
    ~Stack()
    {
        delete [] s;
    }
};
void Display(Stack *st)
{

    int target = st->Size;
    int i = st->top;
    if(i==-1)
    {
        cout<<"Empty"<<endl;
        return;
    }
    for(;i>=0;i--)
    {
        cout<<st->s[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    Display(&st);

    for(int i=0;i<4;i++) cout<<st.pop()<<" ";
    cout<<endl;

    Display(&st);

    cout<<st.pop()<<" "<<st.pop()<<endl;
    cout<<st.isEmpty()<<endl;
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    Display(&st);
    cout<<st.isFull()<<endl;
    st.push(789);
    Display(&st);
    cout<<st.isFull()<<endl;

    return 0;
}
