#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num;
	int output=1;
	int divNumsize=1;
	
	cin>> num;

	for(int i =1; i<=num; i++)
	{
		divNumsize = log10((double)i);
		output*=i;
		while(output%10==0)
		{
			output=output/10;
		}
		output=output%(int)pow(10.0,divNumsize+1);
	}

	cout<<output%10<<endl;

	return 0;
}