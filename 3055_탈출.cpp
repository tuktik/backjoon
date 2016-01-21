#include <iostream>

using namespace std;

int row, col;

char arr[52][52];
bool visited[52][52];

class point
{
public:
	int x, y;
	int dept;

	point(){}
	point(int x, int y, int dept):x(x),y(y),dept(dept){}
};

class queue
{
	point data[2600];
	int front, rear;
public:
	queue() :front(0), rear(0){}

	point get_front()
	{
		return data[front % 2600];
	}
	void push(point input)
	{
		data[rear++%2600] = input;
	}

	point pop()
	{
		return data[front++ % 2600];
	}

	bool is_empty()
	{
		if (front == rear)
			return 1;
		else
			return 0;
	}
};

queue water;
queue gosum;

int Dx[4] = { 1, 0, -1, 0 };
int Dy[4] = { 0, 1,  0, -1 };

void init()
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (arr[i][j] == '*')
			{
				water.push(point(j, i, 0));
				visited[i][j] = 1;
			}
				
			else if (arr[i][j] == 'S')
				gosum.push(point(j, i, 0));
		}
	}
}

void spread_water(int phase)
{
	while (!water.is_empty()&&water.get_front().dept==phase)
	{
		point temp = water.pop();
		//cout << temp.x << " " << temp.y << endl;
		for (int i = 0; i < 4; i++)
		{
			if ((arr[temp.y + Dy[i]][temp.x + Dx[i]] == 'S'
				|| arr[temp.y + Dy[i]][temp.x + Dx[i]] == '.')
				&& visited[temp.y + Dy[i]][temp.x + Dx[i]] == 0)
			{
				//cout << "!" << endl;
				water.push(point(temp.x + Dx[i], temp.y + Dy[i], temp.dept + 1));
				visited[temp.y + Dy[i]][temp.x + Dx[i]] = 1;
				arr[temp.y + Dy[i]][temp.x + Dx[i]] = '*';
			}
		}
	}
}

int spread_gosum(int phase)
{
	if (gosum.is_empty())
		return -1;

	while (!gosum.is_empty() && gosum.get_front().dept == phase)
	{
		point temp = gosum.pop();
		
		for (int i = 0; i < 4; i++)
		{
			if (arr[temp.y + Dy[i]][temp.x + Dx[i]] == '.')
			{
				//cout << "1" << endl;
				gosum.push(point(temp.x + Dx[i], temp.y + Dy[i], temp.dept + 1));
				arr[temp.y + Dy[i]][temp.x + Dx[i]] = '*';
			}
			else if (arr[temp.y + Dy[i]][temp.x + Dx[i]] == 'D')
			{
				//cout << "!!!" << endl;
				return temp.dept + 1;
			}
		}
	}
	
	return 0;
}

void continue_seq()
{
	
}

int main()
{
	cin >> row;
	cin >> col;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	init();

	int phase = 0;
	while (!gosum.is_empty())
	{
		spread_water(phase);
		int res = spread_gosum(phase);

		if (res == -1)
		{
			cout << "KAKTUS" << endl;
			return 0;
		}
		else if (res != 0)
		{
			cout << res << endl;
			return 0;
		}
		phase++;
		//cout << phase << endl;
	}
	cout << "KAKTUS" << endl;

	return 0;
}