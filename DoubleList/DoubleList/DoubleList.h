#pragma once

struct Node
{
	int data;
	Node* next;
	Node* previous;
};

class List
{
	Node* head;
	Node* tail;
	int count;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	~List()
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}

	void add(int data)
	{
		Node *node = new Node;
		node->next = nullptr;
		node->data = data;

		if (head == nullptr)
		{
			node->previous = nullptr;
			head = tail = node;
		}
		else
		{
			node->previous = tail;
			tail->next = node;
			tail = node;
		}

		count++;
	}

	void remove(int index)
	{
		Node* node = head;

		if (index == 1)
			head = node->next;
		else
		if (index == this->count)
		{
			node = tail;
			tail = tail->previous;
			tail->next = nullptr;
			delete node;
		}
		else
		{
			index--;

			if ((this->count / 2) < index)
			{
				node = tail;

				for (int i = count - 1; i > index; i--)
					node = node->previous;

				node->next = node->next->next;
				node->next->previous = node;
			}
			else
			{
				for (int i = 0; i < index - 1; i++)
					node = node->next;

				node->next = node->next->next;
				node->next->previous = node;
			}
		}

		this->count--;
	}

	void insert(int data, int index)
	{
		Node* temp = nullptr;
		Node* node = nullptr;

		if (index == 1)
		{
			temp = head;
			head = new Node;
			head->data = data;
			head->next = temp;
			head->previous = nullptr;
			
			this->count++;
		}
		else
		if (index == getCount())
			add(data);
		else
		{
			index--;

			if ((this->count / 2) <= index)
			{
				node = tail;

				for (int i = this->count - 1; i > index - 1; i--)
					node = node->previous;
			}
			else
			{
				node = head;

				for (int i = 0; i < index - 1; i++)
					node = node->next;
			}

			temp = node->next;
			node->next = new Node;
			node->next->next = temp;
			node->next->data = data;
			node->next->previous = node;

			this->count++;
		}
		//delete temp;
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