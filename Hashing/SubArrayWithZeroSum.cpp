#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
bool subArray(vector<int> &arr,int n)
{
    unordered_set<int> st;
    int pSum =0;
    for(int i =0;i<n;i++)
    {
        pSum +=arr[i];
        if(st.find(pSum)!=st.end()) return true;
        if(pSum==0) return true;
        st.insert(pSum);
    }
    return false;

}
int main()
{
    vector<int> arr = { 1,4,13,-3,-10,5};
    cout<<subArray(arr,arr.size())<<endl;
    arr.clear();
    arr = { 3,1,-2,5,6};
    cout<<subArray(arr,arr.size())<<endl;
    return 0;
}

