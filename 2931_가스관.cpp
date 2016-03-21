#include <iostream>

using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int r, c;

char arr[26][26];
int m_x, m_y;
int z_x, z_y;

class point
{
public:
	int x, y;
};

//(¾Æ½ºÅ° 124), '-', '+', '1', '2', '3', '4'

void dfs(int x, int y, int direction)
{
	if (arr[y][x] == 'M')
	{

	}

	if (arr[y][x] == '|')
	{
		if (direction == DOWN)
			dfs(x, y + 1, direction);
		else
			dfs(x, y - 1, direction);
	}


}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'M')
			{
				m_x = j;
				m_y = i;
			}
			else if (arr[i][j] == 'Z')
			{
				z_x = j;
				z_y = i;
			}
		}
	}

	dfs();




	return 0;
}