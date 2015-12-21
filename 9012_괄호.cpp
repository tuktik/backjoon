#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int testNum;
	int count=0;
	char ch[100];

	cin>> testNum;

	for(int i =0; i<testNum; i++)
	{
		cin>>ch;

		for(int i =0; i<strlen(ch);i++)
		{
			if(ch[i]=='(')
				count++;
			else if(ch[i]==')')
				count--;
			
			if(count<0)
				break;
		}
		
		if(count==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
		count=0;
	}
	return 0;
}