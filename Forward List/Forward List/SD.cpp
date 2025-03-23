#include <iostream>

struct node
{
	int info = NULL;
	node* next = nullptr;
};

struct List
{
	node* first = nullptr;
	int nr_elem = 0;

	void push_front(int elem)
	{
		node* newnode = new node;
		newnode->info = elem;
		if (first != nullptr)
		{
			newnode->next = first;
		}
		first = newnode;
		nr_elem++;
	}

	void push_back(int elem)
	{
		node* newnode = new node;
		newnode->info = elem;
		if (first != nullptr)
		{
			node* iterator = nullptr;
			for (auto it = first; it != nullptr; it = it->next)
				iterator = it;
			iterator->next = newnode;
		}
		else
		{
			first = newnode;
		}
		nr_elem++;
	}

	void pop_front()
	{
		if (first == nullptr)
		{
			std::cout << "Nu avem de unde sa scoatem" << std::endl;
			return;
		}
		node* aux = first;
		first = first->next;
		delete aux;
		nr_elem--;
	}

	void pop_back()
	{
		if (first == nullptr)
		{
			std::cout << "Nu avem de unde sa scoatem" << std::endl;
			return;
		}
		node* toDelete = first;
		node* prev = nullptr;
		while (toDelete->next != nullptr)
		{
			prev = toDelete;
			toDelete = toDelete->next;
		}
		if (prev != nullptr)
			prev->next = nullptr;
		delete toDelete;
		nr_elem--;
	}

	node* find(int key)
	{
		auto it = first;
		while (it != nullptr && it->info != key)
			it = it->next;
		return it;
	}

	void erase(node* Nod)
	{
		if (first == nullptr)
		{
			std::cout << "Nu avem de unde sa scoatem" << std::endl;
			return;
		}
		if (Nod == first)
		{
			pop_front();
			return;
		}
		node* iterator = nullptr;
		for (auto it = first; it != nullptr; it = it->next)
			iterator = it;
		if (Nod == iterator)
		{
			pop_back();
			return;
		}
		node* iterator1 = nullptr;
		node* iterator2 = nullptr;
		for (auto it = first; it != Nod; it = it->next)
			iterator1 = it;
		iterator2 = iterator1->next->next;
		iterator1->next = iterator2;
		delete Nod;
		nr_elem--;
	}

	void remove(int key)
	{
		while (find(key) != nullptr)
			erase(find(key));
	}

	void insert(node* Nod, int val)
	{
		if (Nod == first || first == nullptr)
		{
			push_front(val);
			return;
		}
		node* aux = nullptr;
		for (auto it = first; it != Nod; it = it->next)
			aux = it;
		node* newnode = new node;
		newnode->info = val;
		aux->next = newnode;
		newnode->next = Nod;
		nr_elem++;
	}

	bool empty()
	{
		if (first == nullptr)
			return false;
		return true;
	}

	void clear()
	{
		while (first != nullptr)
			pop_front();
	}

	int size()
	{
		return nr_elem;
	}

	void print()
	{
		for (auto it = first; it != nullptr; it = it->next)
			std::cout << it->info << " ";
		std::cout << std::endl;
	}
};

int main()
{
	List l;
	l.push_front(10);
	l.push_front(28);
	l.push_back(20);
	l.push_back(6);
	l.erase(l.find(10));
	l.print();
	l.insert(l.find(20), 10);
	l.print();

	return 0;
}