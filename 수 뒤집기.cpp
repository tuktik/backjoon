#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int testNum;
	char input[100];
	char sum[100];

	cin>>testNum;

	for(int i =0; i<testNum; i++)
	{
		cin>>input;

		//'1'==49
		int carry =0;
		int j;
		for(j =0; j<strlen(input); j++)
		{

			sum[j] = input[j] + input[strlen(input)-j-1] -48 -48 + carry;
			if(sum[j]>=10)
			{
				sum[j]-=10;
				carry=1;
			}
			else
			{
				carry=0;
			}
		}
		//cout<<j<<endl;
		//cout<<carry<<endl;
		if(carry==1)
			sum[j]=1;
		bool flag = true;

		int temp = strlen(input)-(1-carry);			//

		for(int j=temp; j>=0; j--)
		{
			//cout<<"!!"<<endl;
			if(sum[j]!=sum[strlen(input)-j-(1-carry)])
			{
				flag=false;
				//break;
			}
			//cout<<(int)sum[j];
		}
		//cout<<endl;
		if(flag==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}


	return 0;
}