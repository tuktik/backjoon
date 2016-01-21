#include <iostream>

using namespace std;

class point
{
public:
	int x, y;

	bool operator < (const point& b)
	{
		if (x > b.x)
			return true;
		else if (x == b.x && y > b.y)
			return true;
		else
			return false;
	}
};

point numArr[100005];

void quick(int first, int end)
{
	point pivot = numArr[(first + end) / 2];
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (numArr[f]< pivot) f++;
		while (pivot< numArr[e]) e--;

		if (f <= e)
		{
			point temp = numArr[f];
			numArr[f] = numArr[e];
			numArr[e] = temp;

			f++;
			e--;
		}
	}

	if (first < e)quick(first, e);
	if (f< end)quick(f, end);
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> numArr[i].x;
		cin >> numArr[i].y;
	}

	quick(0, n - 1);

	for (int i = n-1; i >=0; i--)
	{
		cout << numArr[i].x << " " << numArr[i].y << endl;
	}

	


	return 0;
}

//
//
//bool compare(point a, point b)
//{
//	if (a.x < b.x)
//		return true;
//	else if (a.x == b.x && a.y < b.y)
//		return true;
//	else
//		return false;
//}