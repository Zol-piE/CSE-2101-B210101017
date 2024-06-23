#include<iostream>
using namespace std;
 class Array
 {
    public:
    int *A;
    int size;
    int length;
 };
 void Display(Array arr)
 {
    cout<<"Display"<<endl;
    for(int i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;

 }
 void add(Array &arr , int value)
 {
    if(arr.length<arr.size)
    {
        arr.A[arr.length++]=value;
    }
    else cout<<"Array is Full"<<endl;
 }
 void insert(Array &arr,int index,int value)
 {
    if(index<arr.size && index<=arr.length)
    {
        for(int i = arr.length ; i>index;i--)
        {
            arr.A[i]=arr.A[i-1];
        }
        arr.A[index]=value;
        arr.length++;
    }
 }
 int Delete(Array &arr,int index)
 {
    int x=0;
    if(arr.length>index && index>=0)
    {
        x = arr.A[index];
        for(int i=index ; i<arr.length-1;i++ )
        {
            arr.A[i]=arr.A[i+1];
        }
        arr.length--;
    }
    return x;
 }
 int LinearSearch(Array &arr,int key)
 {
    cout<<"Linear search Method"<<endl;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
        {
            swap(arr.A[i],arr.A[i-1]);
            return i;
        }
    }
    return -1;
 }
int main()
{
    Array arr;
    cout<<"Enter Size : ";
    cin>>arr.size;
    cout<<endl;
    arr.A = new int[arr.size];
    arr.length =0;
    int n ; cout<<"Enter numbers :"; cin>>n; cout<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>arr.A[i];
    }
    arr.length = n;
    Display(arr);
     cout<<"Add Number " ; cin>>n; cout<<endl;
    add(arr,n);
    Display(arr);
    int index; 
    cout<<"Insert A Number & index " ; cin>>n>>index; cout<<endl;
    insert(arr,index,n);
    Display(arr);
    cout<<"Enter index " ; cin>>index; cout<<endl;
    Delete(arr,index);
    Display(arr);

    cout<<"Search An Element : "; cin>>n; cout<<endl;

    cout<<"Index : " << LinearSearch(arr,n)<<endl;




    return 0;
}