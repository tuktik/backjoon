#include <iostream>

using namespace std;

int main()
{
	char buff[10000];
	int ppong = 0;

	int number;

	cin >> number;

	while (number!=0)
	{
		while (number)
		{
			cin.getline(buff, 1000);
			
			for (int i = 0; i < strlen(buff);i++)`

			number--;
		}

		cin >> number;
	}
	
	
	
	//cout << buff << endl;
	/*while ()
	{
		for (int i = 0; i < strlen(buff); i++)
		{
			if (buff[i] == ' ' && i > ppong)
			{
				ppong = i;
			}
		}
	}*/
	return 0;
}