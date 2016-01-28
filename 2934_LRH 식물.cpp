#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int nArr[100001];
int partArr[1002];
int main()
{
	int n;
	int L, R;
	int count=0;
	int i,j;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		count = 0;
		scanf("%d", &L);
		scanf("%d", &R);
		//cin >> L;
		//cin >> R;

		count += nArr[L];
		count += nArr[R];

		int sqrtL = (int)sqrt(L) + 1;
		int sqrtR = (int)sqrt(R);

		count += partArr[sqrtL-1];
		count += partArr[sqrtR];

		printf("%d\n", count);
		//cout << count << endl;

		nArr[L] = -partArr[sqrtL-1];
		nArr[R] = -partArr[sqrtR];
		
		if (sqrtL < sqrtR)
		{
			for (j = L + 1; j <sqrtL*sqrtL; j++)
			{
				nArr[j]++;
			}

			for (j = sqrtL; j < sqrtR; j++)
			{
				partArr[j]++;
			}

			for (j = sqrtR*sqrtR; j <R; j++)
			{
				nArr[j]++;
			}
		}
		else
		{
			for (j = L + 1; j < R; j++)
			{
				nArr[j]++;
			}
		}
		

	}

	return 0;
}