#include<iostream>
using namespace std;

void showtime(int h, int m);

int main()
{
    showtime(9,28);
    return 0;
}

void showtime(int h, int m)
{
    cout<<"Time: "<<h<<" : "<<m<<endl;
}