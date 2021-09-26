#include<iostream>
using namespace std;

class Student
{
private:
	char name[10];
	char SID[12];
	int grade[3];

public:
	Student(char *stu_name, char *stu_sid, int stu_grade1, int stu_grade2, int stu_grade3)
	{
		int i = 0;
		while (stu_name[i])
		{
			name[i] = stu_name[i];
			i++;
		}

		i = 0;
		while (stu_sid[i])
		{
			SID[i] = stu_sid[i];
			i++;
		}

		grade[0] = stu_grade1;
		grade[1] = stu_grade2;
		grade[2] = stu_grade3;
	}

	void display()
	{
		cout << name << " " << SID << " " << grade[0] << " " << grade[1] << " " << grade[2]<<endl;
	}
};

int main() {
	Student* stu1, * stu2, * stu3;
	char name1[10], name2[10], name3[10];
	char num1[12], num2[12], num3[12];
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