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
      if(arr[i]<brr[j] ) i++;
      else if (arr[i]>brr[j]) j++;
      else
      {
          crr[k++] = arr[i++];
          j++;
      }
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
    int arr[] = {1,2,3,4,5},brr[]={1,2,3,4,5};

    sort(arr,arr+5); sort(brr,brr+5); // Arrays must be sorted for this Algo
    int *crr = Union(arr,brr,5,5);
    Display(crr,10);
    return 0;
}

