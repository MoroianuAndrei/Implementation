#include <iostream>
#include <fstream>
#include <string>

struct node
{
	std::string info;
	node* next = nullptr;
};

struct Queue
{
	node* first = nullptr;
	node* last = nullptr;
	int nr_elem = 0;

	void push(std::string elem)
	{
		node* newnode = new node;
		newnode->info = elem;
		if (last != nullptr)
		{
			last->next = newnode;
		}
		else
		{
			first = newnode;
		}
		last = newnode;
		nr_elem++;
	}

	void pop()
	{
		if (first == nullptr)
		{
			std::cout << "Nu avem de unde sa scoatem, coada este goala" << std::endl;
			return;
		}
		if (first == last)
		{
			first = last = nullptr;
			delete first;
			nr_elem--;
			return;
		}
		node* aux = first;
		first = first->next;
		delete aux;
		nr_elem--;
		//std::cout << "A fost sters primul element din coada" << std::endl;
	}

	std::string front()
	{
		return first->info;
	}

	std::string back()
	{
		return last->info;
	}

	bool empty()
	{
		if (first == nullptr && last == nullptr)
			return true;
		else
			return false;
	}

	void clear()
	{
		while (empty() == false)
			pop();
	}

	int size()
	{
		return nr_elem;
	}
};

void ReadCandidate(int& time, Queue& candidate)
{
	int number;
	std::ifstream file("file.in");
	file >> time >> number;
	time = time * 60;
	for (int i = 0; i < number; i++)
	{
		std::string cand;
		file >> cand;
		candidate.push(cand);
	}
	file.close();
}

void solve(int time, Queue candidate)
{
	std::srand(std::time(nullptr));
	std::ofstream file("file.out");
	int tm = 0, day = 1;
	while(candidate.empty() == false)
	{
		int random = std::rand() % 11 + 5;
		std::cout << random << std::endl;
		if (tm + random > time)
		{
			day++;
			tm = 0;
		}
		if (tm + random <= time && day == 1)
		{
			candidate.pop();
			tm += random;
		}
		else
			if (tm + random <= time && day == 2)
			{
				file << candidate.front() << std::endl;
				tm += random;
				candidate.pop();
			}
			else
				if (day > 2)
					return;
	}
	if (day == 1)
		std::cout << "Nu a ajuns nici un elev sa fie corectat in ziua a doua";
}

int main()
{
	int time;
	Queue candidate;
	ReadCandidate(time, candidate);
	solve(time, candidate);

	return 0;
}