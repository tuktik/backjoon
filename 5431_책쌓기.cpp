#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node* prev;
	node* next;

	node(int data) :data(data), prev(NULL), next(NULL){}
};

class stack
{
	node* front;
	node* rear;
	int cnt;

public:
	stack() :front(NULL), rear(NULL), cnt(0){}

	void init()
	{
		node* now_node = rear;

		while (now_node != NULL)
		{
			node* prev_node = now_node->prev;

			delete now_node;
			now_node = prev_node;
		}
		front = NULL;
		rear = NULL;
		cnt = 0;
	}
	void pushFront(int input)
	{
		node* new_node = new node(input);

		if (rear == NULL)
		{
			rear = new_node;
		}

		new_node->next = front;
		if (front != NULL)
			front->prev = new_node;

		front = new_node;
	}
	void push(int input)
	{
		node * new_node = new node(input);

		if (front == NULL)
		{
			front = new_node;
		}

		new_node->prev = rear;
		if (rear != NULL)
			rear->next = new_node;

		rear = new_node;
	}

	void search()
	{
		bool is_Notsorting = true;
		while (is_Notsorting)
		{
			node* now_node = rear->prev;
			//cout << "!" << endl;
			while (now_node != NULL)
			{
				node* prev_node = now_node->prev;
				node* next_node = now_node->next;
				is_Notsorting = false;

				if (now_node->data < next_node->data)
				{
					if (prev_node != NULL)
						prev_node->next = next_node;
					if (next_node != NULL)
						next_node->prev = prev_node;
					push(now_node->data);
					delete now_node;
					is_Notsorting = true;
					cnt++;
					break;
				}
				now_node = now_node->prev;
			}
			//printStack();
		}
	}


	void printStack()
	{
		node * tmp = rear;
		while (tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->prev;
		}
		cout << endl;
	}

	int getCnt()
	{
		return cnt;
	}
};

stack bookStack;
int main()
{
	int testNum;

	cin >> testNum;

	for (int a = 0; a < testNum; a++)
	{
		int bookNum;

		cin >> bookNum;

		for (int i = 0; i < bookNum; i++)
		{
			int tmp;
			cin >> tmp;
			bookStack.pushFront(tmp);
		}
		bookStack.search();
		//bookStack.printStack();

		cout << bookStack.getCnt() << endl;

		bookStack.init();
	}

	return 0;
}