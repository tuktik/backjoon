#include <iostream>

using namespace std;

int triArr[1001];

int main()
{
	int testNum;

	cin >> testNum;

	for (int i = 0; i < testNum; i++)
	{
		int inputNum;

		cin >> inputNum;

		for (int i = 1; i <= 1000; i++)
		{
			triArr[i] = triArr[i - 1] + i;
			//cout << triArr[i]<<endl;
		}

		int sum = 0;
		bool res = false;

		for (int i = inputNum; i >= 1; i--)
		{
			if (inputNum > triArr[i] * 3)
				break;
			if (triArr[i]>inputNum)
				continue;
			else
				sum += triArr[i];
			for (int j = i; j >= 1; j--)
			{
				if (inputNum > sum + triArr[j] * 2)
					break;
				sum += triArr[j];
				if (sum < inputNum)
				{
					for (int k = j; k >= 1; k--)
					{
						if (sum +triArr[k]< inputNum)
							break;
						sum += triArr[k];
						//cout << i <<" "<<j<<" "<<k << endl;
						if (sum == inputNum)
						{
							res = true;
							break;
						}
						sum -= triArr[k];
					}
				}
				if (res==true)
				{
					break;
				}
				sum -= triArr[j];
			}
			if (res == true)
			{
				break;
			}
			sum -= triArr[i];
		}

		//cout << sum << endl;
		if (res == true)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

	return 0;
}