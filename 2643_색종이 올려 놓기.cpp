#include <iostream>
#include <limits.h>

using namespace std;

class Len
{
public:
	int x, y;
	int lower_count;

	Len(){}
	Len(int x, int y):x(x),y(y),lower_count(0){}

	bool operator< (const Len& b)
	{
		if (x < b.x || (x == b.x&&y <b.y ))
			return true;
		else
			return false;
	}
};

Len lenArr[105];

void quick(int first, int end)
{
	Len pivot = lenArr[(first + end) / 2];
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (lenArr[f] < pivot) f++;
		while (pivot < lenArr[e]) e--;

		if (f <= e)
		{
			Len tmp = lenArr[f];
			lenArr[f] = lenArr[e];
			lenArr[e] = tmp;
			
			f++;
			e--;
		}
	}

	if (first < e) quick(first, e);
	if (f < end) quick(f, end);
}

int maximum = -1;
int n;

int main()
{
	cin >> n;

	lenArr[0].x = 0;
	lenArr[0].y = 0;
	lenArr[0].lower_count = 0;

	int x, y;

	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		cin >> y;

		if (x >= y)
		{
			lenArr[i].x = x;
			lenArr[i].y = y;
		}
		else
		{
			lenArr[i].x = y;
			lenArr[i].y = x;
		}
	}
	

	quick(1, n);

	for (int i = 1; i <= n; i++)
	{
		int j,j_max = 0;
		for (j = i - 1; j >= 1; j--)
		{
			if (lenArr[j].y <= lenArr[i].y && j_max < lenArr[j].lower_count)
			{
				j_max = lenArr[j].lower_count;
			}
		}
		lenArr[i].lower_count = j_max + 1;

		if (lenArr[i].lower_count > maximum)
			maximum = lenArr[i].lower_count;

		//cout << lenArr[i].x << " " << lenArr[i].y << " " << lenArr[i].lower_count << endl;

	}

	cout << maximum << endl;

	
	return 0;
}

/*
void dfs(int now_idx, int prev_idx, int now_count)
{
	if (now_count > maximum)
	{
		maximum = now_count;
		max_idx = prev_idx;
	}

	if (prev_idx >= max_idx && maximum > now_count)
		return;

	if (now_idx == n + 1)
		return;


	if ((lenArr[now_idx].x <= lenArr[prev_idx].x && lenArr[now_idx].y <= lenArr[prev_idx].y)
		|| (lenArr[now_idx].x <= lenArr[prev_idx].y && lenArr[now_idx].y <= lenArr[prev_idx].x))
	{
		//cout << lenArr[now_idx].x << " " << lenArr[now_idx].y << endl;
		dfs(now_idx + 1, now_idx, now_count + 1);
	}
	//cout << endl;

	dfs(now_idx + 1, prev_idx, now_count);
}
*/