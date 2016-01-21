#include <iostream>

using namespace std;

bool numArr[2010];

int main()
{
	int n;

	cin >> n;
	
	int num;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		numArr[num + 1000]=1;
	}

	for (int i = 0; i < 2010; i++)
	{
		if (numArr[i] == 1)
			cout << i - 1000 << " ";
	}
	cout << endl;

}