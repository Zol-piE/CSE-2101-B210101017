#include<iostream>
#include<vector>
using namespace std;
int const Size = 10;
int hashfun(int key)
{
    return key %Size;
}
int probe(vector<int> &arr,int key)
{
    int index = hashfun(key);
    int i =1;
    while(arr[(index+(i*i))%Size]!=0)
    {
        i++;
    }
    return (index+(i*i))%Size;
}
void inserting(vector<int>&arr,int key)
{
    int index = hashfun(key);
    if(arr[index]==0)
    {
        arr[index] = key;
    }
    else
    {
        index = probe(arr,key);
        arr[index] = key;
    }
}
bool searching(vector<int>&arr,int key)
{

}
int main()
{
    vector<int>arr(10,0);
    inserting(arr,23);
    inserting(arr,43);
    inserting(arr,13);
    inserting(arr,27);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    return 0;
}
