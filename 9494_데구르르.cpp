#include <iostream>

using namespace std;

int main()
{
	char str[10000];
	int num;
	cin >> num;
	while (num!=0)
	{
		int ppong = 0;
		while (num)
		{
			cin.getline(str, 10000);
			cout << "1";
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == ' ' && ppong < i)
				{
					ppong = i;
					break;
				}
			}
		}
		cout << ppong << endl;

		cin >> num;
	}
	


	return 0;
}