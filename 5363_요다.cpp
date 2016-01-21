#include <iostream>
#include <string.h>

using namespace std;

char line[105];
char temp[105];
int main()
{
	int n;

	cin >> n;
	//char temp;
	cin.getline(line, 1);

	for (int a = 0; a < n; a++)
	{
		cin.getline(line, 100);
		cin.clear();
		int count = 0;
		int tempIndex = 0;
		bool flag = true;
		for (int i = 0; i < strlen(line); i++)
		{
			while (count != 2 && i<strlen(line))
			{
				if (line[i] == ' ')
					count++;
				if (count == 2)
					break;
				temp[tempIndex] = line[i];
				tempIndex++;
				i++;
			}
			temp[tempIndex] = '\0';
			if (flag == true && tempIndex != 0)
			{
				flag = false;
				i++;
			}

			cout << line[i];
		}

		if (tempIndex != 0)
			cout << " ";
		cout << temp << endl;

	}

	return 0;
}