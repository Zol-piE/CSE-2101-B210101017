#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void addedge(vector<vector<pair<int,int>>> &arr,int src,int des,int weight)
{
    arr[src].push_back(make_pair(des,weight));
}
void print(vector<vector<pair<int,int>>> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<"Vertex "<<i<<" -> ";

        for(auto it : arr[i]) cout<<"( "<<it.first<<" , "<<it.second<<" ) ";

        cout<<endl;
    }
}
vector<int> countDeg(vector<vector<pair<int,int>>> &arr)
{
    int n = arr.size();
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto x : arr[i])
        {
            indeg[x.first]++;
        }
    }
    return indeg;
}
vector<int> t_sort(vector<vector<pair<int,int>>> &arr)
{
    int n = arr.size();

    vector<int> indeg = countDeg(arr),tsort;
    queue<int> qt;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0) qt.push(i);
    }
    while(!qt.empty())
    {
        int src = qt.front();qt.pop();
        tsort.push_back(src);
        for(auto x : arr[src])
        {
            indeg[x.first]--;
            if(indeg[x.first]==0) qt.push(x.first);
        }
    }
    return tsort;
}
vector<int> shortPath(vector<vector<pair<int,int>>> &arr,int src)
{
    int n = arr.size();

    vector<int> tsort = t_sort(arr);

    vector<int> dis(n,INT_MAX);

    dis[src] = 0;
    for(int i=0;i<n;i++)
    {
        for(auto x : arr[i])
        {
            if(dis[x.first]>(dis[i]+x.second))
            {
                dis[x.first]=(dis[i]+x.second);
            }
        }
    }
    return dis;
}
int main()
{
    int n = 6;

    vector<vector<pair<int,int>>> graph(n);

    addedge(graph,0,1,2);
    addedge(graph,0,4,1);
    addedge(graph,1,2,3);
    addedge(graph,2,3,6);
    addedge(graph,4,2,2);
    addedge(graph,4,5,4);
    addedge(graph,5,3,1);

    print(graph);
    vector<int> indeg = countDeg(graph);
    for(int x:indeg) cout<<x<<" ";
    cout<<endl;
    vector<int> tsort = t_sort(graph);
    for(int x:tsort) cout<<x<<" ";
    cout<<endl;
    vector<int> sp = shortPath(graph,0);
    for(int x:sp) cout<<x<<" ";
    cout<<endl;

    return 0;
}
