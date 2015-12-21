#include <iostream>
#include <string>
using namespace std;

string input[20000];

int testNum;

void swap(string* a, string * b)
{
	string* temp;
	//cout<<"11"<<endl;
	temp = a;
	a=b;
	b=temp;
}


void sort(int testNum)
{
	for(int i =0; i<testNum; i++)
	{
		for(int j =i+1; j<testNum; j++)
		{
			if(input[i].length()>input[j].length())
			{
				swap(input[i], input[j]);
			} 
		}
	}
	bool flag = true;
	for(int i =0; i<testNum; i++)
	{
		for(int j =i; j<testNum-1; j++)
		{
			if(input[j].length()==input[j+1].length())
			{
				
				for(int k = 0; k<input[j].length(); k++)
				{
					if((int)input[j].c_str()[k]>=(int)input[j+1].c_str()[k])
					{
						//cout<<input[i][k]<<" "<<input[j][k]<<endl;
						flag = false;
						break;
					}
				}
				if(flag == false)
				{
					swap(input[j],input[j+1]);
					flag=true;
				}
			}
		}
	}


}

int main()
{
	cin>>testNum;

	for(int i =0; i<testNum; i++)
	{
		cin>>input[i];
	}

	sort(testNum);

	for(int i =0; i<testNum; i++)
	{
		//if(i==0)
		//{
			cout<<input[i]<<endl;
		//}
		/*else
		{
		if(input[i-1]!=input[i])
			cout<<input[i]<<input[i].length()<<endl;
		}*/
	}

	return 0;
}