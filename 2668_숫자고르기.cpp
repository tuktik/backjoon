#include <iostream>

using namespace std;

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

};

bool isVisit[101];

stack temp_stack;
stack output_stack;

void stack_copy()
{
	while(temp_stack.is_empty()!=1)
	{
		int output_temp=temp_stack.pop();
		isVisit[output_temp]=1;
		output_stack.push(output_temp);
	}
}

void stack_out()
{
	while(temp_stack.is_empty()!=1)
	{
		temp_stack.pop();
		//isVisit[output_temp]=1;
		//output_stack.push(output_temp);
	}
}

int main()
{
	int numArr[101];

	int testNum;

	cin>>testNum;

	for(int i =1; i<=testNum; i++)
	{
		cin>>numArr[i];
	}

	for(int i =1; i<=testNum; i++)
	{
		if(isVisit[i]==0)
		{
			int init_num = i;
			temp_stack.push(numArr[i]);
			int temp = numArr[i];
			while(1)
			{
				if(temp_stack.is_num(temp))
				{
					if(init_num==temp)
					{
						stack_copy();
						cout<<temp<<"!"<<endl;
					}
					else
					{
						stack_out();
					}
					break;
				}
				temp_stack.push(temp);
				temp = numArr[temp];
			}
		}
	}

	cout<<output_stack.stack_size()<<endl;

	while(output_stack.is_empty()!=1)
	{
		cout<<output_stack.pop()<<endl;
	}

	return 0;
}