#include <iostream>

using namespace std;

int main()
{
	int num;
	int divNum=64;
	int count =0;
	cin>> num;


	while(num)
	{
		if(num/divNum==1)
		{
			count++;
			num = num % divNum;
		}

		divNum/=2;
		
		if(num==0)
			break;
	}

	cout<<count<<endl;

	return 0;
}