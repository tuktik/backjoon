#include <stdio.h>


long long cal(int N, int K)
{
	long long res = 1;
	for (int i = N, j = 1; i > N - K; i--, j++)
	{
		res = (res * (long long)i) % 1000000007;
		res = res / (long long)j;
		//res %= 1000000007;

	}
	return res % (long long)1000000007;
}



int main()
{
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%lld", cal(N, K));

	return 0;
}

/*
long long rec(int n, int k)
{
if (k == 1)
return n% 1000000007;
if (n - k == 1)
return n % 1000000007;
if (k == 0)
return 1;

return (rec(n - 1, k - 1) % 1000000007 + rec(n - 1, k) % 1000000007)% 1000000007;
}

//1000000007

*/