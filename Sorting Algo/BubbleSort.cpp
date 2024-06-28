#include<iostream>
using namespace std;
void BubbleSort(int *arr,int n)
{
    bool flag = true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag = false;
            }
            if(flag) break;
        }
    }
}
void Display(int *arr,int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;
}
int main()
{
    int arr[] = {5,3,9,5,1,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    Display(arr,len);
    BubbleSort(arr,len);
    Display(arr,len);
    return 0;
}
