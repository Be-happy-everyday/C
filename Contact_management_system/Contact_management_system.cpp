#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

// - 封装函数显示该界面 如 void showMenu()
// - 在main函数中调用封装好的函数

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满,如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满,无法添加!" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别: " << endl;
		cout << "1 --- 男 " << endl;
		cout << "2 --- 女 " << endl;
		int sex = 0;
		
		while (true)
		{
			//如果输入的是 1 或者 2 可以退出循环, 因为输入是正确值
			//如果输入有误,重新输入
 			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误,请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄: " << endl;
		int age = 0;
		while(true)
		{
			cin >> age;
			if (age >= 0 && age <= 140)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误,请重新输入" << endl;
		}
		//电话
		cout << "请输入联系电话: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");
	}
}

//2.显示所有联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0,如果为0,提示记录为空
	//如果不为空,显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名:  " << abs->personArray[i].m_Name << "\t";
			cout << "性别:  " << (abs->personArray[i].m_Sex == 1? "男":"女") << "\t";
			cout << "年龄:  " << abs->personArray[i].m_Age << "\t";
			cout << "电话:  " << abs->personArray[i].m_Phone << "\t";
			cout << "住址:  " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");//清屏
}

//检测联系人是否存在,如果存在返回联系人所在数组的位置,否则返回-1
int isExist(Addressbooks *abs, string name)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
		return -1;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			//get it
			if (abs->personArray[i].m_Name == name)
			{
				return i;//find people,and return the position
			}
		}
		return -1;
	}

}

//3.删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//refresh the number of address list
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//4.查找指定联系人信息
void findPerson(Addressbooks*abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	
	if (ret != -1)
	{
		cout << "姓名:  " << abs->personArray[ret].m_Name << "\t";
		cout << "性别:  " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:  " << abs->personArray[ret].m_Age << "\t";
		cout << "电话:  " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址:  " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//5.修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin>>name;
	int ret = isExist(abs, name);

	if (ret != 1)
	{
		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别: " << endl;
		cout << "1 --- 男 " << endl;
		cout << "2 --- 女 " << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是 1 或者 2 可以退出循环, 因为输入是正确值
			//如果输入有误,重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误,请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//地址
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//6.清空所有噢联系人
void cleanup(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");

}

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1. 添加联系人  *****" << endl;
	cout << "*****  2. 显示联系人  *****" << endl;
	cout << "*****  3. 删除联系人  *****" << endl;
	cout << "*****  4. 查找联系人  *****" << endl;
	cout << "*****  5. 修改联系人  *****" << endl;
	cout << "*****  6. 清空联系人  *****" << endl;
	cout << "*****  0. 退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录当前人员个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入的变量

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1. 添加联系人
			addPerson(&abs);//利用地址传递
			break;
		case 2://2. 显示联系人
			showPerson(&abs);
			break;
		case 3://3. 删除联系人
			deletePerson(&abs);
			break;
		case 4:// 4. 查找联系人
			findPerson(&abs);
			break;
		case 5://5. 修改联系人
			modifyPerson(&abs);
			break;
		case 6://6. 清空联系人
			cleanup(&abs);
			break;
		case 0://0. 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}