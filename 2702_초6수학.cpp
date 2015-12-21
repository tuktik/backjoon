#include <iostream>

using namespace std;

int uclid(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	else
	{
		return uclid(b, a%b);
	}
}

int main()
{
	int testNum;

	cin >> testNum;

	for (int i = 0; i < testNum; i++)
	{
		int a, b;

		cin >> a >> b;

		int gcd = uclid(a, b);

		cout << a / gcd * b / gcd * gcd << " " << uclid(a, b) << endl;
	}

	return 0;
}