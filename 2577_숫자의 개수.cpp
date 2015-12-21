#include <iostream>

using namespace std;

int countArr[10];

int main()
{
	int num;

	int a, b, c;
	int temp;
	
	cin>> a >> b >>c;

	num = a*b*c;

	while(num>0)
	{
		temp = num%10;
		num = num/10;

		countArr[temp]++;
	}

	for(int i =0 ; i<10; i++)
	{
		cout<<countArr[i]<<endl;
	}
	
	return 0;
}