#include <iostream>

using namespace std;

int main()
{
	int inputNum;

	cin >> inputNum;
	
	while (inputNum != 0)
	{
		int maxSize = 1;
		int res = 0;
		while (inputNum > maxSize*maxSize)
		{
			maxSize++;
		}

		int sum = 0;

		for (int i = maxSize; i >= 1; i--)
		{
			sum += i*i;
			if (sum < inputNum)
			{
				for (int j = i; j >= 1; j--)
				{
					if (sum + j*j * 3 < inputNum)
						break;
					sum += j*j;
					if (sum < inputNum)
					{
						for (int k = j; k >= 1; k--)
						{
							if (sum + k*k * 2 < inputNum)
								break;
							sum += k*k;
							if (sum < inputNum)
							{
								for (int l = k; l >= 1; l--)
								{
									if (sum + l*l < inputNum)
										break;
									sum += l*l;

									if (sum == inputNum)
									{
										res++;
									}

									sum -= l*l;
								}
							}
							else if (sum == inputNum)
							{
								res++;
							}
							sum -= k*k;
						}
					}
					else if (sum == inputNum)
					{
						res++;
					}
					sum -= j*j;
				}
			}
			else if (sum==inputNum)
			{
				res++;
			}
			sum -= i*i;
		}
		cout << res << endl;
		cin >> inputNum;
	}

	return 0;
}