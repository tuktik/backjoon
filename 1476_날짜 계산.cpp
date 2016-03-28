#include <iostream>

using namespace std;

int main()
{
	int e, s, m;

	cin >> e >> s >> m;

	int k = 0;

	while (1)
	{
		int nowNum = 28 * k + s;

		if ((nowNum % 15) == (e % 15) && (nowNum % 19) == (m % 19))
		{
			cout << nowNum << endl;
			break;
		}
		k++;
	}

	return 0;
}