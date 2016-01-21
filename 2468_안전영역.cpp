#include <iostream>

using namespace std;

int arr[102][102];
bool visited[102][102];
int n;



void dfs(int x,int y,int high)
{
	//cout << "!!" << endl;
	if (arr[y][x] <= high)
		return;
	if (visited[y][x] == 1)
		return;

	visited[y][x] = 1;
	
	if (x - 1 > 0 && arr[y][x - 1] > high )	dfs(x - 1, y, high);
	if (x + 1 <= n && arr[y][x + 1] > high )dfs(x + 1, y, high);
	if (y - 1 > 0 && arr[y-1][x] > high )	dfs(x, y-1, high);
	if (y + 1 <= n && arr[y+1][x] > high )	dfs(x, y+1, high);
}

void init()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			visited[i][j] = 0;
		}
	}
}

int counting_area(int high)
{
	int count=0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] == 0 && arr[i][j]>high)
			{
				//cout << "!";
				count++;
				dfs(j, i, high);
			}
		}
	}

	return count;
}

int main()
{
	int max=0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}

	int max_count = 1;
	int res;
	for (int i = 1; i <= max; i++)
	{
		init();
		res = counting_area(i);
		if (res > max_count)
			max_count = res;
	}
	
	//cout << counting_area(0) << endl;
	cout << max_count << endl;


	return 0;
}