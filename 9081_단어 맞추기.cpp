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

		int swapA = -1;
		int swapB;
		int j,k;
		for (k = wordLen - 1; k >= 0; k--)
		{
			for (j = k ; j >= 0 && wordArr[j] >= wordArr[k]; j--);
			if (j >= 0 && swapA<j)
			{
				swapA = j;
				swapB = k;
			}
		}
		
		if (swapA != -1)
		{
			swaping(swapA, swapB);
			quick(swapA + 1, wordLen - 1);
		}
			

		//swaping(wordLen - 2, wordLen - 1);

		cout << wordArr << endl;
	}



	return 0;
}

//
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//char a[101], k;
//int t, i, j, m, n;
//
//int cmp(void *a, void *b)
//{
//	return (char*)a>(char*)b ? 1 : (char*)a<(char*)b ? -1 : 0;
//}
//void main()
//{
//	for (scanf("%d ", &t); t--; puts(a))
//	{
//		m = -1;
//		for (i = strlen(gets(a)) - 1; i >= 0; i--)
//		{
//			for (j = i; j >= 0 && a[i] <= a[j]; j--);
//			if (j >= 0 && m<j)
//			{ 
//				m = j; 
//				n = i;
//				printf("%d %d\n", n, m);
//			}
//		}
//		if (m != -1)
//		{
//			for (k = a[n]; n>m; n--)a[n] = a[n - 1]; a[m] = k;
//			qsort(a + m + 1, strlen(a + m + 1), 1, cmp);
//		}
//	}
//}