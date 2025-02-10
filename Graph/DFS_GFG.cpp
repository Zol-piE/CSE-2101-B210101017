#include<bits/stdc++.h>
using namespace std;
void dfs_rec(vector<vector<int>> &arr,vector<bool>&vis,int src)
{
    vis[src] = true;
    cout<<src<< " ";
    for(int x : arr[src])
    {
        if(vis[x]==false)
        {
            dfs_rec(arr,vis,x);
        }
    }
}
void dfs(vector<vector<int>>&arr)
{
    int n= arr.size();
    vector<bool> vis(n,false);
    int con =0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs_rec(arr,vis,i);
            con++;
        }
    }
    cout<<endl;
}
int main()
{
    vector<vector<int>> graph{ {1,3},{0,2,3},{1,3},{0,1,2} };
    dfs(graph);
    return 0;
}
