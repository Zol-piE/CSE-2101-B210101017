#include<iostream>
using namespace std;
int BinarySearch(int arr[],int low ,int high,int key)
{
    if(low<=high)
    {
        
        int mid = (low+high) / 2;
        cout<<low<<" " <<high<<" "<<mid<<endl;
        if(key==arr[mid])
        {
            return mid;
        }
        else if(key<arr[mid])
        {
            return BinarySearch(arr,low,mid-1,key);
        }
        else return  BinarySearch(arr,mid+1,high,key);
    }
    return -1;
}
int main()
{
    int arr[10] = { 1,2,3,4,5,11,17,18,33,35};
    cout<<BinarySearch(arr,0,9,3);
    return 0;
}