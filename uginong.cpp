#include <iostream>

using namespace std;

int arr[51][51];
int visited[51][51];
int M, N, K;

class node
{
public:
	int x,y;
	node(){}
	node(int x, int y):x(x),y(y){}
};

class queue
{
private:
	node data[10000];
	int front, tail;
public:
	queue():front(0), tail(-1){}

	void push(node new_data)
	{
		tail++;
		data[tail%10000] = new_data;
	}
	node pop()
	{
		if(tail<front)
		{
			return node(-1,-1);
		}
		node temp_node = data[front++%10000];

		return temp_node;
	}
	
	bool is_empty()
	{
		if(tail<front)
			return 1;
		else
			return 0;
	}
};


queue public_queue;

void bfs()
{
	int x = -1,y = -1;

	while(!public_queue.is_empty())
	{
		node temp = public_queue.pop();
		x = temp.x;
		y = temp.y;
		
		if(arr[y][x] != 1 || visited[y][x]==1 || x<0 || y<0 || x>=M || y>=N)
		{}
		else
		{
		visited[y][x] =1;
		//cout<<"visited"<<y<<x;
		if( arr[y+1][x] == 1 && visited[y+1][x]==0)
			public_queue.push(node(x, y+1));
		if( arr[y-1][x] == 1 && visited[y-1][x]==0)
			public_queue.push(node(x, y-1));
		if( arr[y][x+1] == 1 && visited[y][x+1]==0)
			public_queue.push(node(x+1, y));
		if( arr[y][x-1] == 1 && visited[y][x-1]==0)
			public_queue.push(node(x-1, y));	
		}
	}
}

void init()
{
	for(int i =0; i<=50; i++)
	{
		for(int j =0; j<=50; j++)
		{
			arr[i][j]=0;
			visited[i][j]=0;
		}
	}
}



int main()
{
	int TestNum;
	

	cin>>TestNum;

	for(int a =0; a<TestNum; a++)
	{
		init();

		cin>> M >> N >> K;

		int x, y;

		for(int i =0; i<K; i++)
		{
			cin>> x >> y;
		
			arr[y][x] =1;		
		}

		int count =0;

		for(int j =0 ; j< N; j++)
		{
			for(int i =0 ; i<M; i++)
			{
				if(arr[j][i]==1 && visited[j][i] == 0)
				{
					public_queue.push(node(i,j));
					bfs();
					//cout<< i <<j<<"!!";
					count++;

				}
			}
		}

		cout<<count<<endl;
	}
	return 0;
}