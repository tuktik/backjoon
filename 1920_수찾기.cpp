#include <iostream>
#include <cstring>
#include <climits>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int compare(const void *a, const void *b){
	if((int*)a>(int*)b)
		return 1;
	else
		return 0;
}

int main()
{
	int * numArr;
	int testNum;

	numArr = new int[100000];
	
	memset(numArr,0,sizeof(int)*100000);
	
	cin>>testNum;
	
	int input;

	for(int i = 0; i<testNum; i++)
	{
		cin>>input;
		numArr[i]=input;
	}
	
	sort(numArr, numArr+testNum);
	//qsort(numArr,testNum,sizeof(int),compare);

	/*for(int i = 0; i<testNum; i++)
	{
		cout<<numArr[i]<<" ";
	}*/

	int outputNum;

	cin>>outputNum;

	int output;

	for(int i=0; i<outputNum; i++)
	{
		cin>>output;

		bool flag = 0;

		int a = 0;
		int b = testNum;
		int c = (testNum-1)/2;

		while(c<=b&& a<=c)
		{
			if(numArr[c]==output)
			{
				flag = 1;
				break;
			}
			if(c==a|| c==b)
				break;
			//cout<<numArr[c];
			if(numArr[c]>output)
			{
				b=c;
				c=(a+c)/2;
				//cout<<"a";
			}
			else if(numArr[c]<output)
			{
				a=c;
				c = (b+c)/2;
				//cout<<"b";
			}
		}

		if(flag ==1)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}

	return 0;
}