#include <iostream>

using namespace std;

int inputArr[105];
int targetArr[105];

int fo_direction[105];
int re_direction[105];

int main()
{
	int n;
	
	char tmp;


	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		inputArr[i] = tmp - '0';
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		targetArr[i] = tmp - '0';
	}

	for (int i = 0; i < n; i++)
	{
		fo_direction[i] = targetArr[i] - inputArr[i];
		if (fo_direction[i] < 0)
			fo_direction[i] = 10 - fo_direction[i];

		re_direction[i] = inputArr[i] - targetArr[i];
		if (re_direction[i] < 0)
			re_direction[i] = 10 - re_direction[i];

	}

	


	return 0;
}