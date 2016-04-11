#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, i, m;

typedef pair<int, int> pii;
#define mp(x,y) make_pair(x,y)

vector<pii> fish;

bool compare(pii a, pii b)
{
	if (a.first < b.first)
		return 1;
	else if (a.first == b.first && a.second < b.second)
		return 1;
	else
		return 0;
}

int main()
{
	int n, i, m;

	cin >> n >> i >> m;

	int x, y;

	for (int a = 0; a < m; a++)
	{
		cin >> y;
		cin >> x;

		fish.push_back(mp(y, x));
	}
	
	sort(fish.begin(), fish.end());

	/*for (int a = 0; a < m; a++)
	{
		cout << fish[a].first << " " << fish[a].second << endl;
	}*/

	for (int a = 0; a < m; a++)
	{
		

		cout << fish[a].first << " " << fish[a].second << endl;
	}



	return 0;
}