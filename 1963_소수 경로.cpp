#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int sosuArr[10000] = {1,1,};
int visited[10000];
//0인 애들이 소수

int targetNum;

void makeSosu()
{
	for (int i = 2; i < 10000; i++)
	{
		if (sosuArr[i] == 0)
		{
			for (int j = 2 * i; j < 10000; j += i)
			{
				sosuArr[j] = 1;
			}
		}
	}
}
void init()
{
	for (int i = 0; i < 10000; i++)
	{
		visited[i] = 0;
	}
}

//int min(int a, int b, int c, int d)
//{
//
//}
int minVal = 99999;

class Val
{
public:
	int num;
	int dept;

	Val(){}
	Val(int num, int dept) :num(num), dept(dept){};
};

queue<Val> global_queue;

int bfs(int nowNum)
{
	init();
	global_queue.push(Val(nowNum, 0));
	visited[nowNum] = 1;

	while (!global_queue.empty())
	{
		Val temp = global_queue.front();
		global_queue.pop();
		//cout << temp.num << endl;

		if (temp.num == targetNum)
		{
			return temp.dept;
		}
		if (temp.num <1000)
		{
			continue;
		}

		for (int num = 0; num < 4; num++)
		{
			for (int i = 0; i <= 9; i++)
			{
				int nextNum[4];
				nextNum[0] = temp.num % 10;
				nextNum[1] = temp.num % 100 / 10;
				nextNum[2] = temp.num % 1000 / 100;
				nextNum[3] = temp.num / 1000;

				if (nextNum[num] != i)
				{
					nextNum[num] = i;
					int makedVal = 0;
					for (int k = 0; k < 4; k++)
					{
						makedVal += (nextNum[k] * pow(10, k));
					}
					if (sosuArr[makedVal] == 0 && visited[makedVal] ==0)
					{
						global_queue.push(Val(makedVal, temp.dept + 1));
						visited[makedVal] = 1;
					}
						
				}
			}
		}
	}

	return -1;

}
//
int main()
{
	int testNum;
	cin >> testNum;

	int nowNum;

	makeSosu();

	for (int t = 0; t < testNum; t++)
	{
		cin >> nowNum;
		cin >> targetNum;
		
		while (!global_queue.empty())
			global_queue.pop();
		int res = bfs(nowNum);

		if (res == -1)
			cout << "Impossible" << endl;
		else
			cout << res << endl;

	}

	return 0;
}

//dfs(nowNum, 0);
//void dfs(int nowNum, int dept)
//{
//	//cout << nowNum << endl;
//	if (visited[nowNum] == 1)
//		return ;
//
//	if (nowNum < 1000)
//		return ;
//
//	if (nowNum == targetNum)
//	{
//		if (minVal > dept)
//			minVal = dept;
//		return;
//	}
//		
//	visited[nowNum] = 1;
//
//	for (int num = 0; num < 4; num++)
//	{
//		for (int i = 0; i <= 9; i++)
//		{
//			int nextNum[4];
//			nextNum[0] = nowNum % 10;
//			nextNum[1] = nowNum % 100 / 10;
//			nextNum[2] = nowNum % 1000 / 100;
//			nextNum[3] = nowNum / 1000;
//
//			if (nextNum[num] != i)
//			{
//				nextNum[num] = i;
//				int temp = 0;
//				for (int k = 0; k < 4; k++)
//				{
//					temp += (nextNum[k] * pow(10, k));
//				}
//				if (sosuArr[temp] == 0)
//					dfs(temp, dept);
//			}
//		}
//	}
//			
//}
