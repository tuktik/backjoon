#include <iostream>
#include <string.h>

using namespace std;

int calcMatrix[1001][1001];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	char buff1[1001];
	char buff2[1001];

	cin >> buff1;
	cin >> buff2;

	for (int i = 1; i <= strlen(buff1); i++)
	{
		for (int j = 1; j <= strlen(buff2); j++)
		{
			if (buff1[i - 1] == buff2[j - 1])
				calcMatrix[i][j] = calcMatrix[i - 1][j - 1] + 1;
			else
				calcMatrix[i][j] = max(calcMatrix[i - 1][j], calcMatrix[i][j - 1]);
		}
	}

	cout << calcMatrix[strlen(buff1)][strlen(buff2)] << endl;

	return 0;
}