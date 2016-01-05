#include <iostream>
#include <string.h>

using namespace std;

char inputBin[5002];

void reverse()
{
	int len = strlen(inputBin);
	//cout << len << endl;
	for (int i = 0; i < len / 2; i++)
	{
		char temp = inputBin[i];
		inputBin[i] = inputBin[len - i - 1];
		inputBin[len - i - 1] = temp;
	}
}

int mult()
{
	int len = strlen(inputBin);
	//cout << len << endl;
	for (int i = 0; i < len; i++)
	{
		inputBin[i] = (inputBin[i] - 48) * 17;
	}
	return len;
}

void makeBin(int len)
{
	//int len = strlen(inputBin);
	//cout << len << endl;
	for (int i = 0; i < len; i++)
	{
		int num = inputBin[i];
		inputBin[i] = 0;
		int j = 0;
		do
		{
			inputBin[i+j] += (num % 2);
			//cout << (char)(inputBin[i]+48);
			num = num / 2;
			j++;
		} while (num != 0);
		if (i + j > len)
			len = i + j;

		inputBin[i] += 48;
	}

	inputBin[len] = '\0';
}

int main()
{
	cin >> inputBin;
	
	reverse();
	int len = mult();
	makeBin(len);
	reverse();
	cout << inputBin << endl;

	return 0;
}