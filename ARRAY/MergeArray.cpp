#include<iostream>
using namespace std;
int *mergeArray(int arr[],int brr[],int Size,int FirstSize,int SecondSize)
{
    int *crr = new int[Size];
    int i = 0,j=0,k=0;
    while(i<FirstSize && j < SecondSize)
    {
        if(arr[i]<brr[j]) crr[k++] = arr[i++];
        else crr[k++] = brr[j++];
    }
    for(;i<FirstSize;i++)
    {
        crr[k++]=arr[i];
    }
    for(;j<SecondSize;j++)
    {
        crr[k++]=brr[j];
    }
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
    int arr[] = {1,3,5,7,9,11};
    int brr[] = {2,4,6,8};
    int *crr = mergeArray(arr,brr,10,6,4);
    Display(crr,10);
    return 0;
}
