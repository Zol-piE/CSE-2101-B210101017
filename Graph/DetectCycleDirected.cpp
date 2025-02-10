#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int>>&arr,int src,int des)
{
    arr[src].push_back(des);
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
bool dfs(vector<vector<int>> &arr,vector<bool> &vis,vector<bool> &rec,int src)
{
    vis[src] = true;
    rec[src] = true;
    for(int x : arr[src])
    {
        if(vis[x]==false)
        {
            if(dfs(arr,vis,rec,x)==true) return true;
        }
        else if(rec[x]) return true;
    }
    rec[src]=false;

    return false;
}
bool dfs_dis(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<bool> vis(n,false);
    vector<bool> rec(n,false);
    for(int i=0;i<n;i++)
    {
        if(dfs(arr,vis,rec,i)) return true;
    }
    return false;
}
int main()
{
    int n = 6;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,2,1);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,3);
    print(graph);
    if(dfs_dis(graph)==true) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle"<<endl;
    return 0;
}
