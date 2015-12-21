#include <iostream>

using namespace std;

char alpa[16];
int length, alpaNum;
char outputArr[4];

void sort(char *arr, int start, int end)
{
	char pivot = arr[start];
	int i = start;
	int j = end;

	while(i<=j)
	{
		while(pivot > arr[i]) { i++;}
		while(pivot < arr[j]) { j--;}

		if(i <=j)
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}

	if(start<j)
		sort(arr,start,j);
	if(i<end)
		sort(arr,i,end);
}

void dfs(int index, int count, int vowel, int consonant)
{
	if(index>=alpaNum || count>3)
		return;

	outputArr[count] = alpa[index];
	
	if(count==3 && vowel>=1 && consonant>=2)
	{
		for(int i =0; i<4; i++)
		{
			cout<<outputArr[i];
		}
		cout<<endl;
	}

	//cout<<outputArr[count]<<endl;  ||'e'||'i'||'o'||'u'
	if(alpa[index] == 'a' || alpa[index] == 'e' || alpa[index] == 'i' || alpa[index] == 'o' ||alpa[index] == 'u')
		dfs(index+1,count+1,vowel+1,consonant);
	else
		dfs(index+1,count+1,vowel,consonant+1);

	dfs(index+1,count,vowel, consonant);
}

int main()
{
	cin>>length>>alpaNum;

	for(int i =0; i<alpaNum; i++)
	{
		cin>> alpa[i];
	}

	sort(alpa,0,alpaNum-1);

	dfs(0,0,0,0);

	/*for(int i =0; i<alpaNum; i++)
	{
		cout<<alpa[i];
	}*/

	return 0;
}

