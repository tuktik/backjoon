#include <iostream>

using namespace std;

int calcArr[40000][5];

void func(int num)
{
	for (int i = 1; i <=num / 2; i++)
	{
		calcArr[num][2] += (calcArr[num - i][1] * calcArr[i][1]);
	}
	
	for (int i = 1; i <= num/2 ; i++)
	{
		calcArr[num][3] += (calcArr[num - i][2] * calcArr[i][1]);
		calcArr[num][3] += (calcArr[num - i][1] * calcArr[i][2]);
	}

	for (int i = 1; i <= num / 2; i++)
	{
		calcArr[num][4] += (calcArr[num - i][3] * calcArr[i][1]);
		calcArr[num][4] += (calcArr[num - i][2] * calcArr[i][2]);
		calcArr[num][4] += (calcArr[num - i][1] * calcArr[i][3]);
	}
}

int main()
{
	for (int i = 1; i*i <= 32768; i++)
	{
		calcArr[i*i][1] = 1;
	}
	
	calcArr[1][1] = 1;
	calcArr[2][2] = 1;
	calcArr[3][3] = 1;
	calcArr[4][4] = 1;
	for (int i = 5; i*i <= 32768; i++)
	{
		func(i);
	}

	
	for (int i = 1; i <= 25; i++)
	{
		cout << calcArr[i][1] << " " << calcArr[i][2] << " " << calcArr[i][3] << " " << calcArr[i][4] << endl;
	}

	/*int input;

	cin >> input;
	
	while (input != 0)
	{
		cout << calcArr[input][1] + calcArr[input][2] + calcArr[input][3] + calcArr[input][4] << endl;
		cout << calcArr[input][1] << " " << calcArr[input][2] << " " << calcArr[input][3] << " " << calcArr[input][4] << endl;
		cin >> input;
	}*/

	return 0;
}