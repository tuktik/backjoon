#include <iostream>

using namespace std;

int main()
{
	int inputNum;

	cin >> inputNum;

	int num = 1;


	while (inputNum>num*num)
	{
		num *= 10;
	}

	int prev = num/10;
	int next = num;
	int pivot = (prev + next) / 2;
	bool is_squareNum = false;
	while (1)
	{
		//cout << prev << " " << next << " " << pivot << endl;
		if (pivot*pivot > inputNum)
			next = pivot;
		else if (pivot*pivot < inputNum)
			prev = pivot;
		else
		{
			is_squareNum = true;
			break;
		}

		pivot = (prev + next) / 2;

		if (pivot == next || pivot == prev)
			break;
	}
	int resNum = 9999999999;


	cout << prev << " " << next << endl;
	if (inputNum <=4)
	{
		cout << "4" << endl;
		return 0;
	}

	//cout << prev << " " << next << endl;
	if (is_squareNum == true)
	{
		cout << pivot << endl;
		resNum = (pivot - 1) * 2 *2;
	}
	else
	{
		if (inputNum > prev*next)
		{
			resNum = (next - 1) * 4;
		}
		else
		{
			resNum = (next + prev - 2) * 2;
		}
	}

	cout << resNum << endl;

	//cout << prev << " " << next << endl;
	return 0;
}