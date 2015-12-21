#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

double Sum =0;

double *numArr;

void getNum(int Num, int maxNum)
{
	for(int i = maxNum+1 ; i<=Num; i++)
	{
		numArr[i]=numArr[i-1]+log10((double)i);
	}
}


int main()
{
	numArr = new double[10000000];

	memset(numArr,0,sizeof(int)*10000000);

	int testNum;
	int InputNum;
	int maxNum =1;

	cin>>testNum;

	for(int i =0; i<testNum; i++)
	{
		cin>>InputNum;

		getNum(InputNum, maxNum);

		if(maxNum<InputNum)
			maxNum=InputNum;
		cout<<(int)numArr[InputNum]+1<<endl;

		//Sum =0;
	}


	return 0;
}