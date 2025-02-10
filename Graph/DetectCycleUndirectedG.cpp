#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void addEdge(vector<vector<int>>&arr,int src,int des)
{
    arr[src].push_back(des);
    arr[des].push_back(src);
}
void print(vector<vector<int>> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<"Vertex "<<i<<" -> ";
        for(int x : arr[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
bool dfs(vector<vector<int>>&arr,vector<bool>&vis,int src,int parent)
{
    vis[src] = true;
    for(int x : arr[src])
    {
        if(vis[x]==false)
        {
            if(dfs(arr,vis,x,src)) return true;
        }
        else if(x!=parent) return true;
    }
    return false;
}
bool dfs_dis(vector<vector<int>>&arr)
{
    int n = arr.size();
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            if(dfs(arr,vis,i,-1)==true) return true;
        }
    }
    return false;
}
int main()
{
    fast
    int n=5;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    print(graph);
    if(dfs_dis(graph)==false) cout<<"No Cycle Detect"<<endl;
    else cout<<"Cycle Detect"<<endl;
    n = 6;
    vector<vector<int>> graph2(n);
    addEdge(graph2,0,1);
    addEdge(graph2,1,2);
    addEdge(graph2,1,3);
    addEdge(graph2,2,3);
    addEdge(graph2,2,4);
    addEdge(graph2,4,5);
    print(graph2);
    if(dfs_dis(graph2)==false) cout<<"No Cycle Detect"<<endl;
    else cout<<"Cycle Detect"<<endl;
    return 0;
}
