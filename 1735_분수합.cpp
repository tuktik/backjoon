#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return getGCD(b, a%b);
}

int main()
{
	int mole1, denomi1;
	int mole2, denomi2;
	int sum_mole, sum_denomi;

	cin >> mole1 >> denomi1;
	cin >> mole2 >> denomi2;

	sum_mole = mole1*denomi2 + mole2*denomi1;
	sum_denomi = denomi1*denomi2;

	int gcd = getGCD(sum_mole, sum_denomi);

	if (gcd != 1)
	{
		sum_mole /= gcd;
		sum_denomi /= gcd;
	}

	cout << sum_mole << " " << sum_denomi << endl;

	return 0;
}