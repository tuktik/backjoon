#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char chArr[51][51];
	int testNum;
	char output[51];

	cin>>testNum;

	for(int i =0; i<testNum; i++)
	{
		cin>>chArr[i];
	}

	bool is_equal = true;
	int j;
	for(j =0; j<strlen(chArr[0]);j++)
	{
		for(int i =0; i<testNum; i++)
		{
			if(chArr[0][j]!=chArr[i][j])
			{
				is_equal=false;
				break;
			}
		}
		if(is_equal==true)
		{
			output[j]=chArr[0][j];
		}
		else
		{
			output[j]='?';
		}
		is_equal=true;
	}

	output[j]='\0';

	cout<<output<<endl;
	return 0;
}