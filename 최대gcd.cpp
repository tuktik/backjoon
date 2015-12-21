#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	if(b==0) return a;
	else GCD(b,a%b);
}
int main()
{
	int Testnum;
	char strArr[100];
	char temp[100];
	int numArr[100];
	int numCount=0;
	int max =0;

	cin>> Testnum;
	gets(strArr);

	for(int i=0; i<Testnum; i++)
	{
		gets(strArr);

		int k =0;
		for(int j =0; strArr[j] !='\0';j++)
		{
			if(strArr[j]!=' ')
			{
				temp[k] = strArr[j];
				k++;
			}
			else
			{
				temp[k]='\0';
				numArr[numCount] = atoi(temp);
				numCount++;
				k=0;
			}
		}

		numArr[numCount] = atoi(temp);
		numCount++;

		for(int i=0; i<numCount;i++)
		{
			for(int j =i+1; j<numCount; j++)
			{
				if(max<GCD(numArr[i],numArr[j]))
				{
					max = GCD(numArr[i],numArr[j]);
				}
			}
		}

		cout<<max<<endl;
			
	}



	return 0;
}