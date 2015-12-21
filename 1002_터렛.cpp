#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

double get_width(double x1, double y1, double x2, double y2)
{

	//cout<<pow((double)(x2-x1),2)<< " "<< pow((double)(y2-y1),2)<<endl;

	//cout<<sqrt(pow((double)(x2-x1),2) + pow((double)(y2-y1),2))<<endl;
	return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int main()
{
	int testNum;

	cin>>testNum;

	double x1,y1;
	double x2,y2;
	double r1,r2;

	for(int i =0; i<testNum; i++)
	{
		cin>>x1 >> y1 >> r1>>x2>>y2>>r2;

		if( x1==x2&& y1==y2 && r1==r2)
		{
			cout<<"-1"<<endl;
		}
		else if(r1+r2==get_width(x1,y1,x2,y2) || get_width(x1,y1,x2,y2)== abs(r1-r2))
		{
			cout<<"1"<<endl;
		}
		else if(r1+r2<get_width(x1,y1,x2,y2) || get_width(x1,y1,x2,y2)<abs(r1-r2) )
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout<<"2"<<endl;
		}

	}

	return 0;
}