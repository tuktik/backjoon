#include <iostream>
#include <string.h>

using namespace std;

char inputArr[12][35];
int check[12];
int rsp[3];

int main()
{
	int t;

	cin >> t;

	int n;

	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> inputArr[i];
			//cout << inputArr[i];
		}
			

		
		int sLen = strlen(inputArr[1]);
		int checkCount = 0;
		for (int i = 0; i < sLen; i++)
		{
			//cout << "!";
			for (int j =1; j <=n; j++)
			{
				if (inputArr[j][i] == 'R'&&check[j]==0)
					rsp[0] = 1;
				if (inputArr[j][i] == 'S'&&check[j] == 0)
					rsp[1] = 1;
				if (inputArr[j][i] == 'P'&&check[j] == 0)
					rsp[2] = 1;
			}
			//cout << rsp[0] << " " << rsp[1] << " " << rsp[2]<<" "<<i << endl;
			if (rsp[0] == 1 && rsp[1] == 1 && rsp[2] == 1)
			{
				rsp[0] = 0;
				rsp[1] = 0;
				rsp[2] = 0;

				continue;
			}
				

			if (rsp[0] == 1 && rsp[1] == 1)
			{
				for (int j = 1; j <=n; j++)
				{
					if (inputArr[j][i] == 'S'&&check[j] == 0)
					{
						check[j] = 1;
						checkCount++;
					}	
				}
			}
			if (rsp[1] == 1 && rsp[2] == 1)
			{
				for (int j = 1; j <=n; j++)
				{
					if (inputArr[j][i] == 'P'&&check[j] == 0)
					{
						check[j] = 1;
						checkCount++;
					}
						
				}
			}
			if (rsp[0] == 1 && rsp[2] == 1)
			{
				for (int j = 1; j <=n; j++)
				{
					if (inputArr[j][i] == 'R'&&check[j] == 0)
					{
						check[j] = 1;
						checkCount++;
					}
						
				}
			}

		/*	for (int j = 1; j <=n; j++)
			{
				cout << check[j] << " ";
			}*/
			//cout << endl;
			rsp[0] = 0;
			rsp[1] = 0;
			rsp[2] = 0;

			if (checkCount == (n - 1))
			{
				//cout << "break" << endl;
				break;
			}
				
		}
		//cout << "!";
		int outputIdx = -1;
		for (int i = 1; i <=n; i++)
		{
			if (check[i] == 0 && outputIdx == -1)
			{
				outputIdx = i;
				//cout << "!";
			}
			else if (check[i] == 0)
			{
				outputIdx = 0;
				break;
			}
		}
		cout << outputIdx << endl;

		for (int i = 1; i <= n; i++)
		{
			check[i] = 0;
		}
	}


	return 0;
}