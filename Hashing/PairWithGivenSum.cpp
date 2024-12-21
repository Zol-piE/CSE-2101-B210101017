#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
bool pairSum(vector<int> &arr,int  n,int target)
{
    unordered_set<int> st;
    for(int i=0;i<n;i++)
    {
        if(st.find(target - arr[i])!= st.end()) return true;

        st.insert(arr[i]);
    }
    return false;
}
int main()
{
    vector<int> arr = { 3,2,8,15,8};
    cout<<pairSum(arr,arr.size(),17)<<endl;
    arr.clear();
    arr = { 2,4,6,3} ;
    cout<<pairSum(arr,arr.size(),11)<<endl;

    return 0;
}
