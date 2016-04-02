#include <iostream>
#include <string.h>

using namespace std;

int n;

char inputArr[51][13];

int counting[11][13];

int alpa[11];	//¾ËÆÄºª ¸ÅÄª ¼ýÀÚ ¹è¿­
int check[11];
int is_first[11];

int cmp(int *a, int* b)
{
	for (int i = 12; i >= 0; i--)
	{
		if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return 0;
		else
			continue;
	}
	
	return -1;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> inputArr[i];

		int sLen = strlen(inputArr[i]);

		for (int j = sLen - 1, idx = 0; j >= 0; j--, idx++)
		{
			if (j == 0)
				is_first[inputArr[i][j] - 'A'] = 1;

			counting[inputArr[i][j] - 'A'][idx]++;
			
			if (counting[inputArr[i][j] - 'A'][idx] >= 10 && idx != 11)
			{
				counting[inputArr[i][j] - 'A'][idx] -= 10;
				counting[inputArr[i][j] - 'A'][idx + 1]++;
			}
		}
	}

	int cnt = 0;
	//while (cnt--)
	for (int i = 0; i < 10; i++)
	{
		int minIdx = -1;

		for (int alpa = 0; alpa < 10; alpa++)
		{
			if (check[alpa] == 0)
			{
				if (i == 0)
				{
					if (is_first[alpa] == 0)
					{
						if (cmp(counting[alpa], counting[minIdx]) || minIdx == -1)
							minIdx = alpa;
					}
				}
				else
				{
					if (cmp(counting[alpa], counting[minIdx]) || minIdx == -1)
						minIdx = alpa;
				}
			}
		}
		check[minIdx] = 1;
		alpa[minIdx] = i;
	}

	/*for (int i = 0; i < 10; i++)
	{
		cout << char('A' + i) << " " << is_first[i] << endl;
	}*/

	//for (int i = 0; i < 10; i++)
	//{
	//	cout <<char ('A'+i)<<" "<<alpa[i] << endl;
	//}
	
	long long sum = 0;

	for (int i = 0; i < n; i++)
	{
		int sLen = strlen(inputArr[i]);
		long long nowNum = 0;
		for (int j = 0; j < sLen ; j++)
		{
			nowNum *= 10;
			nowNum += alpa[inputArr[i][j] - 'A'];
		}
		//cout << nowNum << endl;
		sum += nowNum;
	}
	
	cout << sum << endl;

	/*for (int alpa = 0; alpa < 10; alpa++)
	{
		cout << char('A' + alpa) << " ";
		for (int idx = 0; idx<12; idx++)
		{
			cout << counting[alpa][idx] << " ";
		}
		cout << endl;
	}*/



	return 0;
}


/*
#include <iostream>
#include <string.h>

using namespace std;

char input[51][13];
int weightArr[11][13];

int alpaVal[11];
int check[11];

bool cmp(int *a, int *b)
{
	for (int i = 12; i >= 0; i--)
	{
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return 0;
		else
			continue;
	}
	return 1;
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
				if (cmp(weightArr[i], weightArr[maxIdx]))
					maxIdx = i;
			}
		}
		cnt++;
		check[maxIdx] = 1;
		alpaVal[maxIdx] = nowNum--;
	}
	
	for (int i = 0; i < 10; i++)
		cout << alpaVal[i] << endl;

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
*/