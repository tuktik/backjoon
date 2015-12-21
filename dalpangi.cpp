#include <iostream>

using namespace std;

int main()
{
	int a, b, v;
	
	int day=1;

	cin>> a >> b >> v;

	while(v> (a-b)*(day-1) +a)
	{
		day++;
	}
	
	cout<<day<<endl;

	return 0;
}