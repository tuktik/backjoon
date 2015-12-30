#include <iostream>

using namespace std;

int inputArr[1001][3];
int minsumArr[1001][3];

int main()
{
	int N; 

	cin >> N;

	for (int i = 1; i <=N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> inputArr[i][j];

		minsumArr[i][2] = (minsumArr[i - 1][0] < minsumArr[i - 1][1] ? minsumArr[i - 1][0] : minsumArr[i - 1][1]) + inputArr[i][2];
		minsumArr[i][1] = (minsumArr[i - 1][0] < minsumArr[i - 1][2] ? minsumArr[i - 1][0] : minsumArr[i - 1][2]) + inputArr[i][1];
		minsumArr[i][0] = (minsumArr[i - 1][1] < minsumArr[i - 1][2] ? minsumArr[i - 1][1] : minsumArr[i - 1][2]) + inputArr[i][0];
	}

	int min;

	min = minsumArr[N][0] < minsumArr[N][1] ? minsumArr[N][0] : minsumArr[N][1];
	min = min < minsumArr[N][2] ? min : minsumArr[N][2];

	cout << min << endl;
	return 0;
}