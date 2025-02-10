#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<vector<int>> vect;
void addEdge(vect &arr,int src,int des)
{
    arr[src].push_back(des);
    arr[des].push_back(src);
}
void print(vect &arr , int v)
{
    for(int i =0;i<v;i++)
    {
        cout<<i<<" ->";
        for(const auto &x : arr[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

}
/*
   "STEPS" for Naive approach

   1->performing DFS for every not but
     *ignoring one vertex every time

*/
void dfs(vect &arr,vector<bool> &vis,int src,int ver)
{
    vis[src] = true;
    for(auto &x:arr[src])
    {
        if(x!=ver && vis[x]==false)
        {
            dfs(arr,vis,x,ver);
        }
    }

}
void ArticulationP(vect &arr,int n)
{
    for(int i =0;i<n;i++)
    {
        vector<bool> vis(n,false);
        int compo =0;
        for(int j =0;j<n;j++)
        {
            if(i!=j)
            {
                if(vis[j]==false)
                {
                    compo++;
                    dfs(arr,vis,j,i);
                }
            }
        }
        if(compo>1)
        {
            cout<<"Articulation Point : "<<i<<endl;
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

