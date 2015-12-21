#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int testNum;
	int num=1;
	int count=1;

	while(cin>>testNum)
	{
		num=1;
		count=1;
		while(num>testNum)
		{
			num+=pow((double)10,count);
			count++;
		}
		
		while(num%testNum!=0)
		{
			num=num%testNum;
			num=num*10+1;
			count++;
		}
		cout<<count<<endl;

	}


	return 0;
}