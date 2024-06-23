#include<iostream>
using namespace std;
void Rotate(string &str)
{
    for(int i=0;i<4;i++)
    {
        swap(str[i],str[i+1]);
        cout<<str<<endl;

    }

}
int main()
{

    char name[6];
    string name2;
    cin>>name2;
    int n=10;
    Rotate(name2);
//    while(n>0)
//    {
//        cout<<name<<"....."<<endl;
//        Rotate(name);
//        n--;
//    }
    return 0;
}
