#include <iostream>

using namespace std;

int relArr[105][105];
int visited[105];

int chonCount = 0;

void dfs(int manNum, int a, int b, int counting)
{
	visited[a] = 1;
	if (a == b)
	{
		chonCount = counting;
		return;
	}
	for (int i = 1; i <= manNum; i++)
	{
		if (relArr[a][i] == 1 && visited[i] == 0)
		{
			dfs(manNum, i, b, counting + 1);
		}

	}

}

int main()
{
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		chonCount = 0;
		cout << "#testcase" << (itr + 1) << endl;

		int manNum;
		cin >> manNum;

		for (int i = 0; i <= manNum; i++)
		{
			for (int j = 0; j < manNum; j++)
			{
				relArr[i][j] = 0;
			}
		}

		int a, b;
		cin >> a >> b;

		int relCountNum;
		cin >> relCountNum;

		int x, y;

		for (int i = 1; i <= relCountNum; i++)
		{
			cin >> x >> y;
			relArr[x][y] = 1;
			relArr[y][x] = 1;
		}

		int now_node = a;

		dfs(manNum, a, b, 0);

		if (chonCount != 0)
			cout << chonCount << endl;
		else
			cout << -1 << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}