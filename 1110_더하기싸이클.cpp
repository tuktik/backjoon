#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int now_num=0;

	int sum=0;
	int ten_digit=0;
	int units_digit=0;
	int count = 0;

	//ten_digit = n / 10;
	//units_digit = n % 10;
	now_num = n;
	do
	{
		ten_digit = now_num / 10;
		units_digit = now_num % 10;

		sum = (ten_digit + units_digit) % 10;
		now_num = units_digit * 10 + sum;
		count++;

	} while (now_num != n);

/*	while (now_num != n)
	{
		sum = (ten_digit + units_digit)%10;
		//sum = 8;
		//units 6
		now_num = units_digit * 10 + sum;
	
		count++;
		//cout << now_num << endl;
		//cout << count << endl;

		ten_digit = now_num / 10;
		units_digit = now_num % 10;
	}
	*/
	cout << count << endl;

	return 0;
}