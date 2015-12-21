#include <iostream>

using namespace std;

int arrA[100] = {5,4,3,2,1};
int arrB[100];

void swap(int* a, int* b)
{
	int* temp;
	temp=a;
	a=b;
	b=temp;
}

void sort(int arr[100], int inputNum)
{
	for(int i =0 ; i<inputNum-1; i++)
	{
		for(int j =0; j<inputNum-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

void reverse_sort(int arr[100], int inputNum)
{
	for(int i =0 ; i<inputNum-1; i++)
	{
		for(int j =0; j<inputNum-i-1; j++)
		{
			if(arr[j]<arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}


int main()
{
	int inputNum;
	cin>>inputNum;

	for(int i =0; i<inputNum; i++)
	{
		cin>>arrA[i];
	}

	sort(arrA,inputNum);

	for(int i =0; i<inputNum; i++)
	{
		cin>>arrB[i];
	}
	reverse_sort(arrB,inputNum);

	int sum =0;

	for(int i =0; i<inputNum; i++)
	{
		sum +=arrA[i]*arrB[i];
	}

	cout<<sum<<endl;


	return 0;
}

