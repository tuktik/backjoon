#include <iostream>

using namespace std;

int arr[20005][20005];
bool visited[20005][20005];

void dfs()
{

}

int main()
{
	int testNum;

	cin >> testNum;

	for (int a = 0; a < testNum; a++)
	{
		

		int nodeCount;

		cin >> nodeCount;

		for (int i = 0; i < nodeCount; i++)
		{
			for (int j = 0; j < nodeCount; j++)
				arr[i][j] = 0;
		}
		//arr[i] = 0;

		int edgeCount;

		cin >> edgeCount;
		int verA, verB;

		bool flag = true;

		for (int i = 0; i < edgeCount; i++)
		{
			cin >> verA >> verB;
			
			arr[verA][verB] = 1;
			arr[verB][verA] = 1;
		}

		for (int i = 0; i < nodeCount; i++)
		{
			for (int j = 0; j < nodeCount; j++)
			{
				
			}
		}

		if (flag == false)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}