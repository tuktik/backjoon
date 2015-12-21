#include <iostream>

using namespace std;

int arr[51][51];
int Visited[51][51];

class Point
{
public:
	int x,y;
	Point(int x,int y):x(x),y(y){}
};

class Stack
{
	Point Data[500];
	int end;
	
public:

	Stack():end(-1){}
	void push(Point data)
	{
		end++;
		Data[end]=data;
	}
	
	Point pop()
	{
		if(end!=-1)
		{
			return Data[end--];
		}
		else
		{
			return Point(-1,-1);
		}
	}
};

Stack global_stack;

int getIsland(int w, int h)
{
	for(int i=0; i < w; i++)
		{
			for(int j=0; j<h; j++)
			{
				if(Visited[i][j]==0 && arr[i][j]==1)
				{
					global_stack.push(Point(i,j));
				}
			}
		}
}

int main()
{
	int w,h;
	
	cin>>w;
	cin>>h;

	while(w!=0 && h!=0)
	{
		for(int i=0; i < w; i++)
		{
			for(int j=0; j<h; j++)
			{
				cin>>arr[i][j];
			}
		}



		cin>> w;
		cin>> h;
		
	}

	return 0;
}