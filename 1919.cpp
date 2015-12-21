#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
	char* temp;
	temp =a;
	a=b;
	b=temp;

}

void sort(char *Arr)
{
	for(int i=0; i<strlen(Arr); i++)
	{
		for(int j =i+1; j<strlen(Arr);j++)
		{
			if(Arr[i]>Arr[j])
				swap(Arr[i],Arr[j]);
		}
	}
}

int count = 0;
int compare(char* str1, char* str2)
{
	int str1Cnt=0, str2Cnt=0;
	while(str1Cnt<strlen(str1) || str2Cnt<strlen(str2) )
	{
		if(str1[str1Cnt]>str2[str2Cnt])
		{
			str1Cnt++;
			count++;
		}
		else if (str1[str1Cnt]<str2[str2Cnt])
		{
			str2Cnt++;
			count++;
		}
		else
		{
			str1Cnt++;
			str2Cnt++;
			count++;
		}
	}

	return strlen(str1)+strlen(str2) - count*2;
}

int main()
{

	char string1[100];
	char string2[100];

	cin>>string1>>string2;

	sort(string1);
	sort(string2);

	

	cout<<-compare(string1, string2)<<endl;

	return 0;
}