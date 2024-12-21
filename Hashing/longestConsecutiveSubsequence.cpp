#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int subArray(vector<int> &arr,int n)
{
    unordered_set<int>  st;
    int res =0;
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(st.find(arr[i]-1)==st.end())
        {
            int con =1;
            while(st.find(arr[i]+con)!=st.end())
            {
                con++;
            }
            res = max(res,con);
        }
    }
    return res;
}
int main()
{
    vector<int> arr={ 1,9,3,4,2,20};
    cout<<subArray(arr,arr.size())<<endl;
    arr.clear();
    arr = { 20,30,40};
    cout<<subArray(arr,arr.size())<<endl;
    return 0;
}
