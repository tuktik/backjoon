#include <iostream>

using namespace std;

int inputArr[10];

//void quick_sort(int first, int end)
//{
//	int f = first;
//	int e = end;
//	int pivot = (first + end) / 2;
//	while (f <= e)
//	{
//		while (inputArr[f] < inputArr[pivot]) f++;
//		while (inputArr[e] > inputArr[pivot]) e--;
//	
//		if (f <= e)
//		{
//			int tmp = inputArr[f];
//			inputArr[f] = inputArr[e];
//			inputArr[e] = tmp;
//			f++;
//			e--;
//			cout << "!!" << endl;
//		}
//	}
//
//	if (first < e) quick_sort(first, e);
//	if (f < end) quick_sort(f, end);
//}

void quick_sort(int first, int end){
	int pivotPoint = inputArr[(first + end) / 2];

	int f = first;
	int e = end;

	while (f <= e){
		while (pivotPoint > inputArr[f]) f++;
		while (pivotPoint < inputArr[e]) e--;

		if (f <= e){
			int tmp = inputArr[f];
			inputArr[f] = inputArr[e];
			inputArr[e] = tmp;

			f++;
			e--;
		}
	}

	if (first < e) quick_sort(first, e);
	if (f < end) quick_sort(f, end);
}


int main()
{
	int testNum;
	int num;
	int sum = 0;
	int arrSize = 0;

	cin >> testNum;
	
	for (int i = 0; i <testNum; i++)
	{
		cin >> inputArr[i];
		
	}

	quick_sort(0, testNum-1);

	//cout << arrSize << endl;
	
	/*for (int i = 1; i <=testNum; i++)
	{
		cout << inputArr[i] << endl;
	}*/

	int i;
	for (i = 0; i <testNum / 2; i++)
	{
		if (i != (testNum+1)/ 2 -1)
		{
			sum += inputArr[testNum - i - 1];
			//cout << inputArr[testNum - i-1]<<endl;
		}
		sum += inputArr[testNum - i - 1];
		//cout << inputArr[testNum - i - 1] << endl;
		if (i != (testNum + 1) / 2 - 1)
		{
			sum -= inputArr[i];
			//cout <<"-"<< inputArr[i] << endl;
		}
		sum -= inputArr[i];
		//cout << "-" << inputArr[i] << endl;

	}

	//cout << sum << endl;

	if (testNum % 2 == 1)
	{
		sum += inputArr[i-1];
		//cout << inputArr[i-1] << endl;
		sum -= inputArr[i];
		//cout << inputArr[i] << endl;
	}

	cout << sum << endl;

	return 0;
}