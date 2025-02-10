#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef pair<int,int> ipair;
typedef vector<vector<ipair>> vect;
void addEdge(vector<vector<ipair>> &arr,int src,int des,int w)
{
    arr[src].push_back({des,w});
    arr[des].push_back({src,w});
}
void print(vect &arr,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<"Vertex "<<i <<" -> ";
        for(auto x : arr[i]) cout<< "( "<<x.first<< ","<<x.second<<" ) ";
        cout<<endl;
    }
}
void dijkstra(vect &arr,int src,int n)
{
    vector<bool> vis(n,false);
    vector<int> dis(n,INT_MAX);
    priority_queue<ipair> pq;
    vis[src] = true;
    dis[src] = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        vis[v] = true;
        for(auto x : arr[v])
        {
            if(dis[x.first] > dis[v] + x.second )
            {
                dis[x.first] = dis[v] + x.second;
                pq.push({x.second,x.first});
            }
        }
    }
    for(int i =0;i<n;i++) cout<<dis[i]<<" ";
    cout<<endl;
}
int main()
{
    fast
    int n = 9;
    vector<vector<ipair>> gp(n);

    addEdge(gp,0, 1, 4);
    addEdge(gp,0, 7, 8);
    addEdge(gp,1, 2, 8);
    addEdge(gp,1, 7, 11);
    addEdge(gp,2, 3, 7);
    addEdge(gp,2, 8, 2);
    addEdge(gp,2, 5, 4);
    addEdge(gp,3, 4, 9);
    addEdge(gp,3, 5, 14);
    addEdge(gp,4, 5, 10);
    addEdge(gp,5, 6, 2);
    addEdge(gp,6, 7, 1);
    addEdge(gp,6, 8, 6);
    addEdge(gp,7, 8, 7);

    print(gp,n);
    dijkstra(gp,0,n);
    return 0;
}
