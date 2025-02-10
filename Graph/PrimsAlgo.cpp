#include<iostream>
#include<vector>
using namespace std;
int primsMST(vector<vector<int>> &arr,int v)
{
    vector<int> key(v,INT_MAX);
    vector<bool> mv(v,false);
    key[0]=0;
    int res =0;
    for(int i=0;i<v;i++)
    {
        int u =-1;
        for(int i=0;i<v;i++)
        {
            if(mv[i]==false && ( u==-1 || key[i]<key[u]))
            {
                u =i;
            }
        }
        mv[u]=true;
        res +=key[u];
        for(int i =0;i<v;i++)
        {
            if(arr[u][i]!=0&& mv[i]==false)
            {
                key[i]=min(arr[u][i],key[i]);
            }
        }
    }
    return res;
}

int main()
{
    int v = 4;
    vector<vector<int>> graph = {
                                    {0,5,10,0},
                                    {5,0,8,15},
                                    {10,8,0,20},
                                    {0,15,20,0},
                                };
    cout<<primsMST(graph,v)<<endl;
    return 0;
}
