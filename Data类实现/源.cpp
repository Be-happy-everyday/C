/*实现日期类Date，它能正确表示年、月、日。
在代码中引入头文件 CDate.h
它的内容如下：
class Date{
 public:
       Date(int y =1996,int m=1,int d=1){};
       int days(int year,int month){};
       void NewDay();
 void display()
 {
    cout<<year<<"-"<<moth<<"-"<<day<<endl;
 }
 private:
      int year; //年
      int month; //月
      int day;  // 日
}

需要实现构成函数Date(int y =1996,int m=1,int d=1)
在构造函数内依次判断输入的月和日是否合法
即月为1~12月中的一个 如果月不合法则输出Invalid month! 然后将月置为1。
如果天数不合法，则输出Invalid day! 然后将天数置为1。
例如 Date d(1993,13,32);
输出：
Invalid month!回车
Invalid day!回车
再调用 d.display()
输出：
1993-1-1

设计一个NewDay()成员函数，将当前Date表示的日期增加一天。
例如：Date d(1991,1,1);
      d.NewDay();
      d.display();
输出：
1991-1-2

设计一个days(int year, int month)成员函数,返回指定年月有多少天。
例如 d.days(1991,1)
返回：
31

在你的代码中必须实现以上三个方法，例如：
#include "CDate.h"
Date::Date(int y=1996,int m=1 ,int d=1){
    ...
}
int  Date::days(int year,int month){
    ...
}
void Date::NewDay(){
  ...
}
*/

#include "CDate.h"

bool judgement(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;
    else return false;
}

Date::Date(int y , int m , int d ) 
{
    if (m < 1 || m>12)
    {
        m = 1;
        cout << "Invalid month!" << endl;
    }
    month = m;

    if (d<28 || d>days(y, m))
    {
        d = 1;
        cout << "Invalid day!" << endl;
    }
    day = d;
    year = y;
}

void Date::NewDay() 
{
    day++;
    if (day > days(year, month))
    {
        day = 1;
        month++;
    }

    if (month > 12)
    {
        month = 1;
        year++;
    }
}

int Date::days(int year, int month)
{
    int days = 0;
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: days = 31; break;
        case 4:
        case 6:
        case 9:
        case 11: days = 30; break;
        case 2:
        {
            if (judgement(year))
            {
                days = 29; break;
            }
            else
            {
                days = 28; break;
            }

        }
    }

    return days;
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;

    Date day(y, m, d);
    day.display();

    day.NewDay();
    day.display();

    return 0;

}