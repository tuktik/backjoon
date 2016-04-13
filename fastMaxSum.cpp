#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int fastMaxSum(const vector<int>& A, int lo, int hi)
{
	if (lo == hi)	return A[lo];

	int mid = (lo + hi) / 2;

	int left = -999999, right = -999999, sum = 0;
	for (int i = mid; i >= lo; --i)
	{
		sum += A[i];
		left = max(left, sum);
	}

	sum = 0;

	for (int j = mid + 1; j <= hi; ++j)
	{
		sum += A[j];
		right = max(right, sum);
	}

	int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));

	return max(left + right, single);
}

int main()
{

	return 0;
}