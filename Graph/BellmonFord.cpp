#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
class edge
{
public:
    int src,des,w;
    edge(int src,int des,int w) : src(src),des(des),w(w) { }
};
void print(vector<int> &arr,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bellmon(vector<edge> &gp,int src,int v)
{
    vector<int> dis(v,INT_MAX);
    dis[src] = 0;
    for(int i =0;i<(v-1);i++)
    {
//        cout<< "iteration "<<i+1<<endl;
        for(const edge &e : gp)
        {
            if(dis[e.src]!=INT_MAX && dis[e.des] > dis[e.src] + e.w)
            {
                dis[e.des] = dis[e.src] + e.w;
            }
//            cout<<e.src<<" "<<e.des<< " -> ";
//            print(dis,v);
        }
    }
    bool cycle = false;
    for(const edge &e : gp)
    {
        if(dis[e.src]!=INT_MAX && dis[e.des] > dis[e.src] + e.w)
        {
            cycle = true;
            cout<<"Cycle Detect"<<endl;
            break;
        }
    }
    if(cycle==false)
    {
        print(dis,v);
    }

}
int main()
{
    fast
    int v = 6;
    vector<edge> gp = {
    {0,1,5},{0,2,7},{1,3,4},{1,2,3},{1,4,6},
    {3,5,2},{3,4,-1},{4,5,-3}
    };
    bellmon(gp,0,v);
    gp.clear();
    gp = { {0,1,-1},{0,4,4},{1,2,2},{1,4,3},{1,3,2},{3,1,-3},{3,4,5}
    };
    v = 5;
    bellmon(gp,0,v);

    return 0;
}

