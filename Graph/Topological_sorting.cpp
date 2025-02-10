#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
void addEdge(vector<vector<int>> &arr,int src,int des)
{
    arr[src].push_back(des);
}
void printGraph(vector<vector<int>>&arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<"Vector "<<i<<" -> ";
        for(int x : arr[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
vector<int> indegree(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++)
    {
        for(int i : arr[i])
        {
            indeg[i]++;
        }
    }
    return indeg;
}
void t_sort(vector<vector<int>> &arr)
{
    vector<int> indeg = indegree(arr);
    queue<int> qt;
    for(int i=0;i<indeg.size();i++)
    {
        if(indeg[i]==0) qt.push(i);
    }
    while(!qt.empty())
    {
        int src = qt.front(); qt.pop();
        cout<<src<<" ";
        for(int i : arr[src])
        {
            indeg[i]--;
            if(indeg[i]==0) qt.push(i);
        }
    }
    cout<<endl;
}

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,4,5);
    addEdge(graph,5,1);
    addEdge(graph,5,2);
    printGraph(graph);
    t_sort(graph);
    n = 5;
    vector<vector<int>> graph2(n);
    addEdge(graph2,0,2);
    addEdge(graph2,0,3);
    addEdge(graph2,1,3);
    addEdge(graph2,1,4);
    addEdge(graph2,2,3);
    printGraph(graph2);
    t_sort(graph2);
    return 0;
}
