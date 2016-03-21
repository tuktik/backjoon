#include <iostream>

using namespace std;

int n, k;

char check[28];
char circleArr[26];

int main()
{
	cin >> n >> k;

	int s;
	char tmp;

	int now_pos = 0;

	bool flag = false;

	//cout << (int)'A' << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> s;
		cin >> tmp;

		now_pos = now_pos - (s%n);
		if (now_pos < 0)
			now_pos = n + now_pos;
		
		if (circleArr[now_pos] == 0)
		{
			if (check[tmp - 65] == 1)
			{
				flag = true;
				break;
			}
			circleArr[now_pos] = tmp;
			check[tmp - 65] = 1;
			//cout << tmp;
		}
		else if (circleArr[now_pos] !=tmp)
		{
			flag = true;
			break;
		}
	}
	//cout << now_pos << endl;
	//cout << circleArr[now_pos]<<"!!!!"<< endl;

	if (flag == true)
	{
		cout << "!" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (circleArr[(now_pos + i) % n] == 0)
			cout << "?";
		else
			cout << circleArr[(now_pos+i)%n];
	}
	cout << endl;

	return 0;
}