#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<int> vec;
int initializer(vector<int> &arr,int n)
{
    srand(time(0));
    vector<bool> vis(n*2,false);
    vis[0]=true;
    int i =0;
    while(i<n)
    {
        int x = rand()%12;
        if(vis[x]==false)
        {
            vis[x]=true;
            arr.push_back(x);
            i++;
        }
    }
    return 0;
}
void print(vector<int>&arr,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void subMerge(vec &arr,int low,int mid,int high)
{
    int n1 = mid - low +1;
    int n2 = high - mid;
    vec s1(n1,0),s2(n2,0);
    for(int i = 0;i<n1;i++)
    {
        s1[i] = arr[low+i];
    }
    for(int i = 0;i<n2;i++)
    {
        s2[i] = arr[mid+i+1];
    }
    int k = low,i = 0,j =0;
    while(i<n1 && j<n2)
    {
        if(s1[i]>=s2[j])
        {
            arr[k++] = s2[j++];
        }
        else arr[k++] = s1[i++];
    }
    while(i<n1) arr[k++] = s1[i++];

    while(j<n2) arr[k++] = s2[j++];
}
void mergeSort(vec &arr,int low,int high)
{
    if(low<high){
    //divide the array into subarrays
    int mid = low + (high - low) / 2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    subMerge(arr,low,mid,high);

    }

}
int main()
{
    fast
    int n = 10;
    vector<int>arr;
    initializer(arr,n);
    print(arr,n);
    mergeSort(arr,0,n-1);
    print(arr,n);
    return 0;
}
