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
	void Input()
	{
		int a,b;
		do
		{
			cout<<"Nhap gio, phut: "<<endl; cin>>a>>b;
			this->Hour = a;
			this->Minute = b;
		}while(b>=60);
	}
	
	int getHour()const
	{
		return this->Hour;
	}
	int getMinute()const
	{
		return this->Minute;
	}

	friend ostream &operator <<(ostream & out, const Time &b)
	{
		out<<b.getHour()<<':'<<b.getMinute()<<' '<<b.day<<'-'<<b.month<<'-'<<b.year<<endl;
		return out;
	}

	friend istream &operator >>(istream &in, Time &x)
	{
		cout<<"Nhap ngay: "; in>>x.day;
		cout<<"Nhap thang: "; in>>x.month;
		cout<<"Nhap nam: "; in>>x.year;
		cout<<"Nhap gio: "; in>>x.Hour;
		cout<<"Nhap phut: "; in>>x.Minute;
		return in;   
	}

	~Time(){}
};
#endif