#include<iostream>
using namespace std;

int c = 0;
double average_1 = 0, average_2 = 0, average_3 = 0;
class Student
{
private:
	char name[12] = {};
	char SID[10] = {};
	int grade[3] = {};
public:
	Student(char *stu_name, char *stu_sid, int stu_grade1, int stu_grade2, int stu_grade3)
	{
		int i = 0;
		while (stu_name[i]&&i<12)
		{
			name[i] = stu_name[i];
			i++;
		}

		i = 0;
		while (stu_sid[i]&&i<10)
		{
			SID[i] = stu_sid[i];
			i++;
		}

		grade[0] = stu_grade1;
		grade[1] = stu_grade2;
		grade[2] = stu_grade3;

		c++;
		average_1 += grade[0];
		average_2 += grade[1];
		average_3 += grade[2];
	}

	void display()
	{
		cout << name << " " << SID << " " << grade[0] << " " << grade[1] << " " << grade[2]<<endl;
	}

	double average1()
	{
		return average_1 / c;
	}

	double average2()
	{
		return average_2 / c;
	}

	double average3()
	{
		return average_3 / c;
	}
};

int main() 
{
	Student* stu1, * stu2, * stu3;
	char name1[12], name2[12], name3[12];
	char num1[10], num2[10], num3[10];
	int grade1[3], grade2[3], grade3[3];
	cin >> name1 >> num1 >> grade1[0] >> grade1[1] >> grade1[2];
	cin >> name2 >> num2 >> grade2[0] >> grade2[1] >> grade2[2];
	cin >> name3 >> num3 >> grade3[0] >> grade3[1] >> grade3[2];
	stu1 = new Student(name1, num1, grade1[0], grade1[1], grade1[2]);
	stu2 = new Student(name2, num2, grade2[0], grade2[1], grade2[2]);
	stu3 = new Student(name3, num3, grade3[0], grade3[1], grade3[2]);

	stu1->display();
	stu2->display();
	stu3->display();

	cout << "The average grade of course1:" << stu2->average1() << endl;
	cout << "The average grade of course2:" << stu2->average2() << endl;
	cout << "The average grade of course3:" << stu2->average3() << endl;
	return 0;
}

//LiWeiwei 200906294 88 75 91 ChenHanfu 200902164 86 78 93 ZhanGaolin 200908079 94 69 97