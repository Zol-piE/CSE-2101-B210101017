#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<vector<int>> vect;
void ArtDFS(vect &arr,vector<bool> &vis,vector<int> &dis,vector<int> &low,int src,int par,int time)
{
    vis[src] = true;
    dis[src] = low[src] = ++time;
    for(const auto &x : arr[src])
    {
        if(vis[x]==false)
        {
            ArtDFS(arr,vis,dis,low,x,src,time);
            if(x!=par) low[src] = min(low[src],low[x]);
        }
        else if(par!=-1 && )

    }
}
void ArtFun(vect &arr,int v)
{
    vector<bool> vis(v,false),AP(n,false);
    vector<int> dis(v,0),low(n,0);

    for(int i =0;i<v;i++)
    {
        if(vis[i]==false)
        {

        }
    }
}
int main()
{
    fast
    int v = 5;
    vect gp(v);
    addEdge(gp,0,1);
    addEdge(gp,0,2);
    addEdge(gp,1,2);
    addEdge(gp,2,3);
    addEdge(gp,3,4);
    print(gp,v);
    ArticulationP(gp,v);
    return 0;
}

