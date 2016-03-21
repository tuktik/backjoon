#include <iostream>
#include <queue>

using namespace std;

char mapArr[1005][1005];
int fire_visited[1005][1005];
int man_visit[1005][1005];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int h, w;

class point
{
public:
	int x, y;
	int phase;
	
	point(){}
	point(int x, int y, int phase) :x(x), y(y), phase(phase){}
};

queue<point> fire_queue;
queue<point> man_queue;

void fireMove(int phase)
{
	//cout << phase << endl;
	if (fire_queue.empty())
	{
		//cout << "!!";
		return;
	}
	point tmp = fire_queue.front();
	
	while ( tmp.phase == phase && !fire_queue.empty())
	{
		fire_queue.pop();
		//cout << tmp.x << " " << tmp.y << " " << tmp.phase << endl;

		for (int i = 0; i < 4; i++)
		{
			if ((mapArr[tmp.y + dy[i]][tmp.x + dx[i]] == '@' 
				|| mapArr[tmp.y + dy[i]][tmp.x + dx[i]] == '.')
				&& fire_visited[tmp.y + dy[i]][tmp.x + dx[i]] != 1)
			{
				fire_visited[tmp.y + dy[i]][tmp.x + dx[i]] = 1;
				//cout << "!" << endl;
				mapArr[tmp.y + dy[i]][tmp.x + dx[i]] = '*';
				fire_queue.push(point(tmp.x + dx[i], tmp.y + dy[i], tmp.phase + 1));
			}
		}
		if (fire_queue.empty())
			return ;
		tmp = fire_queue.front();
	}
}

int manMove(int phase)
{
	//point tmp(0, 0, 0);
	point tmp = man_queue.front();
	while (tmp.phase == phase && !man_queue.empty())
	{
		man_queue.pop();

		for (int i = 0; i < 4; i++)
		{
			if (mapArr[tmp.y + dy[i]][tmp.x + dx[i]] == '.'
				&& man_visit[tmp.y + dy[i]][tmp.x + dx[i]] != 1)
			{
				man_visit[tmp.y + dy[i]][tmp.x + dx[i]] = 1;
				man_queue.push(point(tmp.x + dx[i], tmp.y + dy[i], tmp.phase + 1));
			}
			else if (mapArr[tmp.y + dy[i]][tmp.x + dx[i]] == 0)
			{
				return tmp.phase+1;
			}
		}
		if (man_queue.empty())
			return -1;
		tmp = man_queue.front();
	}
	if (man_queue.empty())
		return -1;
	else
		return 0;
}

int cal()
{
	while (!fire_queue.empty()){ fire_queue.pop(); }
	while (!man_queue.empty()){ man_queue.pop(); }

	int phase = 0;
	int res = 0;

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (mapArr[i][j] == '*')
			{
				//cout << j << i << endl;
				fire_queue.push(point(j, i, 0));
			}
				
			else if (mapArr[i][j] == '@')
				man_queue.push(point(j, i, 0));
		}
	}

	while (!man_queue.empty() && res == 0)
	{
		fireMove(phase);
		res = manMove(phase);
		phase++;

		//for (int i = 1; i <= h; i++)
		//{
		//	for (int j = 1; j <= w; j++)
		//	{
		//		cout<< mapArr[i][j];	
		//	}
		//cout << endl;
		//}
		//cout << phase << endl;
	}
	return res;
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{

		cin >> w;
		cin >> h;

		for (int i = 1; i <=h; i++)
		{
			for (int j = 1; j <=w; j++)
			{
				cin >> mapArr[i][j];
			}
		}

		int res = cal();

		if (res == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << res << endl;

		for (int i = 0; i < 1005; i++)
		{
			for (int j = 0; j <1005; j++)
			{

				mapArr[i][j] = 0;
				fire_visited[i][j] = 0;
				man_visit[i][j] = 0;
			}
		}

	}

	return 0;
}