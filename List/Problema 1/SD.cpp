#include <iostream>

struct node
{
	int info = NULL;
	node* prev = nullptr;
	node* next = nullptr;
};

struct List
{
	node* first = nullptr;
	node* last = nullptr;
	int elements = 0;

	void push_front(int var)
	{
		node* newnode = new node;
		newnode->info = var;
		newnode->next = first;
		if (first != nullptr)
		{
			first->prev = newnode;
		}
		else
		{
			last = newnode;
		}
		first = newnode;
		elements++;
	}

	void push_back(int var)
	{
		node* newnode = new node;
		newnode->info = var;
		newnode->prev = last;
		if (last != nullptr)
		{
			last->next = newnode;
		}
		else
		{
			first = newnode;
		}
		last = newnode;
		elements++;
	}

	void pop_front()
	{
		if (first == nullptr)
		{
			std::cout << "Nu avem de unde sa scoatem, lista este goala" << std::endl;
			return;
		}
		if (first == last)
		{
			first = last = nullptr;
			delete first;
			elements--;
			return;
		}
		node* aux = first;
		first = first->next;
		delete aux;
		first->prev = nullptr;
		elements--;
		std::cout << "A fost sters primul element din lista" << std::endl;
	}

	void pop_back()
	{
		if (last == nullptr)
		{
			std::cout << "Nu avem de unde sa scoatem, lista este goala" << std::endl;
			return;
		}
		if (first == last)
		{
			first = last = nullptr;
			delete first;
			elements--;
			return;
		}
		node* aux = last;
		last = last->prev;
		delete aux;
		last->next = nullptr;
		elements--;
		std::cout << "A fost sters ultimul element din lista" << std::endl;
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
		if (Nod == first)
		{
			pop_front();
			return;
		}
		if (Nod == last)
		{
			pop_back();
			return;
		}
		node* aux1 = Nod; 
		node* aux2 = Nod;
		aux1 = aux1->prev;
		aux2 = aux2->next;
		aux1->next = aux2;
		aux2->prev = aux1;
		delete Nod;
		elements--;
	}

	void remove(int key)
	{
		while (find(key) != nullptr)
			erase(find(key));
	}

	void insert(node* Nod, int val)
	{
		if (Nod == first)
		{
			push_front(val);
			return;
		}
		node* aux = Nod->prev;
		node* newnode = new node;
		newnode->info = val;
		aux->next = newnode;
		newnode->prev = aux;
		newnode->next = Nod;
		Nod->prev = newnode;
		elements++;
	}

	bool empty()
	{
		if (first == nullptr && last == nullptr)
			return false;
		return true;
	}

	void clear()
	{
		while (first != nullptr)
			pop_front();
	}

	void print()
	{
		for (node* i = first; i != nullptr; i = i->next)
			std::cout << i->info << " ";
		std::cout << std::endl;
	}

	int size()
	{
		return elements;
	}
};

bool palindrom(List L)
{
	node* first = L.first;
	node* last = L.last;
	while (first < last)
	{
		if (first->info != last->info)
			return false;
		first = first->next;
		last = last->prev;
	}
	return true;
}

bool compare(List L1, List L2)
{
	auto it1 = L1.first;
	auto it2 = L2.first;
	while (it1 != nullptr || it2 != nullptr)
	{
		if ((it1 == nullptr && it2 != nullptr) || (it1 != nullptr && it2 == nullptr))
			return false;
		if (it1->info != it2->info)
			return false;
		it1 = it1->next;
		it2 = it2->next;
	}
	return true;
}

int main()
{
	int choice;
	List list, list2;

	std::cout << "1. Adauga element la inceput" << std::endl;
	std::cout << "2. Adauga element la sfarsit" << std::endl;
	std::cout << "3. Sterge primul element" << std::endl;
	std::cout << "4. Sterge ultimul element" << std::endl;
	std::cout << "5. Cauta element" << std::endl;
	std::cout << "6. Sterge un element Nod din lista" << std::endl;
	std::cout << "7. Sterge toate aparitiile unei valori" << std::endl;
	std::cout << "8. Insereaza un element inaintea nodului dorit" << std::endl;
	std::cout << "9. Verifica daca lista este vida" << std::endl;
	std::cout << "10. Goleste lista" << std::endl;
	std::cout << "11. Afiseaza elementele listei" << std::endl;
	std::cout << "12. Afiseaza numarul de elemente din lista" << std::endl;
	std::cout << "13. Afiseaza daca lista este palindrom" << std::endl;
	std::cout << "14. Verifica daca doua liste sunt identice" << std::endl;
	std::cout << "15. Iesire" << std::endl << std::endl;

	while (true)
	{
		std::cout << "Introduceti optiunea: ";
		std::cin >> choice;

		switch (choice) 
		{
		case 1:
			int val1;
			std::cout << "Introduceti valoarea ce se doreste a fi adaugata la inceputul listei: ";
			std::cin >> val1;
			std::cout << std::endl;
			list.push_front(val1);
			break;
		case 2:
			int val2;
			std::cout << "Introduceti valoarea ce se doreste a fi adaugata la sfarsitul listei: ";
			std::cin >> val2;
			std::cout << std::endl;
			list.push_back(val2);
			break;
		case 3:
			list.pop_front();
			break;
		case 4:
			list.pop_back();
			break;
		case 5:
			int val3;
			std::cout << "Introduceti valoarea ce se doreste cautata: ";
			std::cin >> val3;
			std::cout << std::endl;
			std::cout << list.find(val3);
			break;
		case 6:
			int val4;
			std::cout << "Introduceti nodul ce se doreste a fi sters: ";
			std::cin >> val4;
			std::cout << std::endl;
			list.erase(list.find(val4));
			break;
		case 7:
			int val5;
			std::cout << "Introduceti valoarea ce se doreste a fi stearsa din toata lista: ";
			std::cin >> val5;
			std::cout << std::endl;
			list.remove(val5);
			break;
		case 8:
			int val6, val7;
			std::cout << "Introduceti valoarea ce se doreste a fi inserata si inaintea carui nod: ";
			std::cin >> val6 >> val7;
			std::cout << std::endl;
			list.insert(list.find(val7), val6);
			break;
		case 9:
			if (list.empty() == true)
				std::cout << "Lista nu este vida" << std::endl;
			else
				std::cout << "Lista este vida" << std::endl;
			break;
		case 10:
			list.clear();
			std::cout << "Lista a fost golita" << std::endl;
			break;
		case 11:
			list.print();
			break;
		case 12:
			std::cout << "Lista are " << list.size() << " elemente" << std::endl;
			break;
		case 13:
			if (palindrom(list) == true)
				std::cout << "Lista este palindrom" << std::endl;
			else
				std::cout << "Lista nu este palindrom" << std::endl;
			break;
		case 14:
			std::cout << "Lista a doua contine numerele 5 28 40 2006" << std::endl;
			list2;
			list2.push_back(5);
			list2.push_back(28);
			list2.push_back(40);
			list2.push_back(2006);
				if (compare(list, list2) == true)
					std::cout << "Listele sunt la fel" << std::endl;
				else
					std::cout << "Listele nu sunt la fel" << std::endl;
				break;
		case 15:
			std::cout << "Ati iesit din program!" << std::endl;
			return 0;
		default:
			std::cout << "Opțiune invalidă. Alegeți din nou." << std::endl;
		}
	}
}