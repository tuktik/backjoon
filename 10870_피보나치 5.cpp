#include <iostream>

using namespace std;

unsigned long long arr[100];
int n;

void fib(int idx)
{
	if (idx > n)
		return;
	if (idx == 0)
		arr[idx] = 0;
	if (idx == 1)
		arr[idx] = 1;
	else
		arr[idx] =  arr[idx - 2] + arr[idx - 1];
	
	fib(idx + 1);
}

int main()
{
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	fib(0);
	cout << arr[n] << endl;

	return 0;
}