#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int now_num = 2;

	while (n--)
	{
		now_num = now_num * 2 - 1;
	}

	cout << now_num*now_num << endl;

	return 0;
}