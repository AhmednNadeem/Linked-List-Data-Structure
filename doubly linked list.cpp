#include<iostream>
using namespace std;
struct node
{
	int data;
	node* prev;
	node* next;
};

node* head = nullptr;
node* tail = nullptr;

void insertion_at_start(int n)
{
	node* ptr = new node;
	ptr->data = n;
	if (head == nullptr)
	{
		ptr->next = nullptr;
		ptr->prev = nullptr;
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->next = head;
		ptr->prev = nullptr;
		head = ptr;
	}
}

void insertion_at_end(int n)
{
	node* ptr = new node;
	ptr->data = n;
	if (head == nullptr)
	{
		ptr->prev = nullptr;
		ptr->next = nullptr;
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->prev = tail;
		tail->next = ptr;
		ptr->next = nullptr;
		tail = ptr;
	}
}

void insert_in_middle(int n, int key)
{
	node* ptr = head;
	bool flag = false;
	while (ptr != nullptr)
	{
		if (ptr->data == key)
		{
			flag = true;
			break;
		}
		ptr = ptr->next;
	}
	if (flag == true)
	{
		node* p = new node;
		p->data = n;
		p->next = ptr->next;
		p->prev = ptr;
		ptr->next->prev = p;
		ptr->next = p;
	}
}

void deletion_at_start()
{
	node* ptr = head;
	head->next->prev = nullptr;
	head = head->next;
	delete ptr;
}

void deletion_at_end()
{
	node* ptr = tail;
	tail->prev->next = nullptr;
	tail = tail->prev;
	delete ptr;
	
}

void deletion_from_middle(int key)
{
	bool flag = false;
	node* ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data == key)
		{
			flag = true;
			break;
		}
		ptr = ptr->next;
	}
	if (flag == true)
	{
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		delete ptr;
	}
	if (flag == false)
	{
		cout << "desired entry doesnt found in the linked list" << endl;
	}
}
void Reseverse_traverse_list()
{
	node* ptr = tail;
	cout << "-----------------Reverse Linked List-----------------" << endl;
	while (ptr != nullptr)
	{
		cout << ptr->data << "  ";
		ptr = ptr->prev;
	}
	cout << endl;
}
void Print_list()
{
	node* ptr = head;
	if (head == nullptr)
	{
		cout << "Linked list is empty" << endl;
	}
	else
	{
		cout << "-----------------LINKED LIST----------------" << endl;
		while (ptr != nullptr)
		{
			cout << ptr->data << "  ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}
int main()
{
	insertion_at_end(1);
	insertion_at_end(2);
	insertion_at_end(3);
	insertion_at_end(4);
	insertion_at_end(5);
	Print_list();
	//insert_in_middle(20,4);
	//Print_list();
	//Reseverse_traverse_list();
	//deletion_at_end();
	//deletion_at_end();
	deletion_from_middle(2);
	deletion_from_middle(4);
	Print_list();

	system("pause");
}