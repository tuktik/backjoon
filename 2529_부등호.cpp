//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//
//using namespace std;
//
//char signArr[12];
//int usedNum[12];
////unsigned long long now_num = 0;
//int k;
//unsigned long long maxVal = 0;
//unsigned long long minVal = 9999999999;
//
//void dfs(int idx, int prevUsed, unsigned long long now_num)
//{
//	//cout << "!";
//	if (idx > k)
//	{
//		if (maxVal < now_num)
//		{
//			maxVal = now_num;
//			//cout << maxVal << endl;
//		}
//			
//		if (minVal > now_num)
//		{
//			minVal = now_num;
//		}
//
//		return;
//	}
//
//	for (int i = 0; i <= 9; i++)
//	{
//		if (usedNum[i] == 0)
//		{
//			if ((signArr[idx] == '<' && prevUsed<i) || (signArr[idx] == '>' && prevUsed>i))
//			{
//				usedNum[i] = 1;
//				//now_num = now_num * 10 + i;
//				dfs(idx + 1, i, now_num * 10 + i);
//				//now_num = now_num / 10;
//				usedNum[i] = 0;
//			}
//		}
//	}
//
//}
//
//
//int main()
//{
//	cin >> k;
//	for (int i = 1; i <= k; i++)
//	{
//		scanf(" %c", &signArr[i]);
//	}
//
//	for (int i = 0; i <= 9; i++)
//	{
//		usedNum[i] = 1;
//		dfs(1, i,i);
//		usedNum[i] = 0;
//	}
//	
//	if ((unsigned long long)maxVal / (unsigned long long)pow(10, k) == 0)
//		cout << '0';
//	cout << maxVal << endl;
//
//	if ((unsigned long long)minVal / (unsigned long long)pow(10, k) == 0)
//		cout << '0';
//	cout << minVal << endl;
//
//
//	return 0;
//}

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

char signArr[10];
int usedNum[10];
unsigned long long now_num = 0;
int k;
unsigned long long maxVal = 0;
unsigned long long minVal = 99999999999;
char maxArr[10];
char minArr[10];

void dfs(int idx, int prevUsed)
{
	//cout << "!";
	if (idx > k)
	{
		if (maxVal < now_num)
			maxVal = now_num;
		if (minVal > now_num)
		{
			minVal = now_num;
		}

		return;
	}

	if (signArr[idx] == '<')
	{
		for (int i = prevUsed + 1; i <= 9; i++)
		{
			if (usedNum[i] == 0)
			{
				usedNum[i] = 1;
				now_num = now_num * 10 + i;
				dfs(idx + 1, i);
				now_num = now_num / 10;
				usedNum[i] = 0;
			}
		}
	}
	else if (signArr[idx] == '>')
	{
		for (int i = prevUsed - 1; i >= 0; i--)
		{
			if (usedNum[i] == 0)
			{
				usedNum[i] = 1;
				now_num = now_num * 10 + i;
				dfs(idx + 1, i);
				now_num = now_num / 10;
				usedNum[i] = 0;
			}

		}
	}
	else if (idx == k)
	{
		if (signArr[idx - 1] == '<')
		{
			for (int i = prevUsed + 1; i <= 9; i++)
			{
				if (usedNum[i] == 0)
				{
					usedNum[i] = 1;
					now_num = now_num * 10 + i;
					dfs(idx + 1, i);
					now_num = now_num / 10;
					usedNum[i] = 0;
				}
			}
		}
		else if (signArr[idx - 1] == '>')
		{
			for (int i = prevUsed - 1; i >= 0; i--)
			{
				if (usedNum[i] == 0)
				{
					usedNum[i] = 1;
					now_num = now_num * 10 + i;
					dfs(idx + 1, i);
					now_num = now_num / 10;
					usedNum[i] = 0;
				}

			}
		}
	}

}

int main()
{


	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		scanf(" %c", &signArr[i]);
	}

	/*for (int i = 0; i < k; i++)
	{
	cout << signArr[i] << endl;
	}*/

	for (int i = 0; i <= 9; i++)
	{
		usedNum[i] = 1;
		now_num = i;
		dfs(1, i);
		usedNum[i] = 0;
	}

	if ((unsigned long long)maxVal / (unsigned long long)pow(10, k) == 0)
		cout << '0';
	cout << maxVal << endl;

	if ((unsigned long long)minVal / (unsigned long long)pow(10, k) == 0)
		cout << '0';
	cout << minVal;


	return 0;
}