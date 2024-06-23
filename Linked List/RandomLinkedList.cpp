#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node next;
    node(int data,node next)
    {
        this->data = data;
        this->next = next;
    }
};
int main()
{
    node first = new node(10,NULL);

    return 0;
}
