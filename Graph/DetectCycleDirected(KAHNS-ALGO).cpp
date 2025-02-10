#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
void addEdge(vector<vector<int>> &arr,int src,int des)
{
    arr[src].push_back(des);
}
void print(vector<vector<int>> &arr)
{
    int n =arr.size();
    for(int i =1;i<n;i++)
    {
        cout<<"Vertex "<<i<<" -> ";
        for(int x : arr[i]) cout<<x<<" ";
        cout<<endl;
    }
}
vector<int> indegree(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> indeg(n);
    for(int i =1;i<n;i++)
    {
        for(int x : arr[i])
        {
            indeg[x]++;
        }
    }
    return indeg;
}
void t_sort(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> indeg = indegree(arr),res;
    queue<int> qt;
    for(int i=1;i<n;i++)
    {
        if(indeg[i]==0) qt.push(i);
    }
    int con =0;
    while(!qt.empty())
    {
        int src = qt.front(); qt.pop();
        res.push_back(src);
        con++;
        for(int i : arr[src])
        {
            indeg[i]--;
            if(indeg[i]==0) qt.push(i);
        }
    }
    if(con!=(n-1)) cout<<"IMPOSSIBLE"<<endl;
    else
    {
        for(int i : res) cout<<i<< " ";
        cout<<endl;
    }
}
int main()
{
    fast
    int n; cin>>n;
    vector<vector<int>> graph(n+1);
    int m; cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        addEdge(graph,x,y);
    }
    t_sort(graph);
    return 0;
}
