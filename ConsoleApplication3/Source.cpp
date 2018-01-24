#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

float f();
void findMax();
int isLeap(int year);
void getCountDaysInMonth_5(int year, int month, int day);
int getCountDaysInMonth(int month, int year);
int Task9(char letter);

void main()
{
	setlocale(LC_ALL, "Rus");



	int nz = 0;
	do
	{
		cout << "������� ����� �������: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			//int difTime = f(9, 0, 0); 
			cout << f();
			cout << endl;
		}
		break;
		case 2:
			findMax();
			break;

		case 5:
		{
			cout << "������� ���: ";
			int year;
			cin >> year;

			cout << "������� �����: ";
			int month;
			cin >> month;

			cout << "������� ����: ";
			int day;
			cin >> day;

			getCountDaysInMonth_5(year, month, day);
		}
		break;

		case 6:
		{
			char letter;
			cin >> letter;
			
			int coutLetter = Task9(letter);
			cout << "���������� ��������� ���� "
				<< letter
				<< " = "
				<< coutLetter
				<< endl;
		}
		break;
		}

	} while (nz > 0);
}


/*
�������� ������� int f(int h, int m, int s),
������� ��������� ��� ����� ���������
(���� h, ������ m � ������� s) �
���������� ���������� ������,
��������� � ������ ���
*/
float f()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	/*struct tm {
	int tm_sec;   // seconds of minutes from 0 to 61
	int tm_min;   // minutes of hour from 0 to 59
	int tm_hour;  // hours of day from 0 to 24

	int tm_mday;  // day of month from 1 to 31
	int tm_mon;   // month of year from 0 to 11
	int tm_year;  // year since 1900
	int tm_wday;  // days since sunday
	int tm_yday;  // days since January 1st
	int tm_isdst; // hours of daylight savings time
	}*/

	int startDayH = 6;
	int startDayM = 0;
	int startDayS = 0;

	float totalSecodns = (timeinfo->tm_hour - startDayH) * 3600;
	totalSecodns += (timeinfo->tm_min) * 60;

	return totalSecodns;
}

//���� ����� ��������� �����.
//���������� ������������ �� ���. 
//(���������� �������, ��������� �������� �� ���� ��������� �����.)
void findMax()
{
	srand(time(NULL));
	int a[6];
	int max = 0;

	for (int i = 0; i < 6; i++)
	{
		a[i] = -1 + rand() % 50;
		if (max < a[i])
			max = a[i];
	}

	cout << "max=" << max << endl;
}

/*
���� ���������� ��� ��������������� ����� ������������ �������:
g (���), m (���������� ����� ������) � n (�����).

�� �������� g, n � m ����������
a.	���� ����������� ���;
b.	���� ���������� ���;
c.  o��������� �������, �������������� ���������� ���� � ��� ��� ���� ������
*/
void getCountDaysInMonth_5(int year, int month, int day)
{
	int leap = isLeap(year);

	//���� ����������� ���;
	if (day < 1 && day >31)
	{
		cout << "������� ���������� ����";
	}
	else if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;

		if (month == 1)
			month = 12;
		else
			month = month - 1;

		day = getCountDaysInMonth(month, year);
	}
	else
		day = day - 1;

	cout << "���� ����������� ���: " <<
		day << "." <<
		month << "." <<
		year << endl;
}

//������� ������� ���������� ���������� �� ���
int isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

//������� ������� ���������� ���������� ���� � ������
int getCountDaysInMonth(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
#pragma region MyRegion
		//1-��
		int leap = isLeap(year);
		if (leap == 1)//����������
			return 29;
		else
			return 28;

		//2
		//if (isLeap(year) == 1)//����������
		//	return 29;
		//else
		//	return 28;

		//3
		//return isLeap(year) == 1 ? 29 : 28;
#pragma endregion
	}
	else
		return 31;
}


/*
��������� ��������� ��� ���������� ������ ���������� �������� 
�����  � ���� �������� ������������. 
(���������� ������� ��� ������� ���������� ��������� 
����� � �����������.)
*/
int Task9(char letter)
{
	char str1[20];
	
	for (int i = 0; i < 20; i++)
	{
		str1[i] = getchar();
	}

	int countLetter = 0;
	for (int i = 0; i < 20; i++)
	{
		if (letter == str1[i])
			countLetter++;
	}
	


	cout << "������� ������ ������";
	char str2[20];
	char *result;
	result = gets_s(str2);

	for (int i = 0; i < 20; i++)
	{
		if (letter == str2[i])
			countLetter++;
	}


	return countLetter;
}


//
//void G(int month, int year)
//{
//	int numberOfDays;
//	if (month == 4 || month == 6 || month == 9 || month == 11)
//		numberOfDays = 30;
//	else if (month == 2)
//	{
//		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//		if (isLeapYear)
//			numberOfDays = 29;
//		else
//			numberOfDays = 28;
//	}
//	else
//		numberOfDays = 31;
//}
//
//
///* function to generate and return random numbers */
//int * getRandom() {
//
//	static int  r[10];
//	int i;
//
//	/* set the seed */
//	srand((unsigned)time(NULL));
//
//	for (i = 0; i < 10; ++i) {
//		r[i] = rand();
//
//		cout << "r[" << i << "] = " << r[i] << "\n";
//	}
//
//	return r;
//}
//
//void invokeArr()
//{
//
//	int *p;
//	int i;
//
//	p = getRandom();
//
//	for (i = 0; i < 10; i++) {
//		cout << "*(p + " << i << ") : " << *(p + i) << "\n";
//	}
//}