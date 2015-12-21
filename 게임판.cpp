#include <iostream>

using namespace std;

int arr[101][101];

class Point
{
public:
	int x, y;
	Point(){}
	Point(int x, int y) :x(x), y(y){}
};

class stack
{
	Point data[10000];
	int top;
public:

	stack() :top(0){}

	void push(Point tmp)
	{
		data[top].x = tmp.x;
		data[top].y = tmp.y;

		top++;
	}

	Point pop()
	{
		if (top == 0)
		{
			return Point(-1, -1);
		}
		else
		{
			top--;
			return data[top];
		}
	}

	void stack_print()
	{
		for (int i = top - 1; i >= 0; i--)
			cout << data[top].x << " " << data[top].y << endl;
	}

};

stack global_stack;

int main()
{
	int nCount;

	cin >> nCount;

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;

		int size;

		cin >> size;

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				cin >> arr[i][j];
			}
		}

		global_stack.push(Point(1, 1));
		global_stack.push(Point(2, 2));
		global_stack.push(Point(3, 3));
		global_stack.stack_print();

		global_stack.pop();
		global_stack.stack_print();

		Point now_point(1, 1);

		//cout << now_point.x << " " << now_point.y << endl;
		//bool isAlive = false;
		//while (now_point.x != -1 && now_point.y != -1)
		//{
		//	if (arr[now_point.y][now_point.x] != 0 && (now_point.y + arr[now_point.y][now_point.x]) <= size)
		//	{
		//		global_stack.push(Point(now_point.x, now_point.y + arr[now_point.y][now_point.x]));
		//		//cout << "1" << endl;
		//	}

		//	if (arr[now_point.y][now_point.x] != 0 && (now_point.x + arr[now_point.y][now_point.x]) <= size)
		//	{
		//		global_stack.push(Point(now_point.x + arr[now_point.y][now_point.x], now_point.y));
		//		//cout << "2" << endl;
		//	}


		//	now_point = global_stack.pop();

		//	//cout << now_point.x << " " << now_point.y << endl;
		//	//cout << "!!";
		//	if (now_point.x == size && now_point.y == size)
		//	{
		//		isAlive = true;
		//		//cout << "break";
		//		break;
		//	}
		//}

		//if (isAlive == true)
		//	cout << "YES" << endl;
		//else
		//	cout << "NO" << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}