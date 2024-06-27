#include<iostream>
using namespace std;
class node
{
public:
    int data;
    int prn;
    node *next;
    node(int data,int prn)
    {
        this->data = data;
        this->prn = prn;
        this->next = NULL;
    }
};
class pqueue
{
public:
    node *Front;
    pqueue()
    {
        Front = NULL;
    }
    void insertq(int data,int prn)
    {
        node *curr = Front,*prev = NULL;
        node *temp = new node(data,prn);
        if(Front==NULL)
        {
            Front = temp;
            return ;
        }
        while( curr != NULL && curr->prn < prn )
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL)
        {
            prev->next = temp;
        }
        else if(curr==Front)
        {
            temp ->next = Front;
            Front = temp;
        }
        else
        {
            prev->next = temp;
            temp->next = curr;
        }
        return ;
    }
    int dequeue()
    {
        if(Front==NULL)
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int res = Front->data;
        Front = Front->next;
        return res;
    }
};
int main()
{
    pqueue pq;
    pq.insertq(10,3);
    pq.insertq(8,2);
    pq.insertq(5,1);
    pq.insertq(15,4);
    for(int i=0;i<4;i++) cout<<pq.dequeue()<<" ";

    return 0;
}
