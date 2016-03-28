#include <iostream>

using namespace std;

int checkArr[5005];

int main()
{
	int n;
	int m;

	cin >> n >> m;
	
	int search = -1;
	int outputCnt = 0;
	int manCnt = 0;
	cout << '<';
	while (outputCnt<n)
	{
		search++;
		if (checkArr[search%n] == 0)
		{
			manCnt++;
		}
		if (manCnt == m)
		{
			manCnt = 0;
			checkArr[search%n] = 1;
			outputCnt++;
			cout << search % n + 1;
			if (outputCnt != n)
				cout << ", ";
		}
	}
	cout << '>';


	return 0;
}