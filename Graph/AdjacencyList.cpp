#include<iostream>
#include<vector>
using namespace std;
void addedge(vector<vector<int>>&arr,int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void printGraph(vector<vector<int>>&arr,int vertices)
{
    for(int i =0;i<=vertices;i++)
    {
        if(arr[i].size()!=0){
        cout<<"vertex "<<i<<" edges -> ";
        for(auto x : arr[i]) cout<<x<<" ";

        cout<<endl;
        }

    }
}
int main()
{
    int vertices = 4;
    vector<vector<int>> adj_list(vertices+1);
    addedge(adj_list,1,2);
    addedge(adj_list,1,3);
    addedge(adj_list,1,4);
    printGraph(adj_list,vertices);
    return 0;
}
