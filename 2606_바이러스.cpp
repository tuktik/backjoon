#include <iostream>

using namespace std;

int arr[105][105];
int visited[105];
int n;
int virusCount = 0;
void dfs(int now_node)
{
	for (int b = 1; b <= n; b++)
	{
		if (visited[b] ==0 && arr[now_node][b] == 1)
		{
			visited[b] = 1;
			virusCount++;
			dfs(b);
		}
			
	}
}
int main()
{
	
	
	int edge;

	cin >> n;

	cin >> edge;

	int a, b;
	for (int i = 0; i < edge; i++)
	{
		cin >> a;
		cin >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	visited[1] = 1;
	//virusCount++;
	dfs(1);

	cout << virusCount << endl;

	return 0;
}