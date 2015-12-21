#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	
	node(int data) :data(data), left(NULL), right(NULL){}
};

class heap
{
	node *header;
	
public:
	void push(int input)
	{
		node * temp = header;
		node * new_node = new node(input);
		while (temp != NULL)
		{
			if (temp->data > input)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		temp = new_node;
	}
	node* popMax()
	{
		if (header == NULL)
		{
			return NULL;
		}
		else
		{
			node* new_node = header;
			node* parent;
			while (new_node->right != NULL)
			{
				parent = new_node;
				new_node = new_node->right;
			}
			parent->right = NULL;
			return new_node;
		}
	}
	node* popMin()
	{
		if (header == NULL)
		{
			return NULL;
		}
		else
		{
			node* new_node = header;
			node* parent;
			while (new_node->left != NULL)
			{
				parent = new_node;
				new_node = new_node->left;
			}
			parent->left = NULL;
			return new_node;
		}
	}
	void print()
	{
	}
};


int main()
{
	int testNum;

	cin >> testNum;

	int instNum;
	
	for (int a = 0; a < testNum; a++)
	{
		cin >> instNum;

		for (int i = 0; i < instNum; i++)
		{
			char instruction;
			int inputNum;

			cin >> instruction;
			cin >> inputNum;


			switch (instruction)
			{
			case 'I':


				break;
			case 'D':

				break;
					
			}
		}




	}

	return 0;
}

//
//class Node
//{
//public:
//	int data;
//	Node* right;
//	Node* left;
//
//	Node(int data) :data(data), right(NULL), left(NULL){}
//};
//
//class queue
//{
//	Node* header;
//
//public:
//
//	queue() :header(NULL){}
//	void push(int data)
//	{
//		Node* new_node = new Node(data);
//
//		if (header == NULL)
//		{
//			header = new_node;
//		}
//		else
//		{
//			Node* temp = header;
//
//			while (temp != NULL)
//			{
//				if (temp->data > data)
//				{
//					temp = temp->left;
//				}
//				else
//				{
//					temp = temp->right;
//				}
//			}
//
//			//temp = new_node;
//		}
//	}
//	int pop()
//	{
//
//	}
//
//
//};