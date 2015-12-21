#include <iostream>

using namespace std;

int fiboArr[50][2];

int main()
{
	int testNum;
	int inputNum;
	cin>>testNum;

	fiboArr[0][0]=1;
	fiboArr[1][1]=1;
	
	for(int i =0; i<testNum; i++)
	{
		cin>>inputNum;

		for(int i =2; i<=inputNum; i++)
		{
			fiboArr[i][0] =fiboArr[i-2][0]+fiboArr[i-1][0];
			fiboArr[i][1] =fiboArr[i-2][1]+fiboArr[i-1][1];
		}
	
	cout<<fiboArr[inputNum][0]<<" "<<fiboArr[inputNum][1]<<endl;
	}

	
	

	return 0;
}