#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	char arrNum[50];

	cin>>arrNum;
	
	sort(arrNum, arrNum+strlen(arrNum));

	reverse(arrNum, arrNum+strlen(arrNum));

	cout<<arrNum<<endl;



	return 0;
}