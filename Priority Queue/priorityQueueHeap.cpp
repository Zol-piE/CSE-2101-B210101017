#include<iostream>
#include<vector>
using namespace std;

class pQueue
{
public:
    vector<int> arr;
    int siz;
    pQueue() : siz(0) {}
    void enqueue(int data)
    {
        int i = siz;
        arr.push_back(data);
        while(i >0 && data<arr[(i-1)/2])
        {
            swap(arr[i],arr[(i-1)/2]);
            i = (i-1)/2;
        }
        siz++;
    }
    void print()
    {
        for(int x : arr) cout<<x<<" ";
        cout<<endl;
    }
    int dequeue()
    {
        int temp = arr[0];
        int n = siz-1;
        arr[0] = arr[n];
        int i=0,j=0;
        while(i<n)
        {
            int left = (i*2)+1;
            int right = (i*2)+2;
            if(left<n && arr[i]> arr[left]) j = left;
            if(right<n && arr[i]> arr[right]) j = right;
            if(i!=j)
            {
                swap(arr[i],arr[j]);
                i =j;
            }
            else break;
        }
        siz--;
        return temp;
    }
};
int main()
{
    pQueue pq;
    pq.enqueue(10);
    pq.enqueue(8);
    pq.enqueue(6);
    pq.enqueue(4);
    pq.enqueue(2);
    pq.print();
    for(int i=0;i<5;i++) cout<<pq.dequeue()<<" ";
    cout<<endl;
    return 0;
}
