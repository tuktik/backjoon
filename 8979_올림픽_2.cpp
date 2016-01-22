#include <iostream>

using namespace std;

class medal
{
public:
	int cuntNum;
	int gold;
	int silver;
	int bronze;

	bool operator < (const medal& b)
	{
		if (gold > b.gold)
			return true;
		else if (gold == b.gold && silver > b.silver)
			return true;
		else if (gold == b.gold && silver == b.silver && bronze> b.bronze)
			return true;
		else
			return false;
	}

	bool operator == (const medal& b)
	{
		
		if (gold == b.gold && silver == b.silver && bronze == b.bronze)
			return true;
		else
			return false;
	}

};

medal cuntArr[1005];

void swaping(int f, int e)
{
	medal temp = cuntArr[f];
	cuntArr[f] = cuntArr[e];
	cuntArr[e] = temp;

}
void quick(int first, int end)
{
	medal pivot = cuntArr[(first + end) / 2];
	int f = first;
	int e = end;
	
	while (f <= e)
	{
		while (cuntArr[f] < pivot) f++;
		while (pivot<cuntArr[e]) e--;

		if (f <= e)
		{
			swaping(f, e);
			
			f++;
			e--;
		}
	}

	if (first < e) quick(first, e);
	if (f < end) quick(f, end);
}

int main()
{
	int N;
	int K;
	cin >> N;
	cin >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> cuntArr[i].cuntNum ;
		cin >> cuntArr[i].gold;
		cin >> cuntArr[i].silver;
		cin >> cuntArr[i].bronze;
	}
	
	quick(1, N);

	int i;

	/*for (i = 1; i <= N; i++)
	{
		cout << cuntArr[i].cuntNum << " ";
		cout << cuntArr[i].gold << " ";
		cout << cuntArr[i].silver << " ";
		cout << cuntArr[i].bronze << endl;

	}*/

	
	for (i = 1; i <= N; i++)
	{
		if (cuntArr[i].cuntNum == K)
			break;
	}

	while (cuntArr[i] == cuntArr[i - 1])
	{
		i--;
	}

	cout << i << endl;


	return 0;
}