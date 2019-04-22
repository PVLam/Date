#ifndef TIME_H 
#define TIME_H
#include "Date.h"

class Time: public Date
{
private:
	int Hour, Minute;
public:
	Time(): Date(), Hour(0), Minute(0){}
	Time(int a, int b, int c, int d, int e): Hour(a), Minute(b), Date(c,d,e){}
	void set(int a, int b)
	{
		this->Hour = a;
		this->Minute = b;
	}
	
	int getHour()const
	{
		return this->Hour;
	}
	int getMinute()const
	{
		return this->Minute;
	}

	bool checkTime()
	{
		int a = getHour();
		int b = getMinute();
		if (a<0 || a>23)
			return false;
		if (b<0 || b>59)
			return false;
		return true;
	}

	friend ostream &operator <<(ostream & out, const Time &b)
	{
		out<<b.getHour()<<':'<<b.getMinute()<<' '<<b.day<<'-'<<b.month<<'-'<<b.year<<endl;
		return out;
	}

	friend istream &operator >>(istream &in, Time &x)
	{
		do
		{
			cout<<"Nhap ngay: "; in>>x.day;
			cout<<"Nhap thang: "; in>>x.month;
			cout<<"Nhap nam: "; in>>x.year;
		}while (!x.checkDate());
		do
		{	
			cout<<"Nhap gio: "; in>>x.Hour;
			cout<<"Nhap phut: "; in>>x.Minute;
		}while (!x.checkTime());
		return in;   
	}

	~Time(){}
};
#endif