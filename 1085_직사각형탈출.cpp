#include <iostream>

using namespace std;

int main()
{
	int x,y, w, h;
	int min =99999;

	cin>> x >> y>> w>>h;

	if(x<w-x)
		min = x;
	else
		min= w-x;

	if(y<h-y && y<min)
		min =y;
	else if(y>h-y && h-y<min)
		min = h-y;

	cout<<min<<endl;


	return 0;
}