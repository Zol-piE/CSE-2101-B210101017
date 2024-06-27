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
        QuickSort(arr,low,j-1);
        QuickSort(arr,j+1,high);
    }
}
int main()
{
    int arr[] = {44,33,11,55,77,90,40,60,99,22,88,66};
    int len = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,len-1);
    for(int i=0;i<len;i++) cout<<arr[i]<<" ";
    return 0;
}
