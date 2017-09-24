#pragma once

struct Node
{
	int data;
	Node* next;
};

class List
{
	Node* head;
	int count;

public:
	List()
	{
		head = nullptr;
		count = 0;
	}

	void add(int data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
			count++;
		}
		else
		{
			Node* node = head;
			for (int i = 0; i < count - 1; i++)
			{
				node = node->next;
			}
			node->next = new Node;
			node->next->data = data;
			node->next->next = nullptr;
			count++;
		}
	}

	void remove(int index)
	{
		Node* node = head;

		if (index == 1)
		{
			head = node->next;
			this->count--;
		}
		else
		{
			index--;

			for (int i = 0; i < index - 1; i++)
			{
				node = node->next;
			}

			node->next = node->next->next;
			this->count--;
		}
	}

	void insert(int data, int index)
	{
		Node* node = head;
		Node* temp = nullptr;

		if (index == 1)
		{
			temp = node;
			head = new Node;
			head->data = data;
			head->next = temp;
		}
		else
		{
			index--;

			for (int i = 0; i < index - 1; i++)
			{
				node = node->next;
			}

			temp = node->next;
			node->next = new Node;
			node->next->data = data;
			node->next->next = temp;
		}

		count++;
		//		delete temp;
	}

	int& operator[](int index)
	{
		Node* node = head;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		return node->data;
	}

	int getCount() { return this->count; }
};