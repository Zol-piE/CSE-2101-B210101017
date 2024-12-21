#include<iostream>
#include<vector>
using namespace std;
int const Size = 10;
int R;
void findPrime()
{
    vector<bool>prime(Size+1,true);
    for(int i =2;i*i<=Size;i++)
    {
        if(prime[i])
        {
            for(int j = i*i;j<=Size;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    int i = Size -1;
    while(prime[i]==false)
    {
        i--;
    }
    R = i;
}
int hashfun(int key)
{
    return key%Size;
}
int probing(vector<int>&arr,int key)
{
    int index1 = hashfun(key);

    int index2 = R - (key%R);
    int i =0;
    while(arr[(index1+(i*index2))%10]!=0)
    {
        i++;
    }
    return (index1+(i*index2))%10;

}
void inserting(vector<int> &arr,int key)
{
    int index = hashfun(key);
    if(arr[index]==0)
    {
        arr[index] = key;
    }
    else
    {
        index = probing(arr,key);
        arr[index] = key;
    }
}
int main()
{
    findPrime();
    vector<int>arr(10,0);
    inserting(arr,5);
    inserting(arr,25);
    inserting(arr,15);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    inserting(arr,95);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;

    return 0;
}
