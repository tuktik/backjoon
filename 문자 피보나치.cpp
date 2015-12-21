#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;

		char string[3][10001];

		cin >> string[0][10001];
		cin >> string[1][10001];

		//sprintf_s(string[2], "%s%s", string[0], string[1]);

		//string[i % 3][index] = '\0';

		cout << string[0] << endl;
		if (num == 1)
			return 0;
		cout << string[1] << endl;
		if (num == 2)
			return 0;
		//for (int i = 2; i <= num; i++)
		//{
		//	//sprintf(string[2], "%s%s", string[0], string[1]);
		//	

		//	int index = 0;
		//	int firstLen = strlen(string[(i - 2) % 3]);
		//	int secondLen = strlen(string[(i - 2) % 3]);

		//	for (int j = 0; j < firstLen; j++)
		//	{
		//		string[i % 3][index] = string[(i - 2) % 3][j];
		//		index++;
		//	}
		//	for (int j = 0; j < secondLen; j++)
		//	{
		//		string[i % 3][index] = string[(i - 1) % 3][j];
		//		index++;
		//	}
		//	string[i % 3][index] = '\0';
		//	cout << string[i % 3] << endl;;
		//	//string[i%3][10001] = string[(i-2)%3][100001] + string[(i-1)%3][100001];
		//}

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}