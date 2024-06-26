#include<iostream>
using namespace std;
class node
{
public:

    char data;
    node *next;
    node(char data )
    {
        this->data= data;
    }

};
class Mystack
{
public:

    node *top;
    int Size;
    Mystack()
    {
        Size =0;
        top = NULL;
    }
    void push(char data)
    {
        node *temp = new node(data);
        temp->next = top;
        top=temp;
        Size++;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    char pop()
    {
        if(isEmpty()) return '\0';
        int res = top->data;
        Size--;
        top=top->next;
        return res;
    }
    char peek()
    {
        return top->data;
    }

};
bool Check(char a,char b)
{
    return ((a=='('&&b==')')||(a=='{'&&b=='}') || ( a=='['&&b==']'));
}
int main()
{
    string str;
    while(cin>>str)
    {
        Mystack *st = new Mystack();
        int len = str.length();
        bool isBalanced = true;
        for(int i=0;i<len;i++)
        {
            char ch = str[i];
            if(ch == '(' || ch == '{' || ch =='[') st->push(ch);
            else
            {
                if( st->isEmpty() || !Check(st->pop(),ch) )
                {
                    isBalanced= false;
                    break;
                }
            }
        }
        if(isBalanced && st->isEmpty() ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}
