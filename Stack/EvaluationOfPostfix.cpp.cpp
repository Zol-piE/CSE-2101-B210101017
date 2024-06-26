#include<bits/stdc++.h>
using namespace std;
int perform(int a,int b,char ch)
{
    switch(ch)
    {
        case '+' : return a+b;
        case '-' : return b-a;
        case '*' : return a*b;
        case '/' : return b/a;
        case '^' : return pow(b,a);
    }
    return 0;
}
void postfix(string str)
{
    stack<int>st;
    string ptr="";
    str+=')';
    for(int i=0;str[i]!=')';i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            ptr+=str[i];
        }
        else if(str[i]==',')
        {
            if(!ptr.empty()){
            int num = stoi(ptr);
            st.push(num);
            ptr="";
            }
        }
        else
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int res = perform(a,b,str[i]);
            st.push(res);
        }
    }
    cout<<st.top()<<endl;
}
int main()
{
    string str;
    cin>>str;
    postfix(str);
    return 0;
}
