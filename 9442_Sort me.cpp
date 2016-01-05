#include <iostream>
#include <string.h>

using namespace std;

char alpaArr[26];
char heap[26];

char *word[21];

void makeHeap()
{
	for (int i = 0; i < 26; i++)
	{
		heap[alpaArr[i]] = i;
	}
}

int Rcompare(int first, int end)
{
	int min = strlen(word[first]) > strlen(word[end]) ? strlen(word[end]) : strlen(word[first]);
	bool ended;
	for (int i = 0; i <  min; i++)
	{
		if (heap[word[first][i]] < heap[word[end][i]])
			return 1;
		else if (heap[word[first][i]] > heap[word[end][i]])
			return 0;
	}

	if (strlen(word[first]) < strlen(word[end]))
		return 1;
	else
		return 0;
}

int compare(int first, int end)
{
	//cout << "compare" << endl;
	//cout << "Cf" << first << "Ce" << end << endl;
	int min = strlen(word[first]) > strlen(word[end]) ? strlen(word[end]) : strlen(word[first]);
	
	for (int i = 0; i < min; i++)
	{
		if (heap[word[first][i]] > heap[word[end][i]])
			return 0;
		else if (heap[word[first][i]] < heap[word[end][i]])
			return 1;
	}

	if (strlen(word[first]) < strlen(word[end]))
		return 1;
	else
		return 0;
}


void swap(int first, int end)
{
	char *temp = word[first];
	word[first] = word[end];
	word[end] = temp;
}

void sort(int wordCount)
{
	for (int i = 0; i < wordCount;i++)
	{
		for (int j = i; j < wordCount; j++)
		{
			if (compare(j, i))
			{
				swap(i, j);
			}
		}
	}
}
/*
void sort(int first, int end)
{
	//cout << "first" << first << "end" << end << endl;
	int pivot = (first + end)/2;
	int f = first;
	int e = end;
	//cout << "pivot" << pivot << endl;
	while (f<=e)
	{
		while (compare(f, pivot)) f++;	//&&f<pivot
		while (compare(pivot, e)) e--;	//&&pivot<e

		if (f <= e){
			//cout << "f" << f << " " << "e" << e << endl;
			swap(f, e);
			f++; 
			e--;
		}
	}

	if (first < e) sort(first, e);
	if (f< end) sort(f, end);

	
}*/


int main()
{
	int wordCount;

	cin >> wordCount;
	
	int year = 1;

	while (wordCount != 0)
	{
		

		cin >> alpaArr;

		makeHeap();

		for (int i = 0; i < wordCount; i++)
		{
			word[i] = new char[31];
			cin >> word[i];
		}

		cout << "year " << year++ << endl;

		//swap(0, 1);
		
		sort(wordCount);

		for (int i = 0; i < wordCount; i++)
		{
			cout << word[i]<< endl;
		}

		for (int i = 0; i < wordCount; i++)
		{
			delete word[i];
		}

		cin >> wordCount;
	}
	



	return 0;
}