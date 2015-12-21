#include <iostream>

using namespace std;

int troopsArr[500001];

int main()
{
	int troopsCount;

	cin >> troopsCount;

	for (int i = 1; i <= troopsCount; i++)
	{
		cin >> troopsArr[i];
	}
	
	int inst;

	while (cin >> inst)
	{
		if (inst == 1)
		{
			int troopNum;

			cin >> troopNum;

			int man;

			cin >> man;

			troopsArr[troopNum] += man;
		}
		else if (inst == 2)
		{
			int get_man;
			int sum = 0;
			int i = 0;

			cin >> get_man;

			while (get_man > sum)
			{
				sum += troopsArr[i++];
			}
			cout << i-1 << endl;
		}
	}


	return 0;
}