#include <iostream>

using namespace std;

#define plus 1
#define minus 2
#define numbering 3

int n;
//int val,

char resArr[10];

void dfs(int idx, int prev_num, int now_num, int prev_cal)
{
	if (idx > n)
	{
		int res;
		if (prev_cal == plus)
		{
			res = prev_num + now_num;
		}
		else if (prev_cal == minus)
		{
			res = prev_num - now_num;
		}
		else
			return;

		if (res == 0)
		{
			if (prev_cal == plus)
			{
				//cout << "res:" << prev_num << "plus " << now_num << endl;
			}
			else if (prev_cal == minus)
			{
				//cout << "res:" << prev_num << "minus " << now_num << endl;
			}

			for (int i = 1; i <= n; i++)
			{
				cout << i;
				if (i!=n)
				cout << resArr[i + 1];
				/*if (resArr[i] == 1)
				{
				cout << '+';
				}
				else if (resArr[i] == 2)
				{
				cout << '-';
				}
				else if (resArr[i] == 3)
				{
				cout << ' ';
				}*/
			}
			cout << endl;
		}
		return;
	}

	if (idx > n )
		return;

	//cout << idx << ": " << prev_num << " " << now_num << " cal:" << prev_cal << " " << endl;

	resArr[idx] = ' ';
	dfs(idx + 1, prev_num, now_num * 10 + idx, prev_cal);

	if (prev_cal == plus)
	{
		//+
		resArr[idx] = '+';
		dfs(idx + 1, prev_num + now_num, idx, plus);
		//-
		resArr[idx] = '-';
		dfs(idx + 1, prev_num + now_num, idx, minus);
	}
	else if (prev_cal == minus)
	{
		//+
		resArr[idx] = '+';
		dfs(idx + 1, prev_num - now_num, idx, plus);
		//-
		resArr[idx] = '-';
		dfs(idx + 1, prev_num - now_num, idx, minus);
	}
	//
	
}

int main()
{
	int testNum;

	cin >> testNum;

	for (int i = 0; i < testNum; i++)
	{
		cin >> n;

		dfs(2, 0, 1, plus);
		
		if (i!=testNum-1)
			cout << endl;
	}

	return 0;
}