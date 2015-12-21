#include <iostream>

using namespace std;

int arr_prime[4];
int prime_num[1000000];

void prime_select()
{
	prime_num[0]=1;
	prime_num[1]=1;
	for(int i =2 ; i< 1000000; i++)
	{
		if(prime_num[i]==1)
			continue;
		else
		{
			for( int j =2; i*j<1000000; j++)
			{
				prime_num[i*j]=1;
			}
		}
	}
}

bool is_prime(int num)
{
	if(prime_num[num]==0)
		return 1;
	else
		return 0;
}

int main()
{
	int num;

	prime_select();

	cin>> num;

	for(int i = num/2; i<num; i++)
	{
		for(int j = i-2; j>=i/2; j--)
		{
			if(is_prime(j)&&is_prime(i-j))
			{
				//cout<<prime_num[35];
				arr_prime[0]=j;
				arr_prime[1]=i-j;
				break;
			}
		}
		for(int j = num - i -2 ; j>=i/2; j--)
		{
			if(is_prime(j)&&is_prime(num-i-j))
			{
				arr_prime[2]=j;
				arr_prime[3]=num-i-j;
				break;
			}
		}
		if(arr_prime[0]!=0 && arr_prime[1]!=0 && arr_prime[2]!=0 && arr_prime[3]!=0)
		{
			cout<<arr_prime[0]<<" "<<arr_prime[1]<<" "<<arr_prime[2]<<" "<<arr_prime[3]<<endl;
			return 0;
		}
		else
		{
			arr_prime[0]=0;
			arr_prime[1]=0;
			arr_prime[2]=0;
			arr_prime[3]=0;
		}
	}

	cout<<-1<<endl;

	return 0;
}