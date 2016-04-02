#include <iostream>

using namespace std;

int get_const(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int get_numcount(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return cnt;
}

int main()
{

	int n;
	int min = 99999999;
	cin >> n;

	int numCnt = get_numcount(n);
	
	for (int i = 1; i <= numCnt * 9; i++)
	{
		if (get_const(n - i) == i)
		{
			if (min > n - i)
				min = n - i;
		}
	}
	if (min == 99999999)
		cout << 0 << endl;
	else
		cout << min << endl;

	return 0;
}