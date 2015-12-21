#include <iostream>

using namespace std;

bool arr[10010][10010];

int main()
{
	int num;
	int count=0;

	cin>> num;

	for(int i =1; i<=num; i++)
	{
		for(int j =1; i*j<=num; j++)
		{
			if(arr[i][j]==0)
			{
				count++;
				arr[i][j]=1;
				arr[j][i]=1;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}

	cout<<count<<endl;


	return 0;
}