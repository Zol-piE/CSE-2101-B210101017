#include<iostream>
#include<vector>
using namespace std;
class MinHeap
{
public:
    vector<int> arr;
    int heapSize;
    MinHeap()
    {
        heapSize =0;
    }
    int parent(int i) { return (i-1)/2; }
    int leftChild(int i) { return (i*2)+1; }
    int rightChild(int i) { return (i*2)+2; }
    void insertHeap(int data)
    {
        arr.push_back(data);
        heapSize++;
        int i = heapSize-1;
        while(i>0&& arr[parent(i)]>arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }
    void print()
    {
        for(auto x : arr) cout<<x<<" ";
        cout<<endl;
    }
    int HeapSize() { return heapSize; }
    void minHeapify(int index)
    {
        int i = index,j = leftChild(i);
        while(j<heapSize)
        {
            if((j+1)<heapSize && arr[j]>arr[j+1]) j = j+1;
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
                i = j;
                j = leftChild(i);
            }
            else break;
        }
    }
};
int main()
{
    MinHeap heap;
    int n ;
    while(cin>>n && n!=-1)
    {
        heap.arr.push_back(n);
    }
    heap.heapSize = 10;
    heap.print();
    heap.minHeapify(0);
    heap.print();

    return 0;
}

