#include <iostream>
#include <string.h>

using namespace std;

char wordArr[105];

void swaping(int f, int e)
{
	char temp = wordArr[f];
	wordArr[f] = wordArr[e];
	wordArr[e] = temp;
}

void quick(int first, int end)
{
	int pivot = wordArr[(first + end) / 2];
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (wordArr[f] < pivot) f++;
		while (pivot < wordArr[e]) e--;

		if (f <= e)
		{
			swaping(f, e);
			
			f++;
			e--;
		}
	}

	if (first < e) quick(first, e);
	if (f < end) quick(f, end);
}


int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> wordArr;
		int wordLen = strlen(wordArr);

		bool is_swap = false;
		int j;

		for (int k = wordLen - 1; k > 0; k--)
		{
			for (j = k - 1; j >= 0; j--)
			{
				if (wordArr[j] < wordArr[k])
				{
					is_swap = true;
					swaping(j, k);
					break;
				}
			}
			if (is_swap == true)
				break;
		}
		
		if (is_swap==1)
			quick(j + 1, wordLen - 1);

		//swaping(wordLen - 2, wordLen - 1);

		cout << wordArr << endl;
	}



	return 0;
}