#include <iostream>

using namespace std;

//30, 000
int apart[30000][2];

void sorting(int apartment_Count)
{
	for (int i = 0; i < apartment_Count; i++)
	{
		for (int j = i + 1; j < apartment_Count; j++)
		{
			if (apart[i][0]>apart[i][0])
			{
				int temp[2];
				temp[0] = apart[i][0];
				temp[1] = apart[i][1];
				apart[i][0] = apart[j][0];
				apart[i][1] = apart[j][1];
				apart[j][0] = temp[0];
				apart[j][1] = temp[1];
			}
		}
	}
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

	sorting(apartment_Count);

	//for (int i = 0; i < apartment_Count; i++)
	//{
	//	cout << apart[i][0] << " " << apart[i][1] << endl;
	//}

	int i = 0;
	int studentSum = 0;
	int distance = 0;

	while ()
	{
		distance += ((school_pos - apart[i][0]) * 2);

		while (studentSum <= max_busNum &&)
		{
			if (apart[i][1] - (max_busNum - studentSum) <= 0)
			{
				studentSum += apart[i][1];
				i++;
			}
			else
			{
				apart[i][1] -= (max_busNum - studentSum);
				studentSum = 0;
				//this pos, coding pleas~~~
			}

		}
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
	cout << distance << endl;





	return 0;
}