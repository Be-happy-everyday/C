#include<iostream>
using namespace std;

long long lconverta(float l);

int main()
{
    cout<<"Enter the number of light years: ";
    float light = 0;
    cin>>light;
    cout<<light<<" light years = "<<lconverta(light)<<" astronomical units."<<endl;
    return 0;
}

long long lconverta(float l)
{
    return 63240 * l;
}