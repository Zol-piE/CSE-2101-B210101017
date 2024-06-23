#include<iostream>
#include<algorithm>
using namespace std;
int *Union(int arr[],int brr[],int arrSize,int brrSize)
{
    int crrSize = (arrSize+brrSize);
    int *crr = new int [crrSize];
    int i =0, j =0, k =0;
    while(i<arrSize && j < brrSize)
    {
        if(arr[i]<brr[j]) crr[k++] = arr[i++];
        else if(arr[i]>brr[j]) crr[k++] = brr[j++];
        else
        {
            crr[k++] = arr[i++];
            j++;
        }
    }
    for(;i<arrSize;i++) crr[k++]=arr[i++]; // including remaning element

    for(;j<brrSize;j++) crr[k++] = brr[j++];

    return crr;
}
void Display(int arr[],int Size)
{

    for(int i=0;i<Size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {1,3,5,7,9},brr[]={4,7,2,3,8};

    sort(arr,arr+5); sort(brr,brr+5); // Arrays must be sorted for this Algo
    int *crr = Union(arr,brr,5,5);
    Display(crr,10);
    return 0;
}
