#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
	int inst;

	cin >> inst;

	char instSet[10];
	int data;

	queue<int> global_queue;

	while (inst--)
	{
		cin >> instSet;

		if (strcmp(instSet, "push") == 0)
		{
			cin >> data;
			global_queue.push(data);
		}
		else if (strcmp(instSet, "pop") == 0)
		{
			if (global_queue.empty())
				cout << -1 << endl;
			else
			{
				data = global_queue.front();
				global_queue.pop();
				cout << data << endl;
			}
		}
		else if (strcmp(instSet, "size") == 0)
		{
			cout << global_queue.size() << endl;
		}
		else if (strcmp(instSet, "empty") == 0)
		{
			cout << global_queue.empty() << endl;
		}
		else if (strcmp(instSet, "front") == 0)
		{
			if (global_queue.empty())
				cout << -1 << endl;
			else
				cout << global_queue.front() << endl;
		}
		else if (strcmp(instSet, "back") == 0)
		{
			if (global_queue.empty())
				cout << -1 << endl;
			else
				cout << global_queue.back() << endl;
		}
	}



	return 0;
}