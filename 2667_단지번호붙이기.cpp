#include <iostream>
#include <algorithm>

using namespace std;

int map[30][30];
bool isVisited[30][30] ={0,};

class Point
{
public:
	int x,y;

	Point(){};
	Point(int x, int y):x(x),y(y){};
};

class stack
{
private:
	Point data[10000];
	int rear,tail;

public:
	stack():rear(0),tail(0){};
	
	void push(Point new_data)
	{
		data[tail]=new_data;
		tail++;
	}
	
	Point pop()
	{
		if(rear==tail)
		{
			return Point(-1,-1);
		}
		else
		{
			Point temp = data[rear];
			
			rear++;

			return temp;
		}
	}
};

stack public_stack;

int bfs()
{
	Point temp = public_stack.pop();
	isVisited[temp.y][temp.x]=1;
	int count = 0;
	while(temp.x!=-1)
	{
		count++;
		
		if(map[temp.y][temp.x+1]==1 && isVisited[temp.y][temp.x+1]==0)
		{
			public_stack.push(Point(temp.x+1,temp.y));
			isVisited[temp.y][temp.x+1]=1;
		}
		if(map[temp.y][temp.x-1]==1 && isVisited[temp.y][temp.x-1]==0)
		{
			public_stack.push(Point(temp.x-1,temp.y));
			isVisited[temp.y][temp.x-1]=1;
		}
		if(map[temp.y+1][temp.x]==1 && isVisited[temp.y+1][temp.x]==0)
		{
			public_stack.push(Point(temp.x,temp.y+1));
			isVisited[temp.y+1][temp.x]=1;
		}
		if(map[temp.y-1][temp.x]==1 && isVisited[temp.y-1][temp.x]==0)
		{
			public_stack.push(Point(temp.x,temp.y-1));
			isVisited[temp.y-1][temp.x]=1;
		}

		temp = public_stack.pop();
	}
	return count;
}

int main()
{
	int map_size;
	int countArr[100];
	int countNum=0;
	
	cin>>map_size;

	char input;

	for(int i =1; i<=map_size; i++)
	{
		for(int j =1; j<=map_size; j++)
		{
			cin>>input;
			map[i][j]= (int)input-48;
		}
	}



	for(int i =1; i<=map_size; i++)
	{
		for(int j =1; j<=map_size; j++)
		{
			if(isVisited[i][j]==0 && map[i][j]==1)
			{
				//cout<<"!!"<<endl;
				public_stack.push(Point(j,i));
				countArr[countNum]=bfs();
				countNum++;
			}
		}
	}

	cout<<countNum<<endl;

	
		sort(countArr,countArr+countNum);
	
	for(int i=0; i<countNum;i++)
	{
		cout<<countArr[i]<<endl;
	}

	return 0;
}