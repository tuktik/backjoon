#include <iostream>
#include <queue>

using namespace std;

class pt
{
public:
	int position;
	int time;

	pt() {}
	pt(int position, int time) :position(position), time(time) {}
};


queue<pt> global_queue;
int n, k;
int visited[100005];



int bfs()
{
	global_queue.push(pt(n, 0));
	visited[n] = 1;
	while (1)
	{
		pt nowPt = global_queue.front();
		global_queue.pop();

		if (nowPt.position == k)
			return nowPt.time;

		if (nowPt.position + 1 <= 100000 && visited[nowPt.position + 1] != 1)
		{
			global_queue.push(pt(nowPt.position + 1, nowPt.time + 1));
			visited[nowPt.position + 1] = 1;
		}
		if (nowPt.position - 1 >= 0 && visited[nowPt.position - 1] != 1)
		{
			global_queue.push(pt(nowPt.position - 1, nowPt.time + 1));
			visited[nowPt.position - 1] = 1;
		}
		if (nowPt.position *2 <= 100000 && visited[nowPt.position *2] != 1)
		{
			global_queue.push(pt(nowPt.position * 2, nowPt.time + 1));
			visited[nowPt.position * 2] = 1;

		}
	}	
		

}

int main()
{
	
	cin >> n >> k;

	cout << bfs()<<endl;



	return 0;
}