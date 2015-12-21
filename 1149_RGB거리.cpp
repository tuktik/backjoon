#include <iostream>

using namespace std;

int **rgbArr;
int **minArr;


int main()
{
	int testNum;

	cin>>testNum;

	minArr = new int*[testNum];
	rgbArr = new int*[testNum];
	for(int i =0; i<testNum; i++)
	{
		minArr[i] = new int[3];
		rgbArr[i] = new int[3];
	}

	for(int i =0; i<testNum; i++)
	{
		cin>>rgbArr[i][0];
		cin>>rgbArr[i][1];
		cin>>rgbArr[i][2];
	}
	
	minArr[0][0]=rgbArr[0][0];
	minArr[0][1]=rgbArr[0][1];
	minArr[0][2]=rgbArr[0][2];

	for(int i =1; i<testNum; i++)
	{
		minArr[i][0]= rgbArr[i][0]+(minArr[i-1][1]<minArr[i-1][2]?minArr[i-1][1]:minArr[i-1][2]);
		minArr[i][1]= rgbArr[i][1]+(minArr[i-1][0]<minArr[i-1][2]?minArr[i-1][0]:minArr[i-1][2]);
		minArr[i][2]= rgbArr[i][2]+(minArr[i-1][0]<minArr[i-1][1]?minArr[i-1][0]:minArr[i-1][1]);
	}

	
	int min = 99999999;
	for(int i =0; i<3; i++)
	{
		if(min>minArr[testNum-1][i])
			min = minArr[testNum-1][i];

		//cout<<minArr[0][i]<<endl;
	}

	cout<<min<<endl;


	return 0;
}