#include <stdio.h>

int eratos[1000000];


void eratosCal()
{
	eratos[0] = 1;
	eratos[1] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; i*j <= 1000000; j++)
		{
			eratos[i*j] = 1;
		}
	}
}

int main()
{
	int n;

	eratosCal();

	scanf("%d", &n);

	while (n != 0)
	{
		bool flag = false;
		for (int i = 2; i <= n / 2; i++)
		{
			if (eratos[i] == 0 && eratos[n - i] == 0)
			{
				flag = true;
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
		if (flag == false)
			printf("Goldbach's conjecture is wrong.\n");

		scanf("%d", &n);
	}

	return 0;
}