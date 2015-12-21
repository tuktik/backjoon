#include <iostream>

using namespace std;

int main()
{
	int length;

	cin >> length;

	int sum=0;
	int nowNum=0;
	int cnt = 0;
	char tmp;
	bool is_num = false;

	for (int i = 0; i <length; i++)
	{
		cin >> tmp;
		//cout << i << "!" << endl;
		if (tmp>=48 && tmp <=57 && cnt<=5)
		{
			if (is_num == true)
			{
				nowNum *= 10;
			}
			nowNum += (tmp - 48);
			cnt++;
			is_num = true;
		}
		else
		{
			cnt = 0;
			sum += nowNum;
			//cout << sum <<"!!!"<< endl;
			nowNum = 0;
			is_num = false;
		}
		//cout << nowNum << endl;
	}

	//tmp = '9';
	// 0 = 48
	if (is_num ==true)
		sum += nowNum;
	cout << sum << endl;

	return 0;
}