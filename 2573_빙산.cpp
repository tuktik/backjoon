#include <iostream>

using namespace std;

int snowMount[303][303];
bool visited[303][303];
int melting_count[303][303];
int row, col;

void reset_visited()
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void melt_mount()
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (i > 1 && snowMount[i - 1][j] == 0) melting_count[i][j]++;
			if (i < row && snowMount[i + 1][j] == 0) melting_count[i][j]++;
			if (j > 1 && snowMount[i][j - 1] == 0) melting_count[i][j]++;
			if (j < col && snowMount[i][j + 1] == 0) melting_count[i][j]++;
		}
	}

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			snowMount[i][j] -= melting_count[i][j];

			if (snowMount[i][j] < 0)
				snowMount[i][j] = 0;

			melting_count[i][j] = 0;	//reset
		}
	}


}
void dfs(int x, int y)
{
	if (snowMount[y][x] == 0)
		return;

	if (visited[y][x] == 1)
		return;

	visited[y][x] = 1;

	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int get_mount_count()
{
	int mount_count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (visited[i][j] == 0 && snowMount[i][j] > 0)
			{
				dfs(j, i);
				mount_count++;
			}
		}
	}

	return mount_count;
}

int run_phase()
{
	int phase_count = 0;
	int mountain_count;
	bool mount_zero = false;

	mountain_count = get_mount_count();

	while (mountain_count<2)
	{
		phase_count++;
		melt_mount();
		reset_visited();
		mountain_count = get_mount_count();

		if (mountain_count == 0)
			return 0;
	}

	return phase_count;
}


int main()
{


	cin >> row >> col;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> snowMount[i][j];
		}
	}

	cout << run_phase() << endl;




	return 0;
}