#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    int temp = arr[n];
    int i =n ;
    while(i>1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i/=2;
    }
    arr[i] = temp;
}

int main()
{
    int arr[] = { 0,40,30,35,25,20,5,10};
    int heapSize = 1;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for(int i=2;i<arrSize;i++)
    {
        insertion(arr,i);
        heapSize++;
    }
    cout<<"Heap Size "<<heapSize<<endl;
    for(int x : arr) cout<<x<<" ";
    return 0;
}
