#include <iostream>

using namespace std;

int prime[1001];

void eratos()
{
	prime[0]=1;
	prime[1]=1;

	for(int i =2; i< 1001; i++)
	{
		if(prime[i]==0)
		{
			for(int j = 2; i*j<1001; j++)
			{
				prime[i*j]=1;
			}
		}
	}
}

int main()
{
	int num;
	int arr[100];
	cin>> num;

	for(int i = 0 ; i< num; i++)
	{
		cin>> arr[i];
	}

	eratos();

	int count =0;

	for(int i = 0 ; i< num; i++)
	{
		if(prime[arr[i]]==0)
			count++;
	}

	cout<<count<<endl;


	return 0;
}