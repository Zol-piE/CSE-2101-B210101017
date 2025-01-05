#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<int> vec;
void initializer(vec &arr,int n)
{
    int i =0;
//    vector<bool> vis(n*2,false);
//    vis[0]=true;
    while(i<n)
    {
        int x = rand()%10;

//            vis[x]=true;
            arr[i] =x;
            i++;

    }
}
void print(vec &arr,int n)
{
    for(int i =0;i<n;i++) cout<<arr[i]<< " ";
    cout<<endl;
}
int findMax(vec &arr,int n)
{
    int m = INT_MIN;
    for(int i =0;i<n;i++)
    {
        if(m<arr[i])
        {
            m = arr[i];
        }
    }
    return m;
}
void countSort(vec &arr,int n)
{
    int cSize = findMax(arr,n);
    vector<int> freq(cSize+1,0);
    for(int  i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    int i =0,k =0;
    while(i<cSize+1)
    {
        if(freq[i]>0)
        {
            arr[k] = i;
            freq[i]--;
            k++;
        }
        else i++;
    }
}
int main()
{
    fast
    srand(time(0));
    int n = 10;
    vec arr(n,0);
    initializer(arr,n);
    print(arr,n);
    countSort(arr,n);
    print(arr,n);
    return 0;
}
