#include <iostream>
#include <algorithm>

using namespace std;

int numArr[101];
bool isVisited[101];

class stack
{
private:
	int data[1000];
	int top;
public:
	stack():top(-1){};

	int pop()
	{
		if(top==-1)
			return -1;
		else
		{
			int return_val=data[top];

			top--;
			
			return return_val;
		}
	}
	void push(int num)
	{
		top++;
		data[top]=num;
	}
	bool is_num(int num)
	{
		for( int i =0; i<top; i++)
		{
			if(data[i]==num)
				return true;
		}
		return false;
	}

	bool is_empty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}

	int stack_size()
	{
		return top+1;
	}

	void sorting_printing()
	{
		sort(data,data+top+1);

		for(int i =0; i<=top; i++)
		{
			cout<<data[i]<<endl;
		}
	}

};

bool is_loop=false;

stack public_stack;

void dfs(int index, int init_num)
{
	if(init_num==numArr[index])
	{
		is_loop=true;
	}
	if(isVisited[index]==1)
	{
		return;
	}

	isVisited[index] = 1;
	
	dfs(numArr[index],init_num);
	
	if(is_loop==true)
	{
		public_stack.push(index);
	}
	else if(is_loop==false)
	{
		isVisited[index]=0;
	}
}


int main()
{
	int testNum;
	
	cin>> testNum;

	for(int i =1; i <=testNum; i++)
	{
		cin>>numArr[i];
	}

	for(int i =1; i <=testNum; i++)
	{
		if(isVisited[i]==0)
		{
			dfs(i,i);
		}
		is_loop=false;
	}

	cout<<public_stack.stack_size()<<endl;

	public_stack.sorting_printing();

	return 0;
}