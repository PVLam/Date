#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
protected:
	int day, month, year;
public:
	Date(): day(1), month(1), year(1){}
	Date(int a, int b, int c): day(a), month(b), year(c){}
	void set(int a, int b, int c)
	{
		this->day = a;
		this->month = b;
		this->year = c;
	} 
	void Input()
	{
		int a,b,c;
		do
		{
			cout<<"Nhap ngay, thang, nam: "<<endl; cin>>a>>b>>c;
			set(a,b,c);
		}while(a<=0 || a>31 || b<=0 || b>12 || c<=0 ||(a>29 && b==2));
	}

	int getDay()const
	{
		return this->day;
	}
	int getMonth()const
	{
		return this->month;
	}
	int getYear()const
	{
		return this->year;
	}

	Date nextDate()
	{
		Date next;
		int x = getDay();
		int y = getMonth();
		int z = getYear();
		int max;
		if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
			max = 31;
		else if (y == 2)
			if ((( z%4 == 0) && (z%100 != 0)) || (z%400 == 0))  // true -> nam nhuan
				max = 29;
			else
				max = 28;
		else
			max = 30;
		if (x == max) //vao th ngay cuoi thang
			if (y == 12)
				next.set(1,1,z+1); //thang = 12
			else
				next.set(1,y+1,z); //thang != 12
		else if (x<max) //th khong phai ngay cuoi thang
			next.set(x+1,y,z);
		return next;
	}

	friend ostream &operator <<(ostream & out, const Date &b)
	{
		out<<b.getDay()<<'-'<<b.getMonth()<<'-'<<b.getYear()<<endl;
		return out;
	}

	friend istream &operator >>(istream &in, Date &x)
	{
		cout<<"Nhap ngay: "; in>>x.day;
		cout<<"Nhap thang: "; in>>x.month;
		cout<<"Nhap nam: "; in>>x.year;
		return in;   
	}

	~Date(){}
};
#endif