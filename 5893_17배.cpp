#include <iostream>
#include <string.h>

using namespace std;

char inputBin[1002];
char outputBin[3004];

void reverse()
{
	int len = strlen(outputBin);

	for (int i = 0; i < len / 2; i++)
	{
		char temp = outputBin[i];
		outputBin[i] = outputBin[len - i - 1];
		outputBin[len - i - 1] = temp;
	}
	//cout << outputBin << endl;
}

void mul()
{
	int len = strlen(inputBin);
	//cout << len << endl;
	for (int i = 0; i <len; i++)
	{
		outputBin[i]=(inputBin[i] - 48) * 17;
		//cout << (int)outputBin[i] << endl;
	}
	outputBin[len] = '\0';
	//cout << outputBin << endl;
}

void printBin(int maxIndex)
{
	for (int i = 0; i <maxIndex; i++)
	{
		outputBin[i] += 48;
		cout << outputBin[i];
	}
	cout << endl;
}

void makebin()
{
	int len = strlen(inputBin);
	int maxIndex=0;
	//cout << len << endl;
	for (int i = 0; i <len; i++)
	{
		//cout << i << endl;
		int j = 0;
		int num = outputBin[i];
		outputBin[i] = 0;
		do
		{
			outputBin[i+j] += (num % 2);
			num = num / 2;
			j++;
			printBin(12);
		} while (num != 0);

		if (maxIndex < i + j)
			maxIndex = i + j;
	}
	//cout << maxIndex << endl;
	cout << maxIndex << endl;
	for (int i = 0; i <maxIndex; i++)
	{
		//if (outputBin[i] == '\0')
			//outputBin[i] = 48;
	}
	outputBin[maxIndex] = '\0';

	printBin(maxIndex);
}

int main()
{
	cin >> inputBin;

	mul();
	reverse();
	makebin();
	reverse();

	cout << outputBin << endl;


	return 0;
}

#if 0

int main()
{
	cin >> inputBin;

	int num = getNum();

	num *= 17;

	//makeBin(num);
	makeBin(num);

	//cout << inputBin << endl;
	reverse();
	cout << outputBin << endl;
	

	return 0;
}



int pow(int num)
{
	if (num == 0)
		return 1;
	else
		return pow(num - 1) * 2;
}

int getNum()
{
	int len = strlen(inputBin);
	int num = 0;
	for (int i = 0; i <strlen(inputBin); i++)
	{
		num += ((inputBin[len - i - 1] - 48) * pow(i));
	}

	return num;
}

void makeBin(int num)
{
	int i = 0;

	do
	{
		outputBin[i] = num % 2 + 48;
		num = num / 2;
		i++;
		//cout<<
	} while (num != 0);
	outputBin[i] = '\0';
}


#endif