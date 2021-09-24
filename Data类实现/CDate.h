#pragma once
#include<iostream>
using namespace std;

class Date 
{
public:
    Date(int y , int m , int d);
    int days(int year, int month);
    void NewDay();
    void display()
    {
        cout << year << "-" << month << "-" << day << endl;
    };
private:
    int year; //Äê
    int month; //ÔÂ
    int day;  // ÈÕ
};