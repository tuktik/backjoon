#include <iostream>
#include <algorithm>

using namespace std;

int n;

int nArr[10005];

int main()
{
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nArr[i];
	}

	sort(nArr, nArr + n);

	int last = n - 1;

	while (nArr[last] >= 0)
	{
		if (nArr[last] != 1 && nArr[last - 1] != 1) {

		}
	}


	/*for (int i = 0; i <n; i++)
	{
	cout << nArr[i] << endl;
	}*/

	return 0;
}