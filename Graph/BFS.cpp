#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void bfs(vector<vector<int>>&arr,int src)
{
    int n = arr.size();
    vector<bool>vis(n,false);
    queue<int> qt;
    vis[src]= true;
    qt.push(src);
    cout<<src<<" ";
    while(!qt.empty())
    {
        int num = qt.front(); qt.pop();
        for(int i=1;i<arr[num].size();i++)
        {
            if(arr[num][i]==1 && vis[i]==false)
            {
                cout<<i<<" ";
                qt.push(i);
                vis[i] = true;
            }
        }
    }
    cout<<endl;
}
void bfs2(vector<vector<int>>&arr,int src)
{
    int n = arr.size();
    vector<bool> vis(n,false);
    queue<int> qt;
    vis[src] = true;
    qt.push(src);
    cout<<src<<" ";
    while(!qt.empty())
    {
        src = qt.front(); qt.pop();
        for(int n : arr[src])
        {
            if(vis[n]==false)
            {
                cout<<n<<" ";
                vis[n]=true;
                qt.push(n);
            }
        }
    }
    cout<<endl;
}
void addEdge(vector<vector<int>> &arr,int v,int u)
{
    arr[v].push_back(u);
    arr[u].push_back(v);
}
void printGraph(vector<vector<int>>&vect)
{
    int n = vect.size();
    for(int i=0;i<n;i++)
    {
        if(vect[i].size()!=0){
        cout<<"vertex "<<i<<" -> ";
        for(int x : vect[i]) cout<<x<<" ";
        cout<<endl;
        }
    }
}
int main()
{
    /*
    1---2
    | \ |
    4---3
     \ /
      5
     / \
    6   7
    */
    fastIO
    int v;
    vector<vector<int>> graph1= { {0,0,0,0,0,0,0,0},
                                  {0,0,1,1,1,0,0,0},
                                  {0,1,0,1,0,0,0,0},
                                  {0,1,1,0,1,1,0,0},
                                  {0,1,0,1,0,1,0,0},
                                  {0,0,0,1,1,0,1,1},
                                  {0,0,0,0,0,1,0,0},
                                  {0,0,0,0,0,1,0,0}};

    cout<<"Adjacent Matrix Representation"<<endl;
    cout<<"Select A vertex "; cin>>v;
    cout<<"BFS -> ";
    bfs(graph1,v);
    cout<<"Adjacent List Representation"<<endl;
    cout<<"Select A vertex "; cin>>v;
    int numOfvertex = 7;
    vector<vector<int>> graph2(numOfvertex+1);
    addEdge(graph2,1,2);
    addEdge(graph2,1,3);
    addEdge(graph2,1,4);
    addEdge(graph2,2,3);
    addEdge(graph2,3,4);
    addEdge(graph2,3,5);
    addEdge(graph2,4,5);
    addEdge(graph2,5,6);
    addEdge(graph2,5,7);
    printGraph(graph2);

    cout<<"BFS -> ";
    bfs2(graph2,v);
    return 0;
}
