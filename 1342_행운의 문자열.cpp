#include <iostream>
#include <string.h>

using namespace std;

int alpaArr[27];
char input[11];
char output[11];
int inputLen;

int cnt = 0;

void dfs(int idx)
{
	if (idx > inputLen)
		return;

	/*if (idx != 0)
	{
		if (output[idx - 1] == output[idx])
			return;
	}*/
	
	if (idx == inputLen)
	{
		//cout << output << endl;
		cnt++;
		return;
	}

	//cout << idx << endl;
	for (int i = 0; i < 26; i++)
	{
		if (alpaArr[i] > 0)
		{
			output[idx] = (char)('a' + i);
			if (idx != 0)
			{
				if (output[idx - 1] == output[idx])
					continue;
			}
			//cout << alpaArr[i] << endl;
			alpaArr[i]--;
			dfs(idx + 1);
			alpaArr[i]++;
		}		
	}
}

int main()
{
	cin >> input;
	inputLen = strlen(input);

	for (int i = 0; i < inputLen; i++)
	{
		alpaArr[input[i] -'a']++;
	}

	dfs(0);
	cout << cnt << endl;


	return 0;
}