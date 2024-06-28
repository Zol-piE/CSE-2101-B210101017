#include<iostream>
using namespace std;
void SelectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j=i,k=i;
        for(;j<n;j++)
        {
            if(arr[j]<arr[k]) k=j;
        }
        swap(arr[i],arr[k]);
    }

}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;
}
int main()
{
    int arr[] = {8,6,4,1,2,3,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    Display(arr,len);
    SelectionSort(arr,len);
    Display(arr,len);

    return 0;
}
