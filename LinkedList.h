#pragma once
#include "Pokemon.h"

class Node
{
public:
	Node* next;
	Node* last;
	Pokemon* poke;

	Node(Pokemon* p)
	{
		poke = p;
	}
};

class sortedList
{
public:
	Node* first;
	Node* last;
	int size;

	sortedList()
	{
		first = nullptr;
		size = 0;
	}

	void insert(Pokemon* p)
	{
		Node* n = new Node(p);
		size++;
		if (first == nullptr)
		{
			first = n;
			last = n;
			return;
		}
		Node* current = first;
		int nn;
		int cc;
		while (true)
		{
			nn = n->poke->getSearchedValue();
			cc = current->poke->getSearchedValue();
			if (nn <= cc)
			{
				if (current == first)
				{
					first = n;
				}
				if (current->last != nullptr)
				{
					n->last = current->last;
					current->last->next = n;

				}
				n->next = current;
				current->last = n;
				return;
			}
			if ((nn == cc) && (current->next != nullptr))
			{
				n->next = current->next;
				n->last = current;
				n->next->last = n;
				current->next = n;
			}
			if (current->next != nullptr)
				current = current->next;
			else
				break;
		}
		current->next = n;
		n->last = current;
		last = n;
	}

	vector<Pokemon*> getVector()
	{
		Node* current = first;
		vector<Pokemon*> vec;
		while (current != nullptr)
		{
			vec.push_back(current->poke);
			current = current->next;
		}
		return vec;
	}

	void returnPokemon(int indexTop, int indexBot, int count, vector<Pokemon*>& results)
	{
		Node* n = first;
		returnPokemonRecursive(indexTop, indexBot, count, n, results);
	}

	void returnPokemonRecursive(int indexTop, int indexBot, int count, Node* n, vector<Pokemon*>& results)
	{
		if (n->poke->getSearchedValue() <= indexTop && n->poke->getSearchedValue() >= indexBot)
		{
			results.push_back(n->poke);
			if (results.size() == count)
				return;
		}
		if (n->next)
			returnPokemonRecursive(indexTop, indexBot, count, n->next, results);
	}
};