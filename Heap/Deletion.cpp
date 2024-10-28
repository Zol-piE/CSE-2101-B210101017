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
int deletion(int arr[],int &hs)
{
    int temp = arr[1];
    arr[1] = arr[hs];
    hs--;
    int i =1,j = i*2;
    while(j<=hs)
    {
        if(j<hs&& arr[j]<arr[j+1]) j = j+1;

        if(arr[j]>arr[i])
        {
            swap(arr[i],arr[j]);
            i =j;
            j = i*2;
        }
        else break;
    }
    hs++;
    arr[hs] = temp;
    hs--;
    return temp;
}
int main()
{
    int arr[] = {0,40,30,35,25,20,10,5};
    int heapSize = 1;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for(int i=2;i<arrSize;i++)
    {
        insertion(arr,i);
        heapSize++;
    }
    cout<<"Heap Size "<<heapSize<<" ";
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    while(heapSize!=0)
    {
    deletion(arr,heapSize);
    cout<<"Heap Size "<<heapSize<<" ";
    for(int x : arr) cout<<x<<" "; cout<<endl;
    }

    return 0;
}

