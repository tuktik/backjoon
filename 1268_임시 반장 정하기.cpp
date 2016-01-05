#include <iostream>

using namespace std;

int studentArr[1005][6];
int relationArr[1005][1005];
int countArr[1005];
int main()
{
	int studentCount;

	cin >> studentCount;

	for (int i = 1; i <= studentCount; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> studentArr[i][j];
		}
	}


	for (int grade = 1; grade <= 5; grade++)
	{
		for (int i = 1; i <= studentCount; i++)
		{
			for (int j = i + 1; j <= studentCount; j++)
			{
				if (studentArr[i][grade] == studentArr[j][grade])
				{
					//cout << "grade:" << grade << " " << i << " " << j << endl;
					relationArr[i][j] = 1;
					relationArr[j][i] = 1;
				}
			}
		}
	}

	int max = 0;
	int maxIndex = 1;
	for (int i = 1; i <= studentCount; i++)
	{
		for (int j = 1; j <= studentCount; j++)
		{
			if (relationArr[i][j] == 1 && i != j)
				countArr[i]++;
		}
		//cout <<i<<" "<< countArr[i] << endl;
		if (countArr[i] > max)
		{
			maxIndex = i;
			max = countArr[i];
		}
	}

	cout << maxIndex << endl;


	return 0;
}

//cout << maxIndex << endl;


//for (int grade = 1; grade <= 5; grade++)
//{
//	for (int classes = 1; classes <= 9; classes++)
//	{
//		int firststuNum = 0;
//		bool isTwo = false;
//		for (int studentNum = 1; studentNum <= studentCount; studentNum++)
//		{
//			if (studentArr[studentNum][grade] == classes)
//			{
//				//cout << studentNum<<" ";
//				if (firststuNum == 0)
//				{
//					firststuNum = studentNum;
//				}
//				else
//				{
//					isTwo = true;
//					countArr[studentNum]++;
//				
//					//cout << k<<" "<<i<< endl;
//				}
//			}
//		}
//		//cout << endl;
//		if (isTwo==true)
//			countArr[firststuNum]++;
//	}
//}

//int maxStudent = 0;
//int maxCount = 0;
//
//for (int i = 1; i <= studentCount; i++)
//{
//	//cout << countArr[i] << endl;
//	if (countArr[i] > maxCount)
//	{
//		maxCount = countArr[i];
//		maxStudent = i;
//	}
//}