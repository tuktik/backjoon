#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class node
{
public:
	string data;
	node* prev;
	node* next;
}

class list
{
private:
	node * header;

public:
	push_back(){};

	pop_bakc(){};

}

int main()
{
	int num;
	string data[20000];

	cin>>num;

	for(int i =0; i<num; i++)
	{
		cin>>data[i];
	}	

	//sort(data,data+num,sizesort);
	//sort(data,data+num,dicsort);
	
	for(int i =0; i<num; i++)
	{
		for(int j = i+1; j<num; j++)
		{
			string temp;

			if(data[i].size()>data[j].size())
			{
				temp = data[i];
				data[i]=data[j];
				data[j]=temp;
			}
			else if(data[i].size()==data[j].size() && data[i]>data[j])
			{
				temp = data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}



	for(int i =0; i<num; i++)
	{
		if(i!=0 && data[i]==data[i-1])
			continue;
		
		cout<<data[i]<<endl;
	}

	return 0;
}