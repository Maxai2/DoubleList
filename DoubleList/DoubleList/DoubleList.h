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
		while (head) //Пока по адресу на начало списка что-то есть
		{
			tail = head->next; //Резервная копия адреса следующего звена списка
			delete head; //Очистка памяти от первого звена
			head = tail; //Смена адреса начала на адрес следующего элемента
		}
	}

	void add(int data)
	{
		//Node *temp = new Node; //Выделение памяти под новый элемент структуры
		//temp->next = nullptr;  //Указываем, что изначально по следующему адресу пусто
		//temp->data = data;//Записываем значение в структуру

		//if (head != nullptr) //Если список не пуст
		//{
		//	temp->previous= tail; //Указываем адрес на предыдущий элемент в соотв. поле
		//	tail->next = temp; //Указываем адрес следующего за хвостом элемента
		//	tail = temp; //Меняем адрес хвоста
		//}
		//else //Если список пустой
		//{
		//	temp->previous= nullptr; //Предыдущий элемент указывает в пустоту
		//	head = tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
		//}

		//count++;

		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = tail;
			head->previous = nullptr;
			count++;
		}
		else
		if (tail == nullptr)
		{
			tail = new Node;
			tail->data = data;
			tail->previous = head;
			tail->next = nullptr;
			count++;
		}
		else
		{
			Node* node = new Node;
			node = tail;

			node->data = tail->data;
			node->next = tail;
			node->previous = tail->previous;

			tail->data = data;
			tail->previous = node;
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