#include <iostream>

using namespace std;

long long get_count(long long num, int div)
{
	long long sum=0;

	while(num!=0)
	{
		//temp= num/5;
		num=num/div;
		sum+=num;
	}

	return sum;
}

int main()
{
	long long n, m;

	cin>>n >> m;

	int five_count = get_count(n,5)-get_count(m,5)-get_count(n-m,5);
	int two_count = get_count(n,2)-get_count(m,2)-get_count(n-m,2);

	
	if(five_count<two_count)
		cout<<five_count<<endl;
	else
		cout<<two_count<<endl;
	//cout<<five_count<two_count?five_count:two_count<<endl;
	


	return 0;
}