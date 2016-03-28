#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
int visited[1000001];

class pt {

public:
	int now_floor;
	int btnCount;

	pt() {}
	pt(int now_floor, int btnCount) :now_floor(now_floor), btnCount(btnCount) {}
};

queue<pt> global_queue;

int bfs()
{
	global_queue.push(pt(s, 0));
	visited[s] = 1;

	while (!global_queue.empty())
	{
		pt nowPt = global_queue.front();
		global_queue.pop();

		if (nowPt.now_floor == g)
			return nowPt.btnCount;
		if (nowPt.now_floor + u <= 1000000 && visited[nowPt.now_floor + u] == 0)
		{
			global_queue.push(pt(nowPt.now_floor + u, nowPt.btnCount + 1));
			visited[nowPt.now_floor + u] = 1;
		}
		if (nowPt.now_floor - d >=1 && visited[nowPt.now_floor - d] == 0)
		{
			global_queue.push(pt(nowPt.now_floor - d, nowPt.btnCount + 1));
			visited[nowPt.now_floor - d] = 1;
		}
	}

	return -1;
}

int main()
{
	

	cin >> f >> s >> g >> u >> d;


	int res = bfs();

	if (res == -1)
		cout << "use the stairs" << endl;
	else
		cout << res << endl;
	return 0;
}