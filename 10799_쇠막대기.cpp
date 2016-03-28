#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char arr[100005];

int main()
{
	scanf("%s", &arr);

	int stickCount = 0;
	int subStick = 0;

	int sLen = strlen(arr);
	
	bool prevStick = false;

	for (int i = 0; i < sLen; i++)
	{
		if (arr[i] == '(')
		{
			stickCount++;
			prevStick = true;
		}
		else if(arr[i]==')' && prevStick==true)
		{
			stickCount--;
			prevStick = false;
			subStick += stickCount;
		}
		else
		{
			stickCount--;
			subStick++;
		}
	}

	cout << subStick << endl;
	return 0;
}