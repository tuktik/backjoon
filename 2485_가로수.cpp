#include <iostream>

using namespace std;

int numArr[100000];
int GCD_Arr[100000];


int get_GCD(int a, int b)
{
	if(b==0)
		return a;
	return get_GCD(b,a%b);
}

int main()
{
	int testNum;
	int GCD=1;
	int sum=0;

	cin>>testNum;

	cin>>numArr[0];
	
	for(int i =1; i<testNum; i++)
	{
		cin>>numArr[i];	
		GCD_Arr[i]=numArr[i]-numArr[i-1];
	}

	GCD=GCD_Arr[1];
	for(int i =1; i<testNum; i++)
	{
		GCD = get_GCD(GCD,GCD_Arr[i]);
	}

	for(int i =1; i<testNum; i++)
	{
		sum+=(GCD_Arr[i]/GCD-1);
	}
	

	cout<<sum<<endl;

	return 0;
}