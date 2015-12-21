#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int acidArr[100000];
int alcaliArr[100000];
int input[100000];

int compare(int a, int b)
{
	if(a>b)
		return 1;
	else
		return 0;

}

int main()
{
	int testNum;
	int acidsizeNum=0;
	int alcalisizeNum=0;
	int outputAcid;
	int outputAlcali;
	int min=200000000;

	cin>> testNum;
	
	for(int i =0; i<testNum; i++)
	{
		cin>>input[i];
	
		if(input[i]<0)
		{
			alcaliArr[alcalisizeNum++] = input[i];
		}
		else
		{
			acidArr[acidsizeNum++]=input[i];
		}
	}
	
	sort(acidArr,acidArr+acidsizeNum);
	sort(alcaliArr,alcaliArr+alcalisizeNum,compare);
	
	

	/*for(int i=0; i<acidsizeNum; i++)
		cout<<acidArr[i]<<" ";

	for(int i=0; i<alcalisizeNum; i++)
		cout<<alcaliArr[i]<<" ";
*/
	int acid=0;
	int alcali=0;

	while(acid<acidsizeNum && alcali<alcalisizeNum)
	{
		if(min>abs(acidArr[acid]+alcaliArr[alcali]))
		{
			min=abs(acidArr[acid]+alcaliArr[alcali]);
			outputAcid=acid;
			outputAlcali=alcali;
			//cout<<min<<"!!"<<endl;
		}
		if(acidArr[acid]+alcaliArr[alcali]>0 && alcali<alcalisizeNum)
		{
			alcali++;
		}
		else
		{
			acid++;
		}
	}

	if(alcalisizeNum==0 &&min>abs(acidArr[0]+acidArr[1]))
	{
		cout<<acidArr[0]<<" "<<acidArr[1]<<endl;

		return 0;
	}
	if(acidsizeNum==0 && min>abs(alcaliArr[0]+alcaliArr[1]))
	{
		cout<<alcaliArr[1]<<" "<<alcaliArr[0]<<endl;

		return 0;
	}

	cout<<alcaliArr[outputAlcali]<<" "<<acidArr[outputAcid]<<endl;

	return 0;
}