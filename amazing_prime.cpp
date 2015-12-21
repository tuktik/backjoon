#include <iostream>

using namespace std;

void eratos(int* PrimeArr)
{
	PrimeArr[0]=1;
	PrimeArr[1]=1;
	for(int i = 2; i < 10000; i++)
	{
		if(PrimeArr[i]==0){
			for(int j =2; i*j<100000000; j++)
			{
				PrimeArr[i*j]=1;
			}
		}
	}
}

int pow(int num, int ex)
{
	if( ex ==0)
		return 1;
	else return 10*pow(num,ex-1);
}

int main()
{
	int* PrimeArr;

	PrimeArr = new int[100000000];

	for(int i =0; i<100000000; i++)
	{
		PrimeArr[i] =0;
	}

	eratos(PrimeArr);

	int num;

	cin>>num;

	bool is_prime =true;
	

	//cout<<pow(10,1)<<endl;
	
	for(int i = pow(10, (num-1)); i<pow(10,num);i++)
	{
		if(PrimeArr[i]==0)
		{
			
			for(int j = num-1; j>=1; j--)
			{
				
				if(PrimeArr[(i/pow(10,j))]!=0)
				{
					//cout<<i<<endl;
					is_prime = false;
					break;	
				}
			}
			//cout<<i<<endl;
			if(is_prime==true)
			{
				cout<<i<<endl;
			}
		}
		is_prime=true;
	}
	return 0;

}