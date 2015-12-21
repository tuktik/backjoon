#include <iostream>

using namespace std;

int main()
{
	int inputNum;

	cin >> inputNum;

	int i;

	for (i = 1; i < 30000; i++)
	{
		if (inputNum <= i*i)
			break;
	}
	int prev = i-1;
	int next = i;
	int resNum;
	if (inputNum <= 4)
		resNum = 4;
	else
	{
		if (inputNum <= prev*next)
		{
			resNum = (prev + next - 2) * 2;
		}
		else 
		{
			resNum = (next - 1) * 4;
		}
	}

	cout << resNum << endl;

	return 0;
}