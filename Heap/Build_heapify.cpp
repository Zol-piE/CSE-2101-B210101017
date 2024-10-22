#include<iostream>
#include<vector>
using namespace std;
class MinHeap
{
    vector<int>arr;
    int heapSize;
public:
    void buildHeap(vector<int>brr,int n);
    void minHeapify(int i);
    void print();
};
void MinHeap :: buildHeap(vector<int>brr,int n)
{
    arr = brr;
    heapSize=n;
    for(int i = (n-2)/2;i>=0;i-- )
    {
        minHeapify(i);
    }

}
void MinHeap :: minHeapify(int i)
{
    int smallest = i;
    while(i<heapSize)
    {
        int lf = (i*2)+1;
        int rl = (i*2)+2;
        if(lf<heapSize && arr[smallest]> arr[lf]) smallest = lf;
        if(rl<heapSize&& arr[smallest]>arr[rl]) smallest = rl;
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            i = smallest;
        }
        else break;
    }
}
void MinHeap :: print()
{
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
}
int main()
{
    MinHeap heap;
    vector<int> arr = { 20,10,12,3,5,7,8,1};
    heap.buildHeap(arr,arr.size());
    heap.print();


    return 0;
}
