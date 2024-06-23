#include<iostream>
using namespace std;
class Array
{
public:
    int *A;
    int Size;
    int length;
};
bool isSorted(Array &arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1]) return false;
    }
    return true;
}
void insertSArray(Array &arr,int value)
{
    if(arr.length==arr.Size) return;
    int i = arr.length;
    arr.A[i]=value;
    while(arr.A[i]<arr.A[i-1])
    {
        swap(arr.A[i],arr.A[i-1]);
        i--;
    }
    arr.length++;
}
void ArrangeArray(int arr[])
{
    int i =0 , j = 8; //array.length -1
    while(i<j)
    {
        while(arr[i]<0) i++;
        while(arr[j]>0) j--;
        if(j>i) swap(arr[i],arr[j]);
    }
}
void Display(Array &arr)
{

    for(int i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}
void Display(int arr[])
{

    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Array arr;
    arr.A = new int [10];
    arr.Size = 10;
    for(int i=0;i<5;i++)
    {
        cin>>arr.A[i];
    }
    arr.length=5;
    cout<<isSorted(arr)<<endl;
    Display(arr);
    insertSArray(arr,3);
    Display(arr);
    cout<<arr.length<<endl;
    int mixArr[]= { -1,-2,5,-6,3,2,6,-5,-8};
    ArrangeArray(mixArr);
    Display(mixArr);
    return 0;
}
