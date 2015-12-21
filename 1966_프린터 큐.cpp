#include <iostream>

using namespace std;

class task
{
public:
	int data;
	int indexNum;
	
	task(){}
	task(int data, int indexNum) :data(data), indexNum(indexNum){}
};

class queue
{
	task data[10000];
	int front, rear;
	int count;
	
public:
	queue() :front(0), rear(0), count(0)
	{
		//data = new task[10000];
	}
	void init()
	{
		count = 0;
		rear = 0;
		front = 0;
	}
	void push(task new_task)
	{
		//task new_task(input_data, input_indexNum);
		data[rear%10000] = new_task;
		rear++;
	}

	task pop()
	{
		return data[front++ % 10000];
	}

	bool __is_upper(int index)
	{
		for (int i = front; i < rear; i++)
		{
			if (data[i].data > data[front].data)
			{
				return true;
			}
		}
		return false;
	}

	int is_index_pop(int index)
	{
		for (int i = front; i < rear; i++)
		{
			if (__is_upper(i))
			{
				push(pop());
			}
			else if (data[i].indexNum==index)
			{
				count++;
				pop();
				break;
			}
			else
			{
				pop();
				count++;
			}
		}
		return count;
	}

	/*int get_priority(int index)
	{
		while ()
		{

		}
	}*/
	
};

queue global_queue;

int main()
{
	int testNum;

	cin >> testNum;

	for (int a = 0; a < testNum; a++)
	{
		global_queue.init();

		int taskNum;
		cin >> taskNum;

		int getIndex;
		cin >> getIndex;

		for (int i = 0; i < taskNum; i++)
		{
			int data;
			cin >> data;
			global_queue.push(task(data, i));
		}

		cout<<global_queue.is_index_pop(getIndex)<<endl;
		
	}

	return 0;
}