#include <iostream>

using namespace std;

int h, w;
int board[21][21];

int blockType[4][3][2] = {
	{ {0,0}, {1,0}, {0,1} },
	{ {0,0}, {0,1}, {1,1} },
	{ {0,0}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {1.-1} }
};

bool set(int y, int x, int type, int delta)
{
	bool ok = true;
	
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + blockType[type][i][0];
		const int nx = x + blockType[type][i][1];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w)
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover(){
	int y = -1, x = -1;

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)break;
	}

	if (y == -1)	return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(y, x, type, 1))
			ret += cover();
		set(y, x, type, -1);
	}

	return ret;
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		cin >> h >> w;
		
		char tmp;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> tmp;
				if (tmp == '.')
					board[i][j] = 0;
				else
					board[i][j] = 1;
			}
		}

		cout << cover() << endl;
	}

	return 0;
}