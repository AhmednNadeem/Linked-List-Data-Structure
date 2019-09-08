#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

node* head=nullptr;
node* tail = nullptr;

void Insert_at_start(int n)
{
	node* ptr = new node;
	ptr -> data = n;
	if (head == NULL)
	{
		head = ptr;
		ptr->next = nullptr;
		tail = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

void Insert_at_End(int n)
{
	node* ptr = new node;
	ptr->data = n;
	if (head == nullptr)
	{
		head = ptr;
		tail = ptr;
		ptr->next = nullptr;
	}
	else
	{
		tail->next = ptr;
		ptr->next = nullptr;
		tail = ptr;
	}
}

void insert_in_middle(int n,int key)
{
	bool flag = false;
	node* ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data == key)
		{
			flag = true; break;
		}
		ptr = ptr->next;
	}
	if (flag == true)
	{
		node* p = new node;
		p->data = n;
		p->next = ptr->next;
		ptr->next = p;
	}
	if (flag == false)
	{
		cout << endl;
		cout << "Desired entry doesn't found in the Linked List" << endl;
	}
}

void delete_from_start()
{
	node* p = head;
	head = head->next;
	delete p;
	p = nullptr;
}

void delete_from_end()
{
	node* ptr = head;
	while (ptr->next != tail)
	{
		ptr = ptr->next;
	}
	delete tail;
	tail = ptr;
	ptr->next = nullptr;
}

void delete_from_middle(int key)
{
	node* ptr = head;
	node* p = head;
	while (ptr != nullptr)
	{
		if (ptr->data == key)
		{
			break;
		}
		ptr = ptr->next;
	}
	while (p->next != ptr)
	{
		p = p->next;
	}
	p -> next = ptr->next;
	delete ptr;
}
void Traversing_linked_list(int key)
{
	int count = 0;
	bool flag = false;
	if (head == nullptr)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		node* ptr = head;
		while (ptr != nullptr)
		{
			count++;
			if (ptr->data == key)
			{
				cout << "Entry found at "<<count  <<" node"<< endl;
				flag = true;
			}
			ptr = ptr->next;
		}
		if (flag == false)
		{
			cout << "Entry not found in the linked list" << endl;
		}
	}
}
void Print_linked_list()
{
	node* ptr = head;
	cout << "-------------------Linked List------------------" << endl;
	if (head == nullptr)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (ptr != nullptr)
		{
			cout << ptr->data << "  ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}

void reverse_print(node* h1)
{
	if (h1 == nullptr)
		return;
	reverse_print(h1->next);
	cout << h1->data << " ";
}
int main()
{
	Insert_at_End(1);
	Insert_at_End(2);
	Insert_at_End(3);
	Insert_at_End(4);
	Insert_at_End(5);
	Insert_at_End(6);
	Insert_at_End(7);
	Insert_at_End(8);
	Insert_at_End(9);
	Print_linked_list();
	//delete_from_start();
	//delete_from_end();
	delete_from_middle(6);
	delete_from_middle(8);
	Print_linked_list();
	reverse_print(head);

	//insert_in_middle(30, 3);
	//insert_in_middle(20, 40);

	//Print_linked_list();
	//Traversing_linked_list(30);
	system("pause");
}