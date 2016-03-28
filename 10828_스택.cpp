#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
	int inst;

	cin >> inst;

	char instSet[10];
	int data;

	stack<int> global_stack;

	while (inst--)
	{
		cin >> instSet;

		if (strcmp(instSet, "push")==0)
		{
			cin >> data;
			global_stack.push(data);
		}
		else if (strcmp(instSet, "pop") == 0)
		{
			if (global_stack.empty())
				cout << -1 << endl;
			else
			{
				data = global_stack.top();
				global_stack.pop();
				cout << data << endl;
			}
		}
		else if (strcmp(instSet, "size") == 0)
		{
			cout << global_stack.size() << endl;
		}
		else if (strcmp(instSet, "empty") == 0)
		{
			cout << global_stack.empty() << endl;
		}
		else if (strcmp(instSet, "top") == 0)
		{
			if (global_stack.empty())
				cout << -1 << endl;
			else
				cout << global_stack.top() << endl;
		}
	}



	return 0;
}