#include "iostream"
#include "vector"
#include "string"
using namespace std;

struct Info
{
	short int year;
	short int day;
	short int month;
};

bool IsLeapYear(int num)
{
	if ((num % 400 == 0) || (num % 4 == 0 && num % 100 != 0))
		return true;
	else
		return false;
}

int main()
{
	vector<Info> v;
	Info temp;
	for (int i = 2000; i <= 9999; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			if ((j == 1) || (j == 3) || (j == 5) || (j == 7) || (j == 8) || (j == 10) || (j == 12))
			{
				for (int k = 1; k <= 31; k++)
				{
					temp.year = i;
					temp.month = j;
					temp.day = k;
					v.push_back(temp);
				}
			}
			else if (j == 2)
			{
				if (IsLeapYear(i))
				{
					for (int k = 1; k <= 29; k++)
					{
						temp.year = i;
						temp.month = j;
						temp.day = k;
						v.push_back(temp);
					}
				}
				else
				{
					for (int k = 1; k <= 28; k++)
					{
						temp.year = i;
						temp.month = j;
						temp.day = k;
						v.push_back(temp);
					}
				}
			}
			else if ((j == 4) || (j == 6) || (j == 9) || (j == 11))
			{
				for (int k = 1; k <= 30; k++)
				{
					temp.year = i;
					temp.month = j;
					temp.day = k;
					v.push_back(temp);
				}
			}
		}
	}

	int days;
	while (cin >> days && days != -1)
	{
		string str;
		int n = days % 7;
		if (n == 1)
			str = "Sunday";
		else if (n == 2)
			str = "Monday";
		else if (n == 3)
			str = "Tuesday";
		else if (n == 4)
			str = "Wednesday";
		else if (n == 5)
			str = "Thursday";
		else if (n == 6)
			str = "Friday";
		else if (n == 0)
			str = "Saturday";
		cout << v[days].year << "-" ;
		if (v[days].month < 10)
		   cout << "0" << v[days].month << "-";
		else
		    cout << v[days].month << "-";
		if (v[days].day < 10)
			cout << "0" << v[days].day << " " << str << endl;
		else
			cout <<  v[days].day << " " << str << endl;
	}
}
