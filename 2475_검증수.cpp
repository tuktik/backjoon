#include <iostream>

using namespace std;

int numArr[6];

int main()
{
	int sum =0;

	for(int i=0; i<5; i++)
	{
		cin>>numArr[i];
	}

	for(int i=0; i<5; i++)
	{
		sum+=(numArr[i]*numArr[i]);
	}

	cout<<sum%10<<endl;

	return 0;
}