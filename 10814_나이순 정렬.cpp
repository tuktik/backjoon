#include <iostream>

using namespace std;

class info
{
public:
	int age;
	char *name;
	int order;

	info(){}
	info(int age, char* name, int order) :age(age), name(name), order(order){}
};

info infoArr[100002];

bool compare(info a, info b)
{
	if (a.age < b.age)
		return 1;
	else if (a.age>b.age)
	{
		return 0;
	}
	else
	{
		if (a.order < b.order)
			return 1;
		else
		{
			return 0;
		}
	}

}
void info_swap(int first, int end)
{
	info temp = infoArr[first];
	infoArr[first] = infoArr[end];
	infoArr[end] = temp;
}

void quick(int first, int end)
{
	info pivot = infoArr[(first + end) / 2];
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (compare(infoArr[f], pivot)) f++;
		while (compare(pivot, infoArr[e])) e--;

		if (f <= e)
		{
			info_swap(f, e);
			f++;
			e--;
		}
	}

	if (first < e) quick(first, e);
	if (f< end) quick(f, end);
}

int main()
{
	int n;

	cin >> n;

	int age;
	char* name;
	int count=1;

	for (int i = 0; i < n; i++)
	{
		cin >> age;
		name = new char[102];
		cin >> name;
		info temp(age, name, count++);
		infoArr[i] = temp;
	}

	quick(0, n - 1);
	
	for (int i = 0; i < n; i++)
	{
		cout << infoArr[i].age << " " << infoArr[i].name << endl;
	}
	
	return 0;
}