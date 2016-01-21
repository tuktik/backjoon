#include <iostream>

using namespace std;

int sumArr[10001][3];
int inputArr[10001];

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> inputArr[i];
		if (i == 0)
		{
			sumArr[0][0] = inputArr[i];
			sumArr[0][1] = 0;
			sumArr[0][2] = inputArr[i];
		}
		else if (i == 1)
		{
			sumArr[i][0] = sumArr[0][0];
			sumArr[i][1] = sumArr[0][1] + inputArr[i];
			sumArr[i][2] = sumArr[0][2] + inputArr[i];
		}
		else
		{
			int zero_max = sumArr[i - 1][0]>sumArr[i - 1][1] ? sumArr[i - 1][0] : sumArr[i - 1][1];
			zero_max = sumArr[i - 1][2] > zero_max ? sumArr[i - 1][2] : zero_max;
			sumArr[i][0] = zero_max;
			sumArr[i][1] = sumArr[i - 1][0] + inputArr[i];
			sumArr[i][2] = sumArr[i - 1][1] + inputArr[i];
			//cout << sumArr[i][0] << " " << sumArr[i][1] << " " << sumArr[i][2] << endl;
		}
	}

	int max = 0;


	max = sumArr[N - 1][0] > sumArr[N - 1][1] ? sumArr[N - 1][0] : sumArr[N - 1][1];

	if (max < sumArr[N - 1][2])
		max = sumArr[N - 1][2];

	cout << max << endl;




	return 0;
}