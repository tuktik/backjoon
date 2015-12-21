#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char buff[100]; 
	int count = 0;
	while (cin >> buff)
	{
		if (buff[0] == '<' && buff[1] == 'b' && buff[2] == 'r' && buff[3] == '>')
		{
			cout << endl;
			count = 0;
			continue;
		}
		if (buff[0] == '<' && buff[1] == 'h' && buff[2] == 'r' && buff[3] == '>')
		{
			if (count!=0)
			{
				cout << endl;
			}
			
			for (int i = 0; i < 80; i++)
				cout << '-';
			cout << endl;
			count = 0;
			continue;
		}
		
		
		
		//count += (strlen(buff) + 1);
		//cout << count << endl;
		
		if (count+strlen(buff) >= 80)
		{
			cout << endl;
			count = 0;
			cout << buff;
			count += strlen(buff);
		}
		else
		{
			if (count != 0)
			{
				cout << " ";
				count++;
			}
			cout << buff;
			count += strlen(buff);
		}
		
		
	}

	
	//scanf("%[^\n]s", str);

	/*for (int i = 0; i < 100; i++)
		printf("%c", str[i]);*/
	return 0;
}