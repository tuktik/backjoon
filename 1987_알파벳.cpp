#include <iostream>

using namespace std;

char inputArr[25][25];
bool alpaArr[26];
int r, c;
int maxCnt = 1;

void dfs(int x, int y, int cnt)
{

	if (alpaArr[inputArr[y][x] - 65] == 1)
		return;

	if (r <= y || 0 > y)
		return;
	
	if (c <= x || 0 > x)
		return;

	
	if (maxCnt < cnt)
		maxCnt = cnt;


	alpaArr[inputArr[y][x] - 65] = 1;

	dfs(x + 1, y, cnt + 1);
	dfs(x, y + 1, cnt + 1);
	dfs(x - 1, y, cnt + 1);
	dfs(x, y - 1, cnt + 1);

	alpaArr[inputArr[y][x] - 65] = 0;

}

int main()
{
	cin >> r;
	cin >> c;

	//cout << (int)'A';

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> inputArr[i][j];
		}
	}

	dfs(0, 0, 1);

	cout << maxCnt << endl;



	return 0;
}