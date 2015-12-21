#include <iostream>

using namespace std;

int inputArr[102][102];
int isVisited[102][102];
int col, row;

class point
{
public:
	int x,y, dept;
	
	point(){}
	point(int x, int y, int dept):x(x),y(y),dept(dept){}
};

class stack
{
private:
	point data[100000];
	int rear, tail;
	
public:

	stack():rear(0),tail(0){}
	
	void push(point new_data)
	{
		data[tail]=new_data;
		tail++;
		
		return;
	}
	
	point pop()
	{
		if(rear==tail)
			return point(-1,-1,-1);
		else
		{
			point temp = data[rear];

			rear++;

			return temp;
		}
	}

};

stack public_stack;
int min_count=999999;

void bfs()
{
	point temp = public_stack.pop();
	isVisited[1][1]=1;

	while(temp.x!=-1)
	{
		//cout<<temp.x<<" "<<temp.y<<endl;

		if(inputArr[temp.y+1][temp.x]==1 && isVisited[temp.y+1][temp.x]==0)
		{
			public_stack.push(point(temp.x,temp.y+1,temp.dept+1));
			isVisited[temp.y+1][temp.x]=1;
			//cout<<"1"<<endl;
		}
		if(inputArr[temp.y-1][temp.x]==1 && isVisited[temp.y-1][temp.x]==0)
		{
			public_stack.push(point(temp.x,temp.y-1,temp.dept+1));
			isVisited[temp.y-1][temp.x]=1;
			//cout<<"2"<<endl;
		}
		if(inputArr[temp.y][temp.x+1]==1 && isVisited[temp.y][temp.x+1]==0)
		{
			public_stack.push(point(temp.x+1,temp.y,temp.dept+1));
			isVisited[temp.y][temp.x+1]=1;
			//cout<<"3"<<endl;
		}
		if(inputArr[temp.y][temp.x-1]==1 && isVisited[temp.y][temp.x-1]==0)
		{
			public_stack.push(point(temp.x-1,temp.y,temp.dept+1));
			isVisited[temp.y][temp.x-1]=1;
			//cout<<"4"<<endl;
		}

		temp = public_stack.pop();
		//cout<<temp.x<<" "<<temp.y<<endl;
		if(temp.x==col && temp.y==row)
		{
			min_count<temp.dept;
			min_count=temp.dept;
		}
	}

}

int main()
{
	

	cin>>row>>col;

	char ch;
	for(int i=1; i<=row; i++)
	{
		for(int j=1; j<=col; j++)
		{
			cin>>ch;
			inputArr[i][j]=ch-48;
		}	
	}

	public_stack.push(point(1,1,1));

	bfs();

	cout<<min_count<<endl;

	return 0;
}