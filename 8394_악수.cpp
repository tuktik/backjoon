#include <iostream>

using namespace std;

int nArr[10000005];

int main()
{
	int n;

	cin >> n;


	nArr[1] = 1;
	nArr[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		nArr[i] = (nArr[i - 1] + nArr[i - 2]) % 10;
	}

	cout << nArr[n] << endl;

	return 0;
}