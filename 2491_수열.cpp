#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int numArr[100001];
	int numSize;

	cin>>numSize;



	return 0;
}


//int main()
//{
//	int numArr[100001];
//	int numSize;
//	int max=1;
//	int count=1;
//	int isUpper=-1;
//
//	cin>>numSize;
//
//	for(int i =0; i<numSize; i++)
//	{
//		cin>>numArr[i];
//		if(i>0&&isUpper==-1)
//		{
//			if(numArr[i]>numArr[i-1])
//			{	
//				isUpper=1;
//			}
//			else if(numArr[i]<numArr[i-1])
//			{
//				isUpper=0;
//			}
//			count++;
//		}
//		else if(isUpper!=-1)
//		{
//			if(numArr[i]>numArr[i-1] && isUpper== 0)
//			{
//				count=1;
//				isUpper=1;
//			}
//			else if(numArr[i]<numArr[i-1] && isUpper== 1)
//			{
//				count=1;
//				isUpper=0;
//			}
//			count++;
//		}
//		if(max<count)
//			max= count;
//	}
//
//	cout<<max<<endl;
//
//	return 0;
//}