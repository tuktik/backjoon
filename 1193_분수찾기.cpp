#include <iostream>

using namespace std;

int main()
{
	int testNum;
	int sum=0;
	int count=0;

	cin>>testNum;
	
	while(testNum>sum)
	{
		count++;
		sum+=count;
	}
	
	if(count%2==1)
		cout<<1+(sum-testNum)<<'/'<<count-(sum-testNum)<<endl;
	else
		cout<<count-(sum-testNum)<<'/'<<1+(sum-testNum)<<endl;
		
	

	return 0;
}