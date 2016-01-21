#include <iostream>
#include <algorithm>

using namespace std;

//30, 000
long long apart[30003][2];
void quick_sorting(long long first, long long end)
{
	long long pivotPoint = apart[(first + end) / 2][0];
	long long f = first;
	long long e = end;

	while (f <= e){
		while (pivotPoint > apart[f][0]) f++;
		while (pivotPoint < apart[e][0]) e--;

		if (f <= e){
			long long temp[2];
			temp[0] = apart[f][0];
			temp[1] = apart[f][1];
			apart[f][0] = apart[e][0];
			apart[f][1] = apart[e][1];
			apart[e][0] = temp[0];
			apart[e][1] = temp[1];
			f++;
			e--;
		}
	}

	if (first < e) quick_sorting(first, e);
	if (f < end) quick_sorting(f, end);
}

int main()
{
	long long apartment_Count;
	long long max_busNum;
	long long school_pos;

	cin >> apartment_Count;
	cin >> max_busNum;
	cin >> school_pos;

	long long apart_pos;
	long long student_count;
	for (long long i = 0; i < apartment_Count; i++)
	{
		cin >> apart_pos;
		cin >> student_count;

		apart[i][0] = apart_pos;
		apart[i][1] = student_count;
	}
	apart[apartment_Count][0] = school_pos;

	//sort(apart)
	quick_sorting(0, apartment_Count);

	//for (long long i = 0; i < apartment_Count; i++)
	//{
	//  cout << apart[i][0] << " " << apart[i][1] << endl;
	//}

	long long i = 0;
	long long studentSum = 0;
	long long distance = 0;

	while (apart[i][0]<school_pos)
	{
		distance += (school_pos - apart[i][0]) * 2;
		//cout << distance <<" "<<i;
		studentSum = 0;
		while (studentSum < max_busNum)
		{
			if (studentSum + apart[i][1] < max_busNum)
			{
				studentSum += apart[i][1];
				apart[i][1] = 0;
				i++;
			}
			else if (studentSum + apart[i][1]> max_busNum)
			{
				apart[i][1] -= (max_busNum - studentSum);
				studentSum += (max_busNum - studentSum);
				//break;
			}
			else
			{
				apart[i][1] = 0;
				studentSum += (max_busNum - studentSum);
				//while (apart[i][1] != 0 )//&& apart[i][0] <= school_pos
				i++;
				//break;
			}
			if (apart[i][0] >= school_pos)
				break;
		}
		//cout << endl;
	}

	long long j = apartment_Count;
	while (apart[j][0]>school_pos)
	{
		distance += (apart[j][0] - school_pos) * 2;
		//cout << distance << " " << j;
		studentSum = 0;
		while (studentSum < max_busNum)
		{
			if (studentSum + apart[j][1] < max_busNum)
			{
				studentSum += apart[j][1];
				apart[j][1] = 0;
				j--;
			}
			else if (studentSum + apart[j][1]> max_busNum)
			{
				apart[j][1] -= (max_busNum - studentSum);
				studentSum += (max_busNum - studentSum);
				//break;
			}
			else
			{
				apart[j][1] = 0;
				studentSum += (max_busNum - studentSum);
				//while (apart[i][1] != 0 )//&& apart[i][0] <= school_pos
				j--;
				//break;
			}
			if (apart[j][0] <= school_pos)
				break;
		}
		//cout << endl;
	}

	cout << distance << endl;

	return 0;
}