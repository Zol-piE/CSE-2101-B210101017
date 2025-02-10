#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector<vector<int>>&arr,int src,int des)
{
    arr[src].push_back(des);
    arr[des].push_back(src);
}
void printGraph(vector<vector<int>> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<"vertex "<<i<<" -> ";
        for(int x : arr[i]) cout<<x<<" ";
        cout<<endl;
    }
}
void dfs_dis(vector<vector<int>> &arr,vector<bool>&vis,int src)
{
    if(vis[src]==false)
    {
        cout<<src<<" ";
        vis[src]= true;
        for(int x : arr[src])
        {
            dfs_dis(arr,vis,x);
        }
    }

}
int dfs(vector<vector<int>>&arr)
{
    int cont =0;
    vector<bool> vis(arr.size(),false);
    for(int i=0;i<arr.size();i++)
    {
        if(vis[i]==false)
        {
            dfs_dis(arr,vis,i);
            cont++;
        }
    }
    cout<<endl;
    return cont;
}
int main()
{
    int n = 5;
    vector<vector<int>>graph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,3,4);
    graph.resize(6);
    printGraph(graph);
    int connect = dfs(graph);
    cout<<"Conneted Components "<<connect<<endl;
    return 0;
}
