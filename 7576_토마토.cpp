#include <iostream>

using namespace std;

int box[1002][1002];
int col,row;

class Point
{
public:
	int x,y;
	int dept;
	
	Point(){}
	Point(int x, int y):x(x),y(y){}
	Point(int x, int y, int dept):x(x),y(y),dept(dept){}
};

class queue
{
private:
	Point point[1000000];
	int rear,tail;

public:
	queue():rear(0),tail(0){}

	void push(Point data)
	{
		point[tail%1000000] = data;
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
			Point temp = point[rear%1000000];

			rear++;

			return temp;
		}
	}

	bool is_empty()
	{
		if(rear==tail)
		{
			return true;
		}
		else
			return false;
	}

};

queue public_queue;
int count = 0;
void bfs()
{
	Point temp = public_queue.pop();
	while(temp.x!=-1)
	{
		

		if(box[temp.y][temp.x-1]==0 )
		{
			box[temp.y][temp.x-1]=1;
			public_queue.push(Point(temp.x-1,temp.y,temp.dept+1));
		}
		if( box[temp.y][temp.x+1]==0 )
		{
			box[temp.y][temp.x+1]=1;
			public_queue.push(Point(temp.x+1,temp.y,temp.dept+1));
		}
		if( box[temp.y-1][temp.x]==0 )
		{
			box[temp.y-1][temp.x]=1;
			public_queue.push(Point(temp.x,temp.y-1,temp.dept+1));
		}
		if( box[temp.y+1][temp.x]==0 )
		{
			box[temp.y+1][temp.x]=1;
			public_queue.push(Point(temp.x,temp.y+1,temp.dept+1));
		}
		
		//if(temp.dept>count)
		count = temp.dept;

		temp = public_queue.pop();
	}
}

int main()
{
	cin>> col >>row;

	//bool unripen = false;
	
	for(int i =0; i<1002; i++)
	{
		for(int j =0; j<1002; j++)
		{
			box[i][j]=-1;
			
		}
	}


	for(int i =1; i<=row; i++)
	{
		for(int j =1; j<=col; j++)
		{
			cin>>box[i][j];
			if(box[i][j]==1)
				public_queue.push(Point(j,i,0));
		}
	}

	

		bfs();

		bool flag = true;

		for(int i =1; i<=row; i++)
		{
			for(int j =1; j<=col; j++)
			{
				if(box[i][j]==0)
				{
					flag = false;
					break;
				}
			}
		}
	
		if(flag)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
		//}
	
	return 0;
}