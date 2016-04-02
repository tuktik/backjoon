#include <iostream>

using namespace std;

int arr[6][3];
int check[6][3];

int is_avail = false;

int available()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == check[i][j])
				continue;
			else
				return 0;
		}
	}
	return 1;
}

void dfs(int first_idx, int second_idx)
{
	if (first_idx >= 5)
	{
		if (available() == 1)
			is_avail = 1;
		return;
	}
		

		check[first_idx][0]++;
		check[second_idx][2]++;
		if (second_idx == 5)
			dfs(first_idx + 1, first_idx + 2);
		else
			dfs(first_idx, second_idx+1);
		check[first_idx][0]--;
		check[second_idx][2]--;
		
		//idx lose
		check[first_idx][2]++;
		check[second_idx][0]++;
		if (second_idx == 5)
			dfs(first_idx + 1, first_idx + 2);
		else
			dfs(first_idx, second_idx + 1);
		check[first_idx][2]--;
		check[second_idx][0]--;

		//idx draw
		check[first_idx][1]++;
		check[second_idx][1]++;
		if (second_idx == 5)
			dfs(first_idx + 1, first_idx + 2);
		else
			dfs(first_idx, second_idx + 1);
		check[first_idx][1]--;
		check[second_idx][1]--;
}

int main()
{
	int t = 4;

	while (t--)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> arr[i][j];
			}
		}
		is_avail = 0;
		dfs(0,1);

		cout << is_avail << endl;
	}



	return 0;
}