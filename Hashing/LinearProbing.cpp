#include<iostream>
#include<vector>
using namespace std;
#define Size 10
int hashfun(int key)
{
    return key%Size;
}
int probe(vector<int>&arr,int key)
{
    int index = hashfun(key);
    int i =0;
    while(arr[(index+(i))%Size]!=0){ i++; }

    return (index+(i))%Size;

}
void inserting(vector<int>&arr,int key)
{
    int index = hashfun(key);
    if(arr[index]==0) arr[index] = key;
    else
    {
        index = probe(arr,key);
        arr[index] = key;
    }
}
bool searching(vector<int> &arr,int key)
{
    int index = hashfun(key);
    int i=0;
    while(arr[(index+i)%Size]!=key)
    {
        if(arr[(index+i)%Size]==0) return false;
        i++;
    }
    return true;
}
int main()
{

    vector<int> arr(10,0); //all 10 index are 0
    inserting(arr,10);
    inserting(arr,11);
    inserting(arr,15);
    inserting(arr,16);
    inserting(arr,25);
    inserting(arr,19);
    inserting(arr,29);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    cout<<searching(arr,13)<<endl;


    return 0;
}
