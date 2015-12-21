#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int testNum;
	int gradeSum =0;
	char temp[100];
	int scoreSum=0;

	cin>>testNum;
	char tempScore[20];
	int tempGrade;
	for(int i =0; i<testNum; i++)
	{
		cin>>temp;

		cin>>tempGrade>>tempScore;

		

		gradeSum+=tempGrade;

		switch(tempScore[0])
		{
		case 'A':
			scoreSum+=4000*tempGrade;	
			break;
		case 'B':
			scoreSum+=3000*tempGrade;
			break;
		case 'C':
			scoreSum+=2000*tempGrade;
			break;
		case 'D':
			scoreSum+=1000*tempGrade;
			break;
		case 'F':
			break;
		default:
			break;
		}
		
		if(tempScore[1]=='+'&& tempScore[0]!='F')
		{
			scoreSum+=(300*tempGrade);
		}
		else if(tempScore[1]=='-'&& tempScore[0]!='F')
		{
			scoreSum-=(300*tempGrade);
		}
		else if(tempScore[0]!='F')
		{
			
		}
	
		//cout<<scoreSum<<endl;
	}



	//cout<<((double)scoreSum)/(gradeSum*10)<<endl;

	//cout<<tempScore<<endl;

	
	int tempOutput;

	tempOutput =scoreSum/gradeSum;

	if(tempOutput%10>=5)
		tempOutput+=5;

	printf("%.2lf\n",(double)tempOutput/1000);


	return 0;
}