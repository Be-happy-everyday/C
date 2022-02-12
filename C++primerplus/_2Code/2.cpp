#include<iostream>
using namespace std;

int convert(int n);

int main()
{
    int n;
    cin >> n;
    cout<< n <<" long = "<<convert(n)<<endl;
    return 0;
}

int convert(int n)
{
    return 220 * n;
}