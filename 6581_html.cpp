#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

char buff[10000];

int main()
{
	int i =0;
	cin >> buff[i];
	while(buff[i]!='\0')
	{
		i++;
		cin >> buff[i];
	}

	i =0;
	bool tag = false;
	int count = 0;

	while(buff[i]!= '\0')
	{
		if (tag == true)
		{
			if (buff[i] == 'h' && buff[i + 1] == 'r' && buff[i + 2] == '>')
			{
				cout << endl;
				for (int i = 0; i < 80; i++)
					cout << '-';
				cout << endl;
				count = 0;
			}
			else if (buff[i] == 'b' && buff[i + 1] == 'r' && buff[i + 2] == '>')
			{
				cout << endl;
				count = 0;
			}
			i += 2;
		}
		else
		{
			if (buff[i] == '<')
				tag = true;
			else
			{ 
				printf("%c", buff[i]);
				count++;
			}
			if (count == 80)
				cout << endl;
		}
		i++;
	}

	return 0;
}