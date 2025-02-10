#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
void addedge(vector<vector<int>> &arr,int src,int des)
{
    arr[src].push_back(des);
}
void print(vector<vector<int>> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<"Vertex " << i<<" -> ";
        for(int x: arr[i]) cout<<x<<" ";
        cout<<endl;
    }
}
void tSort(vector<vector<int>>&arr,vector<bool> &vis,stack<int>&st,int src)
{
    vis[src] = true;
    for(int i: arr[src])
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            tSort(arr,vis,st,i);
        }
    }
    st.push(src);
}
void dfs(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<bool> vis(n,false);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false) tSort(arr,vis,st,i);
    }
    while(!st.empty())
    {
        cout<<st.top()<< " ";
        st.pop();
    }
    cout<<endl;
}
int main()
{
    fast
    int n = 5;
    vector<vector<int>> graph(n);
    addedge(graph,0,1);
    addedge(graph,1,3);
    addedge(graph,3,4);
    addedge(graph,2,3);
    addedge(graph,2,4);
//    print(graph);
    dfs(graph);
    return 0;
}
