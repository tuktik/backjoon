#include <stdio.h>

int numArr[10];
int n;
int k;

class queue
{
	int data[100000];
	int front, rear;

public:
	queue():front(0),rear(0){}

	void push(int input)
	{
		data[rear++] = input;
	}
	
	int pop()
	{
		return data[front++];
	}

	bool is_empty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}

	bool find(int input)
	{
		for (int i = front; i < rear; i++)
		{
			if (data[i] == input)
				return true;
		}
		return false;
	}
};

queue chk_queue;
queue bfs_queue;

int make_num()
{
	int num = 0;

	for (int i = 0; i<)
}

void bfs()
{


}

bool is_sorted()
{
	bool is_sort = true;
	for (int i = 0; i < n; i++)
	{
		if (numArr[i] != i + 1)
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

void reverse(int idx)
{
	for (int i = 0; i < k/2; i++)
	{
		int temp = numArr[idx+i];
		numArr[idx + i] = numArr[idx + k - 1 - i];
		numArr[idx + k - 1 - i] = temp;
	}
}

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numArr[i]);
	}





	return 0;
}

