#include <iostream>

using namespace std;

int switchArr[101];
int switchNum;

void women(int standardNum)
{
	for (int i = 0; standardNum+i<=switchNum && standardNum-i>=1; i++)
	{
		if (switchArr[standardNum + i] == switchArr[standardNum - i])
		{
			if (switchArr[standardNum + i] == 1)
			{
				switchArr[standardNum + i] = 0;
				switchArr[standardNum - i] = 0;
			}
			else
			{
				switchArr[standardNum + i] = 1;
				switchArr[standardNum - i] = 1;
			}
		}
		else
		{
			break;
		}
	}
}

void man(int standardNum)
{
	for (int i = standardNum; i <= switchNum; i += standardNum)
	{
		if (switchArr[i] == 1)
			switchArr[i] = 0;
		else
			switchArr[i] = 1;
	}
}


int main()
{
	

	cin >> switchNum;

	for (int i = 1; i <= switchNum; i++)
	{
		cin >> switchArr[i];
	}

	int personNum;

	cin >> personNum;

	for (int i = 1; i <= personNum; i++)
	{
		int sex;

		cin >> sex;

		int standardNum;

		cin >> standardNum;

		if (sex == 1)
			man(standardNum);
		else
			women(standardNum);
	}

	for (int i = 1; i <= switchNum; i++)
	{
		cout << switchArr[i];
		if (i % 20 == 0)
			cout << endl;
		else if (i!= switchNum)
			cout << " ";
	}

	return 0;
}