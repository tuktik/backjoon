#include <iostream>

using namespace std;

int numArr[100002];
int mArr[100002][2];
int outputArr[100002];

int main()
{
	int numCount;

	cin >> numCount;


	int sum = 0;
	for (int i = 1; i <= numCount; i++)
	{
		cin >> numArr[i];
		sum += numArr[i];
		
		outputArr[i] = sum;
		/*for (int j = i; j >=1; j--)
		{
			outputArr[j] += numArr[i];
		}*/
	}

	int start, end;

	int sumNum;

	cin >> sumNum;

	

	for (int i = 1; i <= sumNum; i++)
	{
		cin >> start;

		cin >> end;

		//cout << outputArr[start] <<" "<< outputArr[end + 1] << endl;
		cout << outputArr[end] - outputArr[start-1] << endl;
	}
	return 0;
}