#include "Date.h"
#include "Time.h"

int main()
{
	int n;
	Date a;
	Time b;
	cin>>a;
	cout<<a;
	cout<<"Ngay mai la: "<<a.nextDate();
	cin>>b;
	cout<<b;
	return 0;
}
