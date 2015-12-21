#include <iostream>
#include <string.h>

using namespace std;


int main()
{
	char string[151];

	while (cin >> string)
	{
		int i = 0;
		bool is_submarine = true ;
		bool is_complete = false;

		while (is_submarine)
		{
			if (string[i] == '1' && is_submarine == true)
			{
				i++;
				if (string[i] == '0' && is_submarine == true)
				{
					i++;
					if (string[i] == '0' && is_submarine == true)
					{
						while (string[i] == '0' && is_submarine==true)	///!!!!!!!!!1
						{
							i++;
							//cout << i << endl;
						}
					}
					else
					{
						is_submarine = false;
						break;
					}
					
					if (string[i] == '1' && is_submarine == true)
					{
						while (string[i] == '1' && is_submarine == true)   ///!!!!!!!!!1
						{
							i++;
							//cout << i << endl;
						}
					}
					else
					{
						is_submarine = false;
						break;
					}
					
				}
				else
				{
					is_submarine = false;
					break;
				}
			}
			else
			{
				is_submarine = false;
				break;
			}
			if (string[i] == '0' && is_submarine == true)
			{
				i++;
				if (string[i] == '1' && is_submarine == true)
				{
					i++;
					//cout << i << endl;
				}
				else
				{
					is_submarine = false;
					break;
				}
			}
			else
			{
				is_submarine = false;
				break;
			}
			if (strlen(string) == i)
			{
				is_complete = true;
				break;
			}
			else if (strlen(string) < i)
				break;
		}

		if (is_complete == true)
			cout << "SUBMARINE" << endl;
		else
			cout << "NOISE" << endl;
	}

	return 0;
}