#include <stdio.h>

int n;
int arr[10005];

int main()
{
	scanf("%d",&n);

	int input;

	for (int i = 0; i < n; i++)
	{
		//cin >> arr[i];
		scanf("%d", &input);
		arr[input]++;
	}
	
	//quick(0, n - 1);

	for (int i = 0; i < 10001; i++)
	{
		//cout << arr[i] << endl;
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}


	return 0;
}

//void quick(int first, int end)
//{
//	int pivot = arr[(first + end) / 2];
//	int f = first;
//	int e = end;
//
//	while (f <= e)
//	{
//		while (arr[f] < pivot) f++;
//		while (pivot < arr[e]) e--;
//
//		if (f <= e)
//		{
//			int tmp = arr[f];
//			arr[f] = arr[e];
//			arr[e] = tmp;
//
//			f++;
//			e--;
//		}
//	}
//
//	if (first < e) quick(first, e);
//	if (f < end) quick(f, end);
//}