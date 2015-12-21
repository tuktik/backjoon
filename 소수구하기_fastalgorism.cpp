#include <iostream>
#include <math.h>
using namespace std;;

int primeNum[100001];

void eratos()
{
	primeNum[0] =1;
	primeNum[1] =1;
	for(int i =2; i <100001; i++)
	{
		if(primeNum[i]==0)
		{
			for(int j = 2 ; i*j<100001; j++)
				primeNum[i*j]=1;
		}
	}
	primeNum[1]=0;
}

bool is_Prime(int a)
{
	for(int i=2; i< sqrt((double)a); i++)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char chrArr[100];

	cin>>chrArr;

	int sum =0;

	eratos();

	//cout<<(int)'a'<<endl;
	//cout<<(int)'A'<<endl;
	for(int i =0; i<strlen(chrArr); i++)
	{
		if(chrArr[i]>=97)
			sum+= (chrArr[i] - 96);
		else
			sum+=(chrArr[i]-64);
	}

	//if(primeNum[sum]==0)
	if(is_Prime(sum))	
		cout<<"It is a prime word."<<endl;
	else
		cout<<"It is not a prime word."<<endl;

	return 0;
}