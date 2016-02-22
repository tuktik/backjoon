#include <iostream>
#include <algorithm>

using namespace std;

int n;

int nArr[10005];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nArr[i];
	}

	sort(nArr, nArr + n);

	int last = n - 1;
	int sum = 0;

	while (nArr[last] > 0)
	{
		if (nArr[last] != 1 && nArr[last - 1] >1) {
			sum += nArr[last] * nArr[last - 1];
			last -= 2;
		}
		else
		{
			sum += nArr[last];
			last --;
		}
	}

	int first = 0;

	while (nArr[first] < 0)
	{
		if (nArr[first] <= -1 && nArr[first + 1] <= -1) {
			sum += nArr[first] * nArr[first + 1];
			first += 2;
		}
		else if (nArr[first] <= -1 && nArr[first + 1] == 0 && (first+1 < n)) {
			sum += nArr[first] * nArr[first + 1];
			first += 2;
		}
		else
		{
			sum += nArr[first];
			first++;
		}
	}

	cout << sum << endl;
	//cout << sum << endl;

	/*for (int i = 0; i <n; i++)
	{
	cout << nArr[i] << endl;
	}*/

	return 0;
}