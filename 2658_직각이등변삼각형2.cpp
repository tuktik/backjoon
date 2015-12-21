#include <iostream>

using namespace std;

int arr[11][11];

class point
{
public:
	int x, y;
	point(){}
	point(int x, int y) :x(x), y(y){}
};

int main()
{
	point vertex[3];
	int vertextCount = 0;

	point prev_starting(0,0);
	point prev_ending(0, 0);
	point starting(0,0);
	bool is_start = false;
	point ending(0, 0);
	bool is_end = false;

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			char tmp;
			cin >> tmp;
			arr[i][j] = tmp - '0';
			
			if (arr[i][j] == 1)
			{
				if (is_start == false)
				{
					starting.x = j;
					starting.y = i;
					is_start = true;

					if (prev_starting.x == 0)
					{
						vertex[vertextCount] = starting;
						vertextCount++;
					}
						
				}
			}
			else
			{
				if (is_start == true && is_end == false)
				{
					ending.x = j - 1;
					ending.y = i;
					is_end = true;

					if (prev_ending.x == 0 && starting.x==ending.x && starting.y == ending.y)
					{
						vertex[vertextCount] = ending;
						vertextCount++;
					}
				}
			}

		}
	}
}