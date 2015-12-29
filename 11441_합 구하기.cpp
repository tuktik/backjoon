#include <iostream>

using namespace std;

int numArr[100002];
int mArr[100002][2];
int outputArr[100002];

int main()
{
	int numCount;

	cin >> numCount;


	for (int i = 1; i <= numCount; i++)
	{
		cin >> numArr[i];
	}

	int start, end;

	int sumNum;

	cin >> sumNum;

	int max=0;
	int min = 100002;

	for (int i = 1; i <= sumNum; i++)
	{
		cin >> start;

		cin >> end;

		mArr[i][0] = start;
		mArr[i][1] = end;

		if (max < end)
			max = end;

		if (min > start)
			min = start;
	}

	int sum = 0;

	for (int i = min; i <= max; i++)
	{
		for (int j = 1; j <= sumNum; j++)
		{
			if (mArr[j][0] <= i && mArr[j][1] >= i)
				outputArr[j] += numArr[i];
		}
	}

	for (int i = 1; i <= sumNum; i++)
	{
		cout << outputArr[i] << endl;
	}

	return 0;
}

//for (int i = 1; i <= sumNum; i++)
//{
//	sum = 0;
//	for (int j = mArr[i][0]; j <= max && outputArr[i]==0; j++)
//	{
//		sum += numArr[j];
//		for (int k = i; k <= sumNum; k++)
//		{
//			if (mArr[k][0]== mArr[i][0] && mArr[k][1] == j)
//				outputArr[k] = sum;
//		}
//	}
//}

//for (int i = 1; i <= sumNum; i++)
//{
//	cout << outputArr[i] << endl;
//}
#if 0
int main()
{
	int numCount;

	cin >> numCount;


	for (int i = 1; i <= numCount; i++)
	{
		cin >> numArr[i];
	}

	int start, end;

	int sumNum;

	cin >> sumNum;

	for (int i = 1; i <= sumNum; i++)
	{
		cin >> start;

		cin >> end;

		int sum = 0;

		if (sumArr[start][0] != 0)
		{
			if (sumArr[start][0] > end)
			{
				sum = sumArr[start][1];
				for (int j = sumArr[start][0]+1; j > end; j--)
				{
					sum -= numArr[j];
				}
			}
			else
			{
				sum = sumArr[start][1];
				for (int j = sumArr[start][0]+1; j <= end; j++)
				{
					sum += numArr[j];
				}
			}

			//cout << "first"<<endl;
		}
		else
		{
			for (int j = start; j <= end; j++)
			{
				sum += numArr[j];
			}
			sumArr[start][0] = end;
			sumArr[start][1] = sum;

			//cout << "second" << endl;
		}
		
		cout << sum << endl;
	}

	

	return 0;
}
#endif