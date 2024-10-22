#include<iostream>
#include<vector>
using namespace std;
class MinHeap
{
    vector<int> arr;
    int heapSize;
public:
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
};
int main()
{
    MinHeap heap;

    heap.insertHeap(10);
    heap.insertHeap(5);
    heap.insertHeap(2);
    heap.insertHeap(15);
    heap.insertHeap(7);
    heap.insertHeap(20);
    heap.insertHeap(1);
    heap.print();
    return 0;
}
