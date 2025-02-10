#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void addEdge(vector<vector<int>> &arr,int src,int des)
{
    arr[src].push_back(des);
    arr[des].push_back(src);
}
void print(vector<vector<int>> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<""<<i<<" -> ";
        for(int x : arr[i]) cout<<x<<" ";
        cout<<endl;
    }
}
void dfs_run(vector<vector<int>> &arr,vector<bool> &vis,int src)
{
    vis[src] = true;
    int n = arr[src].size();
    cout<<src<<" ";
    for(int x : arr[src])
    {

        if(vis[x]==false)
        {
            dfs_run(arr,vis,x);
        }
    }
}
void dfs(vector<vector<int>>  &arr)
{
    int n = arr.size();

    vector<bool> vis(n,false);

    for(int i=0;i<n;i++)
    {
        if(vis[i]==false) dfs_run(arr,vis,i);
        cout<<endl;
    }
}

int  main()
{
    int n = 5;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    print(graph);
    dfs(graph);

    return 0;
}
