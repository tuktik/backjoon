#include <iostream>

using namespace std;

//int quest[105][3];
int answerArr[1000];

int main()
{
	int n;
	
	int number;
	int strike;
	int boll;

	cin >> n;

	for (int k = 0; k < n; k++)
	{
		cin >> number;

		cin >> strike;
		cin >> boll;

		int questNum[3];
		questNum[0] = number % 10;
		questNum[1] = number % 100 / 10;
		questNum[2] = number / 100;
		
		//cout << questNum[0] << " " << questNum[1] << " " << questNum[2] << endl;

		for (int i = 111; i <= 999; i++)
		{
			int num[3];
			num[0] = i % 10;
			num[1] = i % 100 / 10;
			num[2] = i / 100;
			
			int nowNumS=0;
			int nowNumB=0;

			if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0]
				|| num[0] == 0 || num[1] == 0 || num[2]==0)
			{
				answerArr[i] = 1;
				continue;
			}
				

			if (questNum[0] == num[0])
				nowNumS++;
			else if (questNum[0] == num[1] || questNum[0] == num[2])
				nowNumB++;
			if (questNum[1] == num[1])
				nowNumS++;
			else if (questNum[1] == num[0] || questNum[1] == num[2])
				nowNumB++;
			if (questNum[2] == num[2])
				nowNumS++;
			else if (questNum[2] == num[0] || questNum[2] == num[1])
				nowNumB++;

			

			if (strike != nowNumS || boll != nowNumB)
				answerArr[i] = 1;
		}

	}

	int counting = 0;

	for (int i = 111; i <= 999; i++)
	{
		if (answerArr[i] == 0)
		{
			//cout << i << ":" << answerArr[i] << endl;
			counting++;
		}
			
	}
	
	cout << counting << endl;

	return 0;
}