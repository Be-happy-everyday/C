#include<iostream>
using namespace std;

float cconvertf(int c);

int main()
{
    cout<<"Please enter a Celsius value: ";
    int Celsius = 0;
    cin>>Celsius;
    cout<<Celsius<<" degrees Celsius is "<<cconvertf(Celsius)<<" degrees Fahrenheit.";
    return 0;
}

float cconvertf(int c)
{
    return (1.8 * c + 32.0);
}