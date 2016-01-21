#include <iostream>
#include <string.h>

using namespace std;

char *passList[102];

int N;

void sort()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (strlen(passList[i]) > strlen(passList[j]))
			{
				char *temp = passList[i];
				passList[i] = passList[j];
				passList[j] = temp;
			}
		}
	}
}

bool compare(char * first, char * second)
{
	int fLen = strlen(first);

	for (int i = 0; i < fLen / 2; i++)
	{
		if (first[i] == second[fLen - i - 1])
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		passList[i] = new char[15];
		
		cin >> passList[i];
	}

	sort();

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			int fLen = strlen(passList[i]);
			int sLen = strlen(passList[j]);

			if (fLen != sLen)
				break;

			bool res = compare(passList[i], passList[j]);

			if (res == 1)
			{
				cout << fLen <<" "<<passList[i][fLen/2]<<endl;
				return 0;	
			}
		}
	}

	cout << "long" << endl;

	return 0;
}