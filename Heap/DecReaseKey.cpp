#include<iostream>
#include<vector>
using namespace std;
class MinHeap
{
    vector<int> arr;
    int heapSize;
public:
    MinHeap() : heapSize(0) {}
    void inserting(int data);
    void index(int i,int data);
    void print();
    void decreaseKey(int in,int data);
};
void MinHeap :: inserting(int data)
{
    arr.push_back(data);
    int i = heapSize;
    heapSize++;
    while(i>0 && arr[i/2] > arr[i])
    {
        swap(arr[i/2],arr[i]);
        i = i/2;
    }
}
void MinHeap:: print()
{
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
}
void MinHeap :: index(int i,int data)
{
    arr[i] = data;
}
void MinHeap:: decreaseKey(int in,int data)
{
    index(in,data);
    int i = in;
    while(i>0 && arr[i/2]>arr[i])
    {
        swap(arr[i/2],arr[i]);
        i=i/2;
    }
}
int main()
{
    MinHeap heap;
    heap.inserting(20);
    heap.inserting(40);
    heap.inserting(10);
    heap.inserting(80);
    heap.inserting(100);
    heap.inserting(70);
    heap.print();
    heap.decreaseKey(3,5);
    heap.print();
    heap.decreaseKey(1,2);
    heap.decreaseKey(0,1);
    heap.print();

    return 0;
}
