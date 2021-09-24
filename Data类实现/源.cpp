/*ʵ��������Date��������ȷ��ʾ�ꡢ�¡��ա�
�ڴ���������ͷ�ļ� CDate.h
�����������£�
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
      int year; //��
      int month; //��
      int day;  // ��
}

��Ҫʵ�ֹ��ɺ���Date(int y =1996,int m=1,int d=1)
�ڹ��캯���������ж�������º����Ƿ�Ϸ�
����Ϊ1~12���е�һ�� ����²��Ϸ������Invalid month! Ȼ������Ϊ1��
����������Ϸ��������Invalid day! Ȼ��������Ϊ1��
���� Date d(1993,13,32);
�����
Invalid month!�س�
Invalid day!�س�
�ٵ��� d.display()
�����
1993-1-1

���һ��NewDay()��Ա����������ǰDate��ʾ����������һ�졣
���磺Date d(1991,1,1);
      d.NewDay();
      d.display();
�����
1991-1-2

���һ��days(int year, int month)��Ա����,����ָ�������ж����졣
���� d.days(1991,1)
���أ�
31

����Ĵ����б���ʵ�������������������磺
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