#include <iostream>
#include <stdio.h>
#include <Bits.h>
//#include <bits/stdc++.h>
#include <queue>
using namespace std;

int button_n[9] = { 3, 4, 3, 4, 5, 4, 3, 4, 3 };
int button[9][5]={{0,1,3},
{0,1,2,4},
{1,2,5},
{0,3,4,6},
{1,3,4,5,7},
{2,4,5,8},
{3,6,7},
{4,6,7,8},
{5,7,8}};

void binary(int num)
{
	for (int i = 8; i >= 0; --i)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}

int main(){
	int t;
	scanf("%d",&t);

	for(;t--;){
		int n=3;
		int arr[512];
		for(int i=0;i<512;i++)
			arr[i]=987654321;

		int sum=0;
		for(int i=0;i<n;i++){
			char arr[4]={};
			scanf(" %s",arr);
			for(int j=0;j<n;j++){
				if(arr[j]=='*'){
					sum|= (1<<(i*3+j));
				}
			}
		}
		queue<int> Q;
		Q.push(sum);
		arr[sum]=0;

		while(!Q.empty()){
			int S=Q.front();
			binary(S);
			Q.pop();
			for(int i=0;i<9;i++){
				int SUM=0;
				for(int j=0;j<button_n[i];j++){
					SUM|=(1<<button[i][j]);
				}
				int X=S^SUM;
				if(arr[X]>arr[S]+1){
					arr[X]=arr[S]+1;
					Q.push(X);
				}
			}
			//^= 
		}
		printf("%d\n",arr[0]);
	}
	return 0;
}



#if 0
#include <iostream>
#include <math.h>
using namespace std;

int visited[1030];

char goalArr[9];
char nowArr[9] = { '.', '.', '.','.', '.', '.','.', '.', '.'};

int goalVal;
int minCount =99999;

void init()
{
	for (int i = 0; i < 9; i++)
		nowArr[i] = '.';
	for (int i = 0; i < 1030; i++)
		visited[i] = 0;
}

int getNum(char arr[9])
{
	int sum = 0;
	
	for (int i = 0; i < 9; i++)
	{
		if (arr[i]== '*')
			sum += (pow(2, i));
	
	}
	return sum;
}

void reverse(int idx)
{
	if (nowArr[idx] == '*')
		nowArr[idx] = '.';
	else if (nowArr[idx] == '.')
		nowArr[idx] = '*';

}

void select(int idx)
{
	reverse(idx);

	if (idx - 3 >= 0)
	{
		reverse(idx - 3);
	}
	if (idx + 3 < 9)
	{
		reverse(idx + 3);
	}
	if ((idx - 1)/3 == idx / 3)
	{
		reverse(idx -1);
	}
	if ((idx + 1) / 3 == idx / 3)
	{
		reverse(idx + 1);
	}
}

void dfs(int now_idx, int cnt)
{
	if (now_idx > 9)
		return;
	int nowNum = getNum(nowArr);
	
	/*if (visited[nowNum] == 1)
		return;*/

	/*for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i>=3)
			cout << endl;
		cout << nowArr[i];
	}*/
	//cout << endl;
	//cout << endl;
	//cout << nowNum << endl;
	
	if (nowNum == goalVal)
	{
		
		if (minCount > cnt)
			minCount = cnt;
		return;
	}
	
	//visited[nowNum] = 1;
	
	
	select(now_idx);
	dfs(now_idx + 1, cnt + 1);
	select(now_idx);
	dfs(now_idx + 1, cnt);
	
	return;
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		init();
		minCount = 99999;
		for (int i = 0; i < 9; i++)
		{
			cin >> goalArr[i];
		}
		
		goalVal = getNum(goalArr);
		
		//cout << goalVal << endl;
		dfs(0, 0);
		cout << minCount << endl;
		
	}
	
	return 0;
}
#endif