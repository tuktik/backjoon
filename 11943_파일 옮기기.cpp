#include <iostream>

using namespace std;

int main()
{
	int a, b;
	int c, d;

	cin >> a >> b;
	cin >> c >> d;

	if (a + d > b + c)
	{
		cout << b + c << endl;
	}
	else
	{
		cout << a+d << endl;
	}

	return 0;
}