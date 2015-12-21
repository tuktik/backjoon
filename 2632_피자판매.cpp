#include <iostream>
using namespace std;

int aArr[1000];
int bArr[1000];

int main()
{
	int pizzaSize;
	int a, b;
	int count=0;

	cin >> pizzaSize;
	cin >> a >> b;
	
	for (int i = 0; i < a; i++)
	{
		cin >> aArr[i];
	}

	for (int i = 0; i < b; i++)
	{
		cin >> bArr[i];
	}

	//int sumA = 0; 
	//int sumB = 0;
	
	for (int startA = 0; startA < a; startA++)
	{
		for (int aNumer = 0, sumA=0; sumA < pizzaSize; aNumer++)
		{
			sumA += aArr[(startA + aNumer) % a];
			
			if (sumA > pizzaSize)
				break;
			else if (sumA == pizzaSize)
			{
				count++;
				break;
			}
			//B
			for (int startB = 0; startB < b; startB++)
			{
				for (int bNumer = 0, sumB = 0; sumB < pizzaSize; bNumer++)
				{
					sumB += bArr[(startB + bNumer) % b];

					if (sumA+sumB > pizzaSize)
						break;
					else if ( (sumA+sumB) == pizzaSize)
					{
						count++;
						break;
					}
				}
			}
		}	
	}

	cout << count << endl;

	return 0;
}