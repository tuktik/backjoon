#include <iostream>
using namespace std;

char** input;

void get_input(int* num);
void memory_alloc();
void swap(char * a, char * b);
void qsort_size(int num);

////////test
void test_input(int num);
void test_swap(int i, int j);

int main()
{
	int testNum;

	memory_alloc();
	get_input(&testNum);


	//test_swap(0,1);
	//test_input(testNum);
}

void get_input(int* num)
{
	cin>>*num;

	for(int i=0; i<*num; i++)
	{
		cin>>input[i];
	}
}
void memory_alloc()
{
	input = new char* [20000];
	
	for(int i =0; i<20000; i++)
	{
		input[i] = new char[50];
	}
}
void swap(char * a, char * b)
{
	char* temp;

	temp = a;
	a = b;
	b= temp;
}
void qsort_size(int num)
{
	int pivot = strlen(input[num-1]);



}

//////////////test
void test_input(int num)
{
	for(int i=0; i<num; i++)
	{
		cout<<input[i]<<endl;
	}
}
void test_swap(int i, int j)
{
	swap(input[i],input[j]);
}
