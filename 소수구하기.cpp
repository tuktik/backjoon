#include <iostream>

using namespace std;

int prime[1000001];

int main()
{
	int num1, num2;

	cin>> num1 >> num2;

	prime[0]=1;
	prime[1]=1;

	for(int i =2; i<=num2; i++)
	{
		if(prime[i]==0)
		{
			if(i>=num1 && i<=num2)
			{
				cout<<i<<endl;
			}
			for(int j =2; i*j<=num2; j++)
			{
				prime[i*j]=1;
			}
		}
	}

	return 0;
}