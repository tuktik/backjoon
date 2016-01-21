#include <iostream>

using namespace std;

bool visited[16][16];
int n;

class pos
{
public:
	int x, y;
	
	pos(){}
	pos(int x, int y):x(x),y(y){}
};

bool is_crossed(pos pos1, pos pos2)
{
	if (pos1.x == pos2.x)
	{
		if (pos1.x == 1 && pos1.y == 2)
			cout << "1" << endl;
		return 1;
	}
	if (pos1.y == pos2.y)
	{
		if (pos1.x == 1 && pos1.y == 2)
			cout << "2" << endl;
		return 1;
	}
		

	pos tmp = pos1;

	while (tmp.x != 1&& tmp.y<n)
	{
		tmp.x--;
		tmp.y++;
	}

	while (tmp.x <= n&& tmp.y>=1)
	{
		if (tmp.x == pos2.x && tmp.y == pos2.y)
		{
			if (tmp.x == 1 && tmp.y == 2)
				cout << "3" << endl;
			return 1;
		}
			
		tmp.x++;
		tmp.y--;
	}

	tmp = pos1;

	while (tmp.x != 1 && tmp.y!=1)
	{
		tmp.x--;
		tmp.y--;
	}
	
	while (tmp.x <= n && tmp.y <= n)
	{
		if (tmp.x == pos2.x && tmp.y == pos2.y)
		{
			if (tmp.x == 1 && tmp.y ==2)
				cout << "4" << endl;
			return 1;
		}

		tmp.x++;
		tmp.y++;
	}

	return 0;
}

bool validate(int x, int y)
{
	//cout << "!" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == x && i == y)
				continue;
			if (visited[i][j] == 1 && x!=j && y!=i)
			{
				if (is_crossed(pos(x, y), pos(j, i)) == 1)
				{
					//cout << "!" << endl;
					return 0;
				}
			}
		}
	}
	cout << x << " " << y << endl;
	return 1;
}

int counter = 0;

void dfs(int x, int y)
{
	//cout << x << " " << y << endl;
	visited[y][x] = 1;

	if (y == n)
	{
		//cout << x << " " << y << endl;
		counter++;
		visited[y][x] = 0;
		return;
	}

	for (x = 1; x <= n; x++)
	{
		if (validate(x, y + 1) == 1)
		{
			//cout << x << " " << y << endl;
			dfs(x, y + 1);
		}
			
	}
	
	visited[y][x] = 0;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dfs(i, 1);
		cout << endl;
	}

	//cout << is_crossed(pos(1, 2), pos(1, 1)) << endl;
	//cout << is_crossed(pos(4, 4), pos(2, 3)) << endl;
	//cout << counter << endl;

	return 0;
}