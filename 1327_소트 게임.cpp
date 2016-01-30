#include <iostream>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

int n;
int k;

struct 
{
	int numArr[10];
	int count;
} typedef numStream;

numStream input;
map<int, int> chk_map;
queue<numStream> bfs_queue;

int make_num(numStream input)
{
	int num = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		num += input.numArr[i] * pow((double)10, (n - i - 1));
	}
	return num;
}


bool is_sorted(numStream input)
{
	bool is_sort = true;
	for (int i = 0; i < n; i++)
	{
		if (input.numArr[i] != i + 1)
		{
			is_sort = false;
			break;
		}
	}
	if (is_sort == false)
		return false;
	else
		return true;
}

numStream reverse(numStream input, int idx)
{
	for (int i = 0; i < k / 2; i++)
	{
		int temp = input.numArr[idx + i];
		input.numArr[idx + i] = input.numArr[idx + k - 1 - i];
		input.numArr[idx + k - 1 - i] = temp;
	}
	input.count = input.count + 1;

	return input;
}

int bfs()
{
	bfs_queue.push(input);
	chk_map.insert(pair<int, int>(make_num(input), 1));

	if (is_sorted(input) == true)
	{
		return input.count;
	}


	while (!bfs_queue.empty())
	{
		numStream tmp = bfs_queue.front();
		bfs_queue.pop();

		/*for (int i = 0; i < n; i++)
		{
			cout << tmp.numArr[i] << " ";
		}
		cout << tmp.count << "!" << endl;*/

		if (is_sorted(tmp) == true)
		{
			return tmp.count;
		}

		for (int i = 0; i <= n - k; i++)
		{
			numStream next_val = reverse(tmp, i);
			
			int num = make_num(next_val);

			auto it = chk_map.find(num);
			if (it == chk_map.end())
			{
				chk_map.insert(pair<int, int>(num, 1));
				bfs_queue.push(next_val);
			}
		}
	}

	return -1;
}


int main()
{
	input.count = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		//cin >> input.numArr;
		scanf("%d", &input.numArr[i]);
	}

	printf("%d", bfs());


	return 0;
}

#if 0


//template <typename T>
//class queue
//{
//	T data[10000];
//	int front, rear;
//
//public:
//	queue():front(0),rear(0){}
//
//	void push(T input)
//	{
//		data[rear++ % 10000] = input;
//	}
//	
//	T pop()
//	{
//		return data[front++ % 10000];
//	}
//
//	bool is_empty()
//	{
//		if (front == rear)
//			return true;
//		else
//			return false;
//	}
//
//	bool find(T input)
//	{
//		for (int i = front; i < rear; i++)
//		{
//			if (data[i % 10000] == input)
//				return true;
//		}
//		return false;
//	}
//};

#endif
