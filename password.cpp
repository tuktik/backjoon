#include <iostream>

using namespace std;

char inputAlpa[16];
char outputAlpa[16];

int passNum;
int alpaNum;

void swap(char* a, char* b)
{
	char* temp;
	temp=a;
	a=b;
	b=temp;
}

void sort(char arr[16], int alpaNum)
{
	for(int i =0 ; i<alpaNum-1; i++)
	{
		for(int j =0; j<alpaNum-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

int vowelCount;
int consonantCount;

void dfs(int num, int count, int VC, int CC)
{
	//cout<<"tt"<<endl;
	cout << VC << " " << CC << endl;
	if(num==4)
	{
		
		if(VC<1 || CC<2)
			return;
		else
		{
			for(int i =0; i<passNum; i++)
			{
				cout<<outputAlpa[i];
			}
			cout<<endl;
			return;
		}
	}
	if(count==alpaNum)
		return;


	if(inputAlpa[num]=='a' || inputAlpa[num]=='i' || inputAlpa[num]=='o' || inputAlpa[num]=='u' || inputAlpa[num]=='e')
	{
		outputAlpa[num]=inputAlpa[count];
		
		//vowelCount++;
		dfs(num+1,count+1,VC+1,CC);
		//vowelCount--;
		dfs(num,count+1,VC,CC);
		
	}
	else
	{
		outputAlpa[num]=inputAlpa[count];
		
		//consonantCount++;
		dfs(num+1,count+1,VC,CC+1);
		//consonantCount--;
		dfs(num,count+1,VC,CC);
		
	}
}

int main()
{
	
	cin>> passNum >> alpaNum;

	for(int i = 0; i<alpaNum; i++)
	{
		cin>>inputAlpa[i];
	}

	sort(inputAlpa,alpaNum);

	dfs(0,0,0,0);

	return 0;
}