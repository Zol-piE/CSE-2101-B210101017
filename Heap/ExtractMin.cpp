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
    int minimum()
    {
        int temp = arr[0];
        heapSize--;
        arr[0]=arr[heapSize];
        minHeapify(0);
        arr[heapSize] = temp;
        return temp;
    }
};
int main()
{
    MinHeap heap;
    int n;
    while(cin>>n && n!=-1)
    {
        heap.insertHeap(n);
    }
    heap.print();
    for(int i=1;i<=3;i++) heap.minimum();
    heap.print();
    cout<<heap.HeapSize()<<endl;

    return 0;
}

