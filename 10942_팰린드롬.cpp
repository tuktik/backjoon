#include <iostream>

using namespace std;
int n, m;

int arr[2005];
int evendp[2005];
int odddp[2005];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		while (1)
		{
			if (i - k <= 0 || i + k > 2000)
				break;
			if (arr[i - k] == arr[i + k])
				odddp[i]++;
			k++;
		}
	}
	

	for (int i = 1, j=2; j <= n; i++,j++)
	{
		int k = 0;
		while (1)
		{
			if (i - k <= 0 || j + k > 2000)
				break;
			if (arr[i - k] == arr[j + k])
			{
				evendp[i]++;
			}
			else
				break;
				
			k++;
		}
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << evendp[i] << " " << odddp[i] << endl;
	}
	*/
	cin >> m;

	while (m--)
	{
		int first;
		int second;

		cin >> first;
		cin >> second;

		int sum = first + second;

		if (sum % 2 == 0)
		{
			if (odddp[sum / 2] > (second - first) / 2)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			if (evendp[sum / 2] > (second - first) / 2)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}



	return 0;
}