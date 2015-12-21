#include <iostream>

using namespace std;

int arrCountry[1001][4];

int countryNum;

void swap(int a, int b)
{
	int tempArr[4];

	tempArr[0] = arrCountry[a][0];
	tempArr[1] = arrCountry[a][1];
	tempArr[2] = arrCountry[a][2];
	tempArr[3] = arrCountry[a][3];

	arrCountry[a][0] = arrCountry[b][0];
	arrCountry[a][1] = arrCountry[b][1];
	arrCountry[a][2] = arrCountry[b][2];
	arrCountry[a][3] = arrCountry[b][3];

	arrCountry[b][0] = tempArr[0];
	arrCountry[b][1] = tempArr[1];
	arrCountry[b][2] = tempArr[2];
	arrCountry[b][3] = tempArr[3];

}

bool compare(int a, int b)
{
	if (arrCountry[a][1] < arrCountry[b][1])
		return true;
	else if (arrCountry[a][1] > arrCountry[b][1])
		return false;
	else
	{
		if (arrCountry[a][2] < arrCountry[b][2])
			return true;
		else if (arrCountry[a][2] > arrCountry[b][2])
			return false;
		else
		{
			if (arrCountry[a][3] < arrCountry[b][3])
				return true;
			else
				return false;
		}
	}
}

void sort()
{
	for (int i = 1; i < countryNum; i++)
	{
		for (int j = i + 1; j <= countryNum; j++)
		{
			if (compare(i, j))
			{
				swap(i, j);
			}
		}
	}
}

int main()
{
	int getCountry;

	cin >> countryNum >> getCountry;

	int country;
	int goldMedal;
	int silverMedal;
	int bronzeMedal;

	for (int i = 1; i <= countryNum; i++)
	{
		cin >> country >> goldMedal >> silverMedal >> bronzeMedal;

		arrCountry[i][0] = country;
		arrCountry[i][1] = goldMedal;
		arrCountry[i][2] = silverMedal;
		arrCountry[i][3] = bronzeMedal;
	}

	sort();

	int grade = 0;

	arrCountry[0][0] = -1;
	arrCountry[0][1] = -1;
	arrCountry[0][2] = -1;
	arrCountry[0][3] = -1;

	for (int i = 1; i <= countryNum; i++)
	{
		if (arrCountry[i - 1][1] != arrCountry[i][1]
			|| arrCountry[i - 1][2] != arrCountry[i][2]
			|| arrCountry[i - 1][3] != arrCountry[i][3]
			)
		{
			grade = i;
		}


		if (arrCountry[i][0] == getCountry)
			break;

		//cout << arrCountry[i][0] << arrCountry[i][1] << arrCountry[i][2] << arrCountry[i][3] << endl;
	}

	cout << grade << endl;
	return 0;
}