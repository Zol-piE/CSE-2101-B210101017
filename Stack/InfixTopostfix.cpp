#include<bits/stdc++.h>
using namespace std;
int precedence(char ch)
{
    if(ch=='^') return 3;

    else if(ch=='*' || ch == '/') return 2;

    else if(ch=='+'|| ch=='-') return 1;


    return -1;
}
void infixTOpost(string str)
{
    stack<char> st;
    st.push('(');
    str+=')';
    string ptr="";
    int len = str.length();
    for(int i=0;i<len && !st.empty(); i++)
    {

        if(str[i]>='A' && str[i]<='Z' )
        {
            ptr+=str[i];
        }
        else if(str[i]=='(')
        {
          st.push(str[i]);

        }

        else if(str[i]=='*' || str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='^')
        {
            while(!st.empty() && precedence(str[i]) <= precedence(st.top()))
            {
                ptr+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(st.top()!='(')
            {
                ptr+=st.top();
                st.pop();
            }
            st.pop();
        }
    }
    cout<<ptr<<endl;
}
int main()
{
    string str ="A+(B*C-(D/E^F)*G)*H";
    infixTOpost(str);
    return 0;
}
