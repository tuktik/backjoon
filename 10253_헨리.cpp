#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);

}

int main()
{
	int testNum;

	cin >> testNum;
	
	int	mole;	//분자
	int denomi;	//분모
	
	for (int i = 0; i < testNum; i++)
	{
		cin >> mole;
		cin >> denomi;

		int sum = mole;
		int j;
		for (j = 2; sum < 2147483648; j++)
		{
			if (mole*j > denomi)
			{
				mole = mole*j - denomi;
				denomi = denomi*j;
				sum *= j;
				if (mole != 1)
				{
					j = denomi / mole ;
					//cout << j << "!!" << endl;
				}
				else
				{
					j = denomi / mole-1;
				}
			}
			else if (mole*j == denomi)
			{
				mole = mole*j - denomi;
				denomi = denomi*j;
				break;
			}
			
			int getGCD = GCD(denomi, mole);
			
			if (getGCD!= 1)
			{
				mole = mole / getGCD;
				denomi = denomi / getGCD;
				
				j = denomi / mole - 1;
			}
		}
		
		cout << j << endl;
	}
	//cout << GCD(3, 21) << endl;

	return 0;
}