#include <iostream>
#include <queue>
#include <deque>

using namespace std;

deque<int> global_queue;
int n;

int main()
{
	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		if (i != n)
		{
			int j = i;

			while (j--)
			{
				int tmp = global_queue.
				global_queue.pop();

				global_queue.push(tmp);
			}
		}
		global_queue.push(i);

		
		
	}

	return 0;
}