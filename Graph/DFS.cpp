#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int>>&arr,int src,int des)
{
    arr[src].push_back(des);
    arr[des].push_back(src);
}
void printGraph(vector<vector<int>>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<"Vertex "<<i<<" -> ";
        for(int x : arr[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void dfs(vector<vector<int>>&arr,int src,vector<bool>&vis)
{
    if(vis[src]==false)
    {
        cout<<src<<" ";
        vis[src] = true;
        for(int i : arr[src])
        {
            dfs(arr,i,vis);
        }
    }
}
int main()
{
    int n = 6;
    vector<vector<int>> graph(n+1);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,4,5);
    addEdge(graph,4,6);
    addEdge(graph,5,6);
    vector<bool> vis(graph.size(),false);
    printGraph(graph);
    dfs(graph,1,vis);
    return 0;
}
