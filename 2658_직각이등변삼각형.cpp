#include <iostream>

using namespace std;

int inputArr[12][12];
int visited[12][12];

typedef struct 
{
	int x;
	int y;
}point;

point pntArr[10];
int pntCount = 0;

int Dx[4] = { 0, 1, 0, -1 };
int Dy[4] = { 1, 0, -1, 0 };

void searchVertex(int x, int y)
{
	if (visited[y][x] == 1)
		return;
	if (inputArr[y][x] == 0)
		return;


	if (cnt >= 5)
	{
		pntArr[pntCount].x = x;
		pntArr[pntCount].y = y;
		pntCount++;
		//cout << "!" << endl;
	}


}

void search(int x, int y)
{
	if (visited[y][x] == 1)
		return;
	if (inputArr[y][x] == 0)
		return;
	
	int cnt = 0;
	if (inputArr[y-1][x] == 0)
		cnt++;
	if (inputArr[y+1][x] == 0)
		cnt++;
	if (inputArr[y][x-1] == 0)
		cnt++;
	if (inputArr[y][x+1] == 0)
		cnt++;
	if (inputArr[y - 1][x-1] == 0)
		cnt++;
	if (inputArr[y + 1][x+1] == 0)
		cnt++;
	if (inputArr[y+1][x - 1] == 0)
		cnt++;
	if (inputArr[y-1][x + 1] == 0)
		cnt++;

	if (cnt >=5)
	{
		pntArr[pntCount].x = x;
		pntArr[pntCount].y = y;
		pntCount++;
		//cout << "!" << endl;
	}
	visited[y][x] = 1;
	

	for (int i = 0; i < 4; i++)
	{
		search(x + Dx[i], y + Dy[i]);
	}
}

int getLength(point p1, point p2)
{
	
	return (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)* (p2.y - p1.y);
}

void printpnt()
{
	cout << pntArr[0].y << " " << pntArr[0].x << endl;
	cout << pntArr[1].y << " " << pntArr[1].x << endl;
	cout << pntArr[2].y << " " << pntArr[2].x << endl;
}

bool compare(point p1, point p2)
{
	if (p1.y > p2.y)
		return true;
	else if (p1.y == p2.y)
	{
		if (p1.x > p2.x)
		{
			return true;
		}
		else 
			return false;
	}
	else
		return false;

}

void sort()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = i+1; j <=2; j++)
		{
			if (compare(pntArr[i], pntArr[j]))
			{
				point temp;
				temp.x = pntArr[i].x;
				temp.y = pntArr[i].y;

				pntArr[i].x = pntArr[j].x;
				pntArr[i].y = pntArr[j].y;

				pntArr[j].x = temp.x;
				pntArr[j].y = temp.y;
			}

		}
	}
}

int main()
{
	char temp;
	for (int i = 1; i <=10; i++)
	{
		for (int j = 1; j <=10; j++)
		{
			cin >> temp;
			inputArr[i][j] = temp - '0';
		}
	}

	for (int i = 1; i <=10; i++)
	{
		for (int j = 1; j <=10; j++)
		{
			if (visited[i][j] == 0 && inputArr[i][j]==1)
				search(j, i);
		}
	}
	
	if (pntCount > 3)
	{
		cout << "0" << endl;	
	}
	//cout << pntCount << endl;
	//printpnt();


	sort();

	int lengthArr[3];

	lengthArr[0] = getLength(pntArr[0], pntArr[1]);
	lengthArr[1] = getLength(pntArr[1], pntArr[2]);
	lengthArr[2] = getLength(pntArr[2], pntArr[0]);
	
	//cout << lengthArr[0] << " " << lengthArr[1] << " " << lengthArr[2] << endl;

	if (lengthArr[0] == lengthArr[1])
	{
		if (lengthArr[0] + lengthArr[1] == lengthArr[2] )
		{
			printpnt();
			return 0;
		}
	}
	if (lengthArr[1] == lengthArr[2])
	{
		if (lengthArr[1] + lengthArr[2] == lengthArr[0])
		{
			printpnt();
			return 0;
		}
	}
	if (lengthArr[2] == lengthArr[0])
	{
		if (lengthArr[0] + lengthArr[2]  == lengthArr[1] )
		{
			printpnt();
			return 0;
		}
	}

	cout << "0" << endl;
	return 0;
}