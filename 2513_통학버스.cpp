#include <iostream>
#include <algorithm>

using namespace std;

//30, 000
int apart[30000][2];

void quick_sorting(int first, int end)
{
	int pivot = (first + end) / 2;
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (apart[f][0] < apart[pivot][0])f++;
		while (apart[pivot][0] < apart[e][0])e--;

		if (f <= e)
		{
			int temp[2];
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
	if (f<end) quick_sorting(f, end);
}

bool compare(const int &i, const int &j){
	return i>j;
}

int main()
{
	int apartment_Count;
	int max_busNum;
	int school_pos;

	cin >> apartment_Count;
	cin >> max_busNum;
	cin >> school_pos;

	int apart_pos;
	int student_count;
	for (int i = 0; i < apartment_Count; i++)
	{
		cin >> apart_pos;
		cin >> student_count;

		apart[i][0] = apart_pos;
		apart[i][1] = student_count;
	}
	
	//sort(apart)
	quick_sorting(0, apartment_Count - 1);

	//for (int i = 0; i < apartment_Count; i++)
	//{
	//	cout << apart[i][0] << " " << apart[i][1] << endl;
	//}

	int i = 0;
	int studentSum = 0;
	int distance = 0;

	while (apart[i][0]<school_pos)
	{
		distance += ((school_pos - apart[i][0]) * 2);
		//cout << distance << endl;
		studentSum = 0;
		while (studentSum <= max_busNum)
		{
			
			if (apart[i][1] - (max_busNum - studentSum) <= 0)
			{
				studentSum += apart[i][1];
				i++;
			}
			else
			{
				apart[i][1] -= (max_busNum - studentSum);
				//studentSum = 0;
				studentSum = max_busNum;
				//this pos, coding pleas~~~
			}
			if (i >= school_pos)
				break;
		}
		if (i >= school_pos)
			break;
	}
	int j = apartment_Count - 1;
	while (apart[j][0]>school_pos)
	{
		distance += ((apart[j][0]-school_pos) * 2);
		//cout << distance << endl;
		studentSum = 0;
		while (studentSum <= max_busNum)
		{

			if (apart[j][1] - (max_busNum - studentSum) <= 0)
			{
				studentSum += apart[j][1];
				j--;
			}
			else
			{
				apart[j][1] -= (max_busNum - studentSum);
				//studentSum = 0;
				studentSum = max_busNum;
				//this pos, coding pleas~~~
			}
			if (school_pos>=j)
				break;
		}
		if (school_pos >= j)
			break;
	}

	cout << distance << endl;

	return 0;
}

/*
if (apart[i][0]<school_pos)
distance += ((school_pos - apart[i][0]) * 2);

cout << distance << endl;
while (apart[i][0]<school_pos)
{
if (apart[i][1] - (max_busNum - studentSum) < 0)
{
studentSum += apart[i][1];
i++;
}
else
{
apart[i][1] -= (max_busNum - studentSum);
distance += ((school_pos-apart[i][0]) * 2);
studentSum = 0;
}
cout << distance << endl;
}

int j = apartment_Count - 1;
studentSum = 0;
//cout << "school_pos" << school_pos << endl;
if (apart[j][0]>school_pos)
distance += ((apart[j][0] - school_pos) * 2);

//cout << distance << endl;
int count =0;
while (apart[j][0]>school_pos)
{
//cout << "j" << j << " "<<apart[j][0] << endl;
if (apart[j][1] - (max_busNum - studentSum) < 0)
{
studentSum += apart[j][1];
j--;
//cout << "one" << endl;
}
else
{
//cout << "two" << endl;
//cout << "!" << endl;
apart[j][1] -= (max_busNum - studentSum);
distance += ((apart[j][0] - school_pos) * 2);
studentSum = 0;
}
//cout << distance << endl;
}
*/