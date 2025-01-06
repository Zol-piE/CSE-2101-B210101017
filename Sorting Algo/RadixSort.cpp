#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<int> vec;
void countSort(vec &arr,int n,int ex,int base)
{
    vec con(base,0),op(n,0);
    for(int i =0;i<n;i++)
    {
        con[(arr[i]/ex)%10]++;
    }

    for(int i =1;i<base;i++) con[i] += con[i-1];

    for(int i =n-1;i>=0;i--)
    {
        op[con[((arr[i]/ex)%10)]-1] = arr[i];
        con[((arr[i]/ex)%10)]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i] = op[i];
    }

}
void radixSort(vec &arr,int n,int base)
{
    int mx= *max_element(arr.begin(),arr.end());

    for(int ex= 1;mx/ex>0;ex *=base)
    {
        countSort(arr,n,ex,base);
    }

}
void print(vec arr,int n)
{
    for(int i =0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    fast
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = arr.size();
    radixSort(arr,n,10);
    print(arr,n);
    return 0;
}
