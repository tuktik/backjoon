#include <iostream>

using namespace std;

long long fac(long long num)
{
	if(num==0)
		return 1;
	else
		return num*fac(num-1);
}

long long fac(long long num, int target)
{
	if(num==target)
		return 1;
	else
		return num*fac(num-1,target);
}

int main()
{
	int testNum;

	long long n,m;

	cin>>testNum;

	for(int i=0; i<testNum;i++)
	{
		cin>>n>>m;

		if(m-n>n)
		{
			cout<<fac(m,m-n)/fac(n)<<endl;
		}
		else
		{
			cout<<fac(m,n)/fac(m-n)<<endl;
		}
	}

	return 0;
}