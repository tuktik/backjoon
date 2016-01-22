#include <iostream>

using namespace std;

class Len
{
public:
	int x, y;

	Len(){}
	Len(int x, int y):x(x),y(y){}

	bool operator< (const Len& b)
	{
		if (x*y > b.x*b.y)
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
int max_idx = -1;
void dfs(int now_idx, int prev_idx, int now_count)
{
	if (now_count > maximum)
	{
		maximum = now_count;
		max_idx = prev_idx;
	}

	if (prev_idx >= max_idx && maximum > now_count)
		return;

	if (now_idx == n+1)
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

int main()
{
	

	cin >> n;

	lenArr[0].x = 9999;
	lenArr[0].y = 9999;

	for (int i = 1; i <= n; i++)
	{
		cin >> lenArr[i].x;
		cin >> lenArr[i].y;
	}
	

	quick(1, n);

	dfs(1, 0, 0);

	/*for (int i = 1; i <= n; i++)
	{
		cout << lenArr[i].x << " " << lenArr[i].y << endl;
	}*/

	cout << maximum << endl;

	
	return 0;
}