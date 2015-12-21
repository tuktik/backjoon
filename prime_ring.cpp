#include <iostream>

using namespace std;

int primeNum[100001];

int outputArr[20];
bool isVisited[20];

int num;
	

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
}

void dfs(int count)
{
	if(num==count)
	{
		if(primeNum[outputArr[0]+outputArr[num-1]]==1)
		{
			for(int i =0; i<num; i++)
				cout<<outputArr[i]<<" ";
			cout<<endl;
		}
		return;
	}

	for(int i = 2; i<=num; i++)
	{
		if(!isVisited[i] && (primeNum[outputArr[count-1]+i]==0))
		{
			isVisited[i]=1;
			outputArr[count]=i;
			dfs(count+1);
			isVisited[i]=0;
		}
	}

}


int main()
{
	eratos();

	while(cin>>num)
	{
		outputArr[0]=1;
		isVisited[1]=1;
		dfs(1);
	}
	return 0;
}