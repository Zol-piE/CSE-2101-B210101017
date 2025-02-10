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
        cout<<"Vertex "<<i<<" -> ";
        for(int x : arr[i]) cout<<x<<" ";
        cout<<endl;
    }
}
vector<int> Distance(vector<vector<int>>&arr,int src)
{
    int n = arr.size();
    vector<int>dis(arr.size(),-1);
    dis[src]=0;
    vector<bool>vis(n,false);
    queue<int>qt;
    qt.push(src);
    vis[src]=true;
    while(!qt.empty())
    {
        src = qt.front(); qt.pop();
        for(int x : arr[src])
        {
            if(vis[x]==false)
            {
                dis[x]=dis[src]+1;
                vis[x]=true;
                qt.push(x);
            }
        }
    }
    return dis;
}
int main()
{
    int n = 4;

    vector<vector<int>>graph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    printGraph(graph);

    vector<int>dis = Distance(graph,0);
    for(int x : dis) cout<<x<<" ";
    cout<<endl;
    vector<vector<int>> graph2(6);
    addEdge(graph2,0,1);
    addEdge(graph2,0,2);
    addEdge(graph2,0,4);
    addEdge(graph2,1,3);
    addEdge(graph2,2,3);
    addEdge(graph2,2,4);
    addEdge(graph2,3,5);
    addEdge(graph2,4,5);
    printGraph(graph2);
    dis = Distance(graph2,5);
    for(int x : dis) cout<<x<<" ";
    cout<<endl;
    return 0;
}
