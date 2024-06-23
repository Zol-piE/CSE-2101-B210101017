#include<iostream>
#include <cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;
int BinaryS(int arr[],int low,int high,int key);
int main()
{
    int size ;cout<<"Enter Size: " ;cin>>size;  cout<<endl;
    srand(time(NULL));
    int *arr = new int [size];
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%101;
    }
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Enter Key : " ; int key;cin>>key; cout<<endl;
    cout<<"Element Search : ";
    cout<<BinaryS(arr,0,size-1,key);
    return 0;
}
int BinaryS(int arr[],int low,int high,int key)
{
    if(low<=high){
    int mid = (low+high)/2;
    if(key==arr[mid]) return mid;
    else if(key>arr[mid])
    {
        return BinaryS(arr,(mid+1),high,key);
    }
    else 
    {
        return BinaryS(arr,low,(mid-1),key);
    }
    }
    return -1;
}