#include <iostream>
#include <queue>

using namespace std;

int arr[1005][1005];
int visited[1005];
int n;
int m;
int start;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i]=0;
	}
}
void dfs(int now_node)
{
	cout << now_node << " ";

	if (visited[now_node] == 1)
		return;

	visited[now_node] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (arr[now_node][i] == 1 && visited[i] == 0 && now_node != i)
			dfs(i);
	}
}

queue<int> global_queue;

void bfs(int now_node)
{
	init();
	global_queue.push(now_node);
	visited[now_node] = 1;

	while (!global_queue.empty())
	{
		int tmp = global_queue.front();
		cout << tmp << " ";
		global_queue.pop();

		for (int i = 1; i <= n; i++)
		{
			if (tmp != i && visited[i] == 0 && arr[tmp][i] == 1)
			{
				global_queue.push(i);
				visited[i] = 1;
			}
		}
	}
	

}

int main()
{
	

	cin >> n;
	cin >> m;
	cin >> start;

	int a, b;

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(start);
	cout << endl;
	bfs(start);
	cout << endl;

	return 0;
}