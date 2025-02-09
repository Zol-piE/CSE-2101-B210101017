#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector<vector<int>>&arr,int src,int des)
{
    arr[src].push_back(des);
    arr[des].push_back(src);
}
void printGraph(vector<vector<int>>&arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i].size()!=0)
        {
            cout<<"vertex "<<i<<" -> ";
            for(auto x : arr[i]) cout<<x<< " ";
            cout<<endl;
        }

    }
}
void bfs(vector<vector<int>>&arr,vector<bool>&vis,int src)
{
    queue<int> qt;
    qt.push(src);
    vis[src]=true;
    cout<<src<<" ";
    while(!qt.empty())
    {
        src = qt.front();qt.pop();
        for(int v : arr[src])
        {
            if(vis[v]==false)
            {
                vis[v] = true;
                qt.push(v);
                cout<<v<<" ";
            }
        }
    }
}
int bfs_dis(vector<vector<int>>&arr)
{
    int n = arr.size();
    int c_comp=0;
    cout<<n<<endl;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            bfs(arr,vis,i);
            c_comp++;
        }
    }
    cout<<endl;
    return c_comp;
}
int main()
{
    /*
      0         4
    /   \      / \
    1   2     5 - 6
     \ /
      3

    */
    int nVertex=6;
    vector<vector<int>> graph(nVertex+1);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    addEdge(graph,4,5);
    addEdge(graph,4,6);
    addEdge(graph,5,6);
    printGraph(graph);
    int con_comp = bfs_dis(graph);
    cout<<"Num of Connected Components "<<con_comp<<endl;

    return 0;
}
