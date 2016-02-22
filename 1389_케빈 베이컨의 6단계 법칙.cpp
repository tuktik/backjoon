#include <iostream>
#include <queue>

using namespace std;

int relArr[105][105];
int visited[105];
int n;
int m;

class data
{
public:
	int now_man;
	int dept;
	
	data(int now_man, int dept) :now_man(now_man), dept(dept){}
	data(){}
};

queue<data> global_queue;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

int getBaken()
{
	int minVal = 99999;
	int minMan=0;

	for (int now_man = 1; now_man <= n; now_man++)
	{
		init();

		int sum = 0;

		global_queue.push(data(now_man, 0));
		visited[now_man] = 1;
		
		while (!global_queue.empty())
		{
			data tmp = global_queue.front();
			global_queue.pop();
			sum += tmp.dept;
			//cout << sum<<"!" << endl;
			for (int i = 1; i <= n; i++)
			{
				if (tmp.now_man != i && visited[i] == 0 && relArr[tmp.now_man][i] == 1)
				{
					global_queue.push(data(i, tmp.dept + 1));
					visited[i] = 1;
				}
			}
		}

		//cout << now_man << ": "<<sum << endl;
		if (sum!=0 && sum < minVal)
		{
			//cout << minVal << " " << minMan << endl;
			minVal = sum;
			minMan = now_man;
		}
	}

	return minMan;
}

int main()
{
	cin >> n;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;

		relArr[a][b] = 1;
		relArr[b][a] = 1;
	}

	

	//for (int i = 1; i <=n; i++)
	//{
	//	int res = getBaken(i);
	//	//cout << res << endl;
	//	if (res < minVal)
	//		minVal = res;
	//}

	cout << getBaken() << endl;


	return 0;
}