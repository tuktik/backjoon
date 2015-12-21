#include <iostream>

using namespace std;

int numArr[46];

int fiv(int num)
{
	for(int i=2; i<=num; i++)
	{
		numArr[i]=numArr[i-2]+numArr[i-1];
	}
	return numArr[num];
}

int main()
{
	numArr[0]=0;
	numArr[1]=1;

	int fiv_num;

	cin>>fiv_num;

	cout<<fiv(fiv_num)<<endl;

	return 0;

}