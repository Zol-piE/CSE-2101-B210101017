#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
void print(vector<int> &arr,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void countSort(vector<int> &arr,int n)
{
    int m = *max_element(arr.begin(),arr.end());

    vector<int> con(m+1,0),op(n,0);
    for(int i =0;i<n;i++)
    {
        con[arr[i]]++;
    }
    for(int i=1;i<m+1;i++)
    {
        con[i]=con[i]+con[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        op[con[arr[i]]-1] =arr[i];
        con[arr[i]]--;
    }
    for(int i =0;i<n;i++)
    {
        arr[i] = op[i];
    }
}
int main()
{
    fast
    vector<int> arr = {1,2,3,5,5,7,8,10};
    int n = arr.size();
    countSort(arr,n);
    print(arr,n);

    return 0;
}
