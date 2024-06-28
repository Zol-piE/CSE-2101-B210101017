#include<iostream>
using namespace std;
int partion(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i=low,j=high;

    do
    {
        do { i++;}while(arr[i]<=pivot);
        do { j--;}while(arr[j]>pivot);
        if(i<j) swap(arr[i],arr[j]);
    }while(i<j);
    swap(arr[j],arr[low]);
    return j;
}
void QuickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int j = partion(arr,low,high);
        QuickSort(arr,low,j);
        QuickSort(arr,j+1,high);
    }
}
int main()
{
    int arr[] = {7,9,6,1,3,5,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,len);
    for(int i=0;i<len;i++) cout<<arr[i]<<" ";
    return 0;
}
