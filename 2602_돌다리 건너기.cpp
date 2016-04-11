#include <iostream>
#include <string.h>

using namespace std;

char word[21];
char angel[101];
char devil[101];

bool now_pos = true;

void bit_conversion()
{
	if (now_pos == true)
		now_pos = false;
	else
		now_pos = true;
}

int main()
{
	cin >> word;
	cin >> angel;
	cin >> devil;
	
	int wordLen = strlen(word);
	int bridgelLen = strlen(angel);
	


	for (int i = 0; i < wordLen; i++)
	{
		for (int j = 0; j < bridgelLen; j++)
		{

		}
		
	}
	

	return 0;
}