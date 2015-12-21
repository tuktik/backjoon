#include <iostream>

using namespace std;

int input_num;
int input_num_count;
int res = 0;

void func(int now_num, int sum, int count)
{
	if (input_num < sum)
		return;
	if (now_num ==0)
		return;
	if (now_num*now_num*(4 - count) + sum < input_num)
		return;

	//cout << now_num << " " << sum << " " << count << endl;

	if (count == 4 && input_num == sum)
	{
		res++;
		return;
	}
	else if (count ==4)
		return;

	func(now_num, sum + now_num*now_num, count+1);
	func(now_num-1, sum + now_num*now_num, count+1);
	func(now_num-1, sum, count);
}

int main()
{
	cin >> input_num;

	int maxNum=1;
	while (input_num != 0)
	{
		while ((maxNum+1)*(maxNum+1) <= input_num)
		{
			maxNum++;
		}
		
		func(maxNum , 0, 0);

		cout << res<<"!!!"<< endl;

		cin >> input_num;
		res = 0;
	}


	return 0;
}