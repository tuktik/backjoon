#include <iostream>

using namespace std;

int n, m;
char boardArr[55][55];
int visited[55][55];
int dp[55][55];

int max(int a, int b){ return a > b ? a : b; }

int flag = 0;

int dfs(int x, int y)
{
	if (x >= m || y >= n || x < 0 || y < 0)
		return 0;
	if (boardArr[y][x] == 'H')
		return 0;
	
	if (visited[y][x] == 1)
	{
		flag = 1;
		return 0;
	}

	if (dp[y][x])
		return dp[y][x];
		
	int now_num = boardArr[y][x] - '0';
	int res = 0;
	
	visited[y][x] = 1;
	res = max(res, 1+dfs(x+now_num, y));
	res = max(res, 1+dfs(x, y + now_num));
	res = max(res, 1+dfs(x -now_num, y));
	res = max(res, 1+dfs(x, y - now_num));
	
	dp[y][x] = res;
	visited[y][x] = 0;

	return dp[y][x];
}

int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> boardArr[i][j];
		}
	}

	int res = dfs(0, 0);
	if (flag == 1)
		cout << -1 << endl;
	else
		cout << res << endl;

	return 0;
}


#if 0
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

char a[55][55];
int visit[55][55];
int dp[55][55];

int flag = 0;
int dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 'H') return 0;
	if (dp[x][y]) return dp[x][y];

	if (visit[x][y]){
		flag = 1;
		return 0;
	}
	visit[x][y] = 1;
	int num = a[x][y] - '0';
	int a1 = dfs(x - num, y);
	int a2 = dfs(x + num, y);
	int a3 = dfs(x, y - num);
	int a4 = dfs(x, y + num);
	visit[x][y] = 0;
	return dp[x][y] = 1 + max(a1, max(a2, max(a3, a4)));
}
int main()
{

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf(" %s", a[i]);

	int res = dfs(0, 0);
	if (flag == 1) printf("-1\n");
	else printf("%d\n", res);
}

#endif



#if 0

#include <iostream>

using namespace std;

int n, m;
char boardArr[55][55];
int weight[55][55];
int visited[55][55];

int maxVal(int a, int b, int c, int d)
{
	int tmp = a > b ? a : b;
	tmp = tmp > c ? tmp : c;
	tmp = tmp > d ? tmp : d;
	return tmp;
}

int dfs(int x, int y, int dept)
{
	if (x >= m || y >= n || x < 0 || y < 0)
		return dept;

	if (visited[y][x] == 1)
		return -1;

	if (boardArr[y][x] == 'H')
		return dept;

	/*if (weight[y][x]>dept)
		return -999999;
*/
	//weight[y][x] = dept;

	//cout << x << " " << y << " " << dept << endl;
	int now_num = boardArr[y][x] - '0';
	
	visited[y][x] = 1;

	int a = dfs(x+now_num, y, dept + 1);
	int b = dfs(x, y + now_num, dept + 1);
	int c = dfs(x - now_num, y, dept + 1);
	int d = dfs(x, y - now_num, dept + 1);

	visited[y][x] = 0;


	if (a == -1 || b == -1 || c == -1 || d == -1)
		return -1;
	else
	{
		//cout << maxVal(a, b, c, d) << endl;
		return maxVal(a, b, c, d);
	}
		

}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> boardArr[i][j];
		}
	}

	cout << dfs(0, 0, 0) << endl;

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout<<weight[i][j]<<" ";
		}
		cout << endl;
	}
*/

	return 0;
}

#endif