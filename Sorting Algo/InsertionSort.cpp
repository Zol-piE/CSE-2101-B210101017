#include<iostream>
using namespace std;
void newInsertionSort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        while(j>-1 && arr[j+1]<arr[j])
        {
            swap(arr[j+1],arr[j]);
            j--;
        }
    }
}
void insertionSort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int x = arr[i];
        int j= i-1;
        while(j>-1&&arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] =x;
    }
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;
}
int main()
{
    int arr[]={2,3,4,5,0,6,7,1};
    int vrr[] = {1,2,3,5,6,7};

    int len = sizeof(arr)/sizeof(arr[0]);
    int len2 = sizeof(vrr)/sizeof(vrr[0]);
    Display(arr,len);
    insertionSort(arr,len);
    Display(arr,len);
    Display(vrr,len2);
    insertionSort(vrr,len2);
    Display(vrr,len2);

    return 0;
}
