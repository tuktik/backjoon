#include <iostream>
#include <string.h>

using namespace std;

char input[51][13];
int weightArr[11][13];

int alpaVal[11];
int check[11];

bool cmp(int *a, int *b)
{

}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];

		int wordLen = strlen(input[i]);
		for (int j =0; j <wordLen; j++)
		{
			weightArr[input[i][j] - 'A'][wordLen-j-1]++;
		}
	}
	
	int cnt = 0;
	int nowNum = 9;
	while (cnt != 10)
	{
		int max = -1;
		int maxIdx = 0;
		for (int i = 0; i < 10; i++)
		{
			if (check[i] == 0)
			{
				if(cmp(weightArr[i], weightArr[maxIdx]))
					maxIdx = i;
			}
		}
		cnt++;
		check[maxIdx] = 1;
		alpaVal[maxIdx] = nowNum--;
	}
	
	/*for (int i = 0; i < 10; i++)
		cout << alpaVal[i] << endl;*/

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int wordLen = strlen(input[i]);
		int getNum = 0;
		for (int j = 0; j <wordLen; j++)
		{
			getNum *= 10;
			getNum += alpaVal[input[i][j] - 'A'];
		}
		cout << getNum << endl;
		sum += getNum;
	}

	cout << sum << endl;
	return 0;
}