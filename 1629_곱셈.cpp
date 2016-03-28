#include <stdio.h>

long long rec(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a%c;

	else if (b % 2 == 0)
		return (rec(a, b / 2, c) * rec(a, b / 2, c)) % c;
	else
		return (rec(a, b / 2, c) * rec(a, b / 2 + 1, c)) % c;
}

int main()
{
	long long a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	printf("%lld", rec(a, b, c));

	return 0;
}