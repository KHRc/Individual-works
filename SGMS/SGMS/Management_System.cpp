#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
#define M 200
FILE* fpw = NULL;
typedef struct stu
{
	char name[10];//姓名
	char sex[10];//性别
	char num[10];//学号
	int score[7];//语文，英语，数学，物理，化学，生物，平时成绩
	int ave;//平均分
	int total;//总分
}STU;
class Student
{
public:
	Student();
	void input();//数据输入
	void print();//输出
	void output(char curse[], int t);//文件
	void look();//浏览
	void find();//查找
	void Delete();//删除
	void design();//修改
	friend ostream& operator<<(ostream& os, STU& stu);
	friend istream& operator>>(istream& is, STU& stu);
private:
	STU stu;
};
Student s[M];
Student::Student()
{
	for (int i = 0; i < M; i++)
	{
		strcpy(s[i].stu.name, " ");
		strcpy(s[i].stu.sex, " ");
		strcpy(s[i].stu.num, " ");
		s[i].stu.total = 0;
		s[i].stu.ave = 0;
		for (int j = 0; j < 7; j++)
		{
			s[i].stu.score[j] = 0;
		}
	}
}
void Student::input()//学生成绩录入函数
{
	char ju = 'Y';
	int i = 0;
	cout << "请输入学生信息：" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分 " << endl;
	cout << "----------------------------------------------------------------" << endl;
	while (ju == 'Y' || ju == 'y')
	{
		cout << "好的，请输入：" << endl;
		int sum = 0;
		cin >> s[i].stu;
		for (int j = 0; j < 6; j++)
		{
			sum = sum + s[i].stu.score[j];
		}
		s[i].stu.ave = (int)(sum / 6);
		s[i].stu.total = (int)(0.3 * s[i].stu.score[6] + 0.7 * s[i].stu.ave);
		i++;
		cout << "继续请输入'Y'或'y',否则请输入任意字符" << endl;
		cin >> ju;
	}
}
void Student::output(char curse[], int t)
{
	char a[50] = "C:\\Users\\Administrator\\Desktop\\", b[5] = ".txt";
	strcat(curse, b);
	strcat(a, curse);

	fpw = fopen(a, "w+");
	if (fpw == NULL)
		cout << "文件无法打开" << endl;
	else
	{

		for (int i = 0; i < M; i++)
		{
			if (s[i].stu.num[6] == curse[1])
			{
				fputs(s[i].stu.name, fpw);//姓名
				fputs(s[i].stu.sex, fpw);//性别
				fputs(s[i].stu.num, fpw);//学号
				fprintf(fpw, "%d\n", s[i].stu.score[t]);//成绩
			}
		}
		fclose(fpw);
		cout << "文件保存成功" << endl;
	}
}
void Student::look()//查看学生成绩函数
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有条件可以匹配" << endl;
	else
	{
		char curse[20], cu[8];
		int t;
		cout << "请输入您要查看的班级代码及科目,如1班语文则输入c1yuwen:" << endl;
		cin >> curse;
		for (int i = 0; i < 8; i++)
		{
			cu[i] = curse[i + 2];
		}
		if (strcmp(cu, "yuwen") == 0)
		{
			t = 0;
			output(curse, t);
		}
		if (strcmp(cu, "yingyu") == 0)
		{
			t = 1;
			output(curse, t);
		}
		if (strcmp(cu, "shuxue") == 0)
		{
			t = 2;
			output(curse, t);
		}
		if (strcmp(cu, "wuli") == 0)
		{
			t = 3;
			output(curse, t);
		}
		if (strcmp(cu, "huaxue") == 0)
		{
			t = 4;
			output(curse, t);
		}
		if (strcmp(cu, "shengwu") == 0)
		{
			t = 5;
			output(curse, t);
		}
	}
}
void Student::find()
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有条件可以匹配" << endl;
	else
	{
		char na[10], b = 'Y';
		int t, k;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分  总评 " << endl;
		cout << "----------------------------------------------------------------------" << endl;
		while (b == 'Y' || b == 'y')
		{
			cout << "请输入您要查找的学生的姓名:" << endl;
			cin >> na;//输入要查找的学生的姓名
			for (int i = 0; i < M; i++)
			{
				if (strcmp(s[i].stu.name, na) == 0)
				{
					t = 1;
					k = i;
					break;
				}
				else
					t = 0;
			}
			if (t == 1)
				cout << s[k].stu;
			if (t == 0)
				cout << "学生信息中没有您要查找的同学" << endl;
			cout << "是否继续进行查找,如是，请输入'Y'或'y',否则请输入任意字符" << endl;
			cin >> b;
		}
	}
}
void Student::design()//学生成绩修改函数
{
	int sum = 0;
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		char a[10], n = 'Y';
		int  t, k;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分  总评 " << endl;
		cout << "--------------------------------------------------------------------" << endl;
		while (n == 'Y' || n == 'y')
		{
			cout << "请输入需要修改成绩的学生姓名：" << endl;
			cin >> a;
			for (int i = 0; i < M; i++)
			{
				if (strcmp(s[i].stu.name, a) == 0)
				{
					t = 1;
					k = i;
					break;
				}
				else
					t = 0;
			}
			if (t == 1)
				cout << s[k].stu << endl;
			if (t == 0)
				cout << "学生信息中没有此同学";
			if (t == 1)
			{
				cout << "请输入修改后该学生的姓名：" << endl;
				cin >> a;
				strcpy(s[k].stu.name, a);
				cout << "请输入修改后该学生的性别：" << endl;
				cin >> a;
				strcpy(s[k].stu.sex, a);
				cout << "请输入修改后该学生的学号：" << endl;
				cin >> a;
				strcpy(s[k].stu.num, a);
				cout << "请按顺序输入修改后该学生的各项成绩：" << endl;
				for (int i = 0; i < 7; i++)
				{
					cin >> s[k].stu.score[i];
				}
				for (int j = 0; j < 6; j++)
				{
					sum = sum + s[k].stu.score[j];
				}
				s[k].stu.ave = (int)(sum / 6);
				s[k].stu.total = (int)(0.3 * s[k].stu.score[6] + 0.7 * s[k].stu.ave);
				cout << "修改完成" << endl;
				cout << "修改后信息" << endl;
				cout << s[k].stu;
			}
			cout << "是否继续进行修改,如是，请输入'Y'或'y'，如否，请输入任意字符" << endl;
			cin >> n;
		}
	}
}
ostream& operator<<(ostream& os, STU& stu)//输出运算符重载
{
	os << stu.name << "  " << stu.sex << "   " << stu.num << "   " << stu.score[0] << "    " << stu.score[1] << "    " << stu.score[2] << "    " << stu.score[3] << "    " << stu.score[4] << "    " << stu.score[5] << "    " << stu.score[6] << "    " << stu.total << endl;
	return os;
}
istream& operator>>(istream& is, STU& stu)//输入运算符重载
{
	is >> stu.name >> stu.sex >> stu.num >> stu.score[0] >> stu.score[1] >> stu.score[2] >> stu.score[3] >> stu.score[4] >> stu.score[5] >> stu.score[6];
	return is;
}
void Student::Delete()//学生信息删除函数
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		char na[10];
		char q = 'Y';
		while (q == 'Y' || q == 'y')
		{
			cout << "请输入需要删除的同学的姓名：";
			cin >> na;
			for (int i = 0; i < M; i++)
			{
				if (strcmp(s[i].stu.name, na) == 0)//判断是否相等
				{
					for (int j = i; j < M - 1; j++)
					{
						strcpy(s[j].stu.name, s[j + 1].stu.name);
						strcpy(s[j].stu.sex, s[j + 1].stu.sex);
						strcpy(s[j].stu.num, s[j + 1].stu.num);
						s[j].stu.total = s[j + 1].stu.total;
						for (int k = 0; k < 7; k++)
						{
							s[j].stu.score[k] = s[j + 1].stu.score[k];
						}

					}
					break;//跳出循环
				}
				else
					cout << "没有该学生" << endl;
			}
			cout << "删除完成" << endl;
			cout << "是否继续进行删除操作，如是，请输入'Y'或'y';如否，请输入‘N’或'n'" << endl;
			cin >> q;
		}
		cout << "删除后的学生信息表为：" << endl;
		print();
	}
}
void Student::print()
{
	int t = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分  总评 " << endl;
	cout << "----------------------------------------------------------------------" << endl;
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		for (int i = 0; i < M; i++)
		{
			if (strcmp(s[i].stu.name, " ") != 0)
			{
				cout << s[i].stu;
			}
		}
		cout << "输出完成" << endl;
	}
}
void headline()
{
	cout << endl;
	cout << endl;

	cout << "\t\t\t【学生成绩管理系统主菜单】" << endl;
	cout << "\n\n\t\t\t\t1、学生成绩录入" << endl;
	cout << "\t\t\t\t2、学生成绩浏览" << endl;
	cout << "\t\t\t\t3、学生成绩查询" << endl;
	cout << "\t\t\t\t4、学生成绩修改" << endl;
	cout << "\t\t\t\t5、学生成绩删除" << endl;
	cout << "\t\t\t\t6、学生成绩保存" << endl;
	cout << "\t\t\t\t0、退出系统" << endl;
	cout << "\n\t\t\t请输入0-6，选择对应功能：" << endl;

}
int main()
{
	Student su;
	headline();
	char x = 'Y';
	int select;
	while (x == 'Y' || x == 'y')
	{
		system("cls");
		headline();
		cout << "请选择您要进行的操作:" << endl;
		cin >> select;
		switch (select)
		{
		case 0:break;
		case 1:su.input(); break;
		case 2:su.print(); break;
		case 3:su.find(); break;
		case 4:su.design(); break;
		case 5:su.Delete(); break;
		case 6:su.look(); break;
		default:cout << "error"; break;
		}
		cout << "是否继续进行其他操作，如是请输入'Y'或'y'，否则请输入任意字母" << endl;
		cin >> x;
		return 0;
	}
}
