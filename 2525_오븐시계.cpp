#include <iostream>

using namespace std;

int main()
{
	int hour, min;
	int input;
	int carry=0;

	cin>> hour >>min;
	
	cin>> input;


	min = min+ input%60;

	if(min>=60)
	{
		min =min-60;
		carry=1;
	}

	hour = (hour+input/60+carry)%24;

	cout<<hour<<" "<<min;

	return 0;
}