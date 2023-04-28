#include "Block.h"

class BTree
{
private:
	Block* root;
	string searchType;

	void appendRoot(Block* b)
	{
		root = b;
	}

public:
	//initializes a new tree
	BTree(string st)
	{
		searchType = st;
		root == nullptr;
	}

	//inserts a pokemon P into the tree, sorting and splitting are done for you
	void insert(Pokemon* p)
	{
		p->updateSearchedVal(searchType);

		if (root == nullptr)
		{
			Block* pushBlock;
			pushBlock = new Block(true, true);
			pushBlock->insert(p, false);
			root = pushBlock;
			return;
		}
		Block* b = nullptr;

		b = root->insert(p, false);

		if (b != nullptr)
		{
			if (root->getParent() != nullptr)
				if (root->getParent()->bRoot())
					root = b->getParent();
			delete(b);
		}

	}

	//returns a vector of pokemon with 'searchVal' between the two indices (inclusive), larger index comes FIRST
	//count represents the amount of pokemon you would like, in order to get every pokemon, enter indexTop - indexBot in the count field
	vector<Pokemon*> findPokemon(int indexTop, int indexBot, int count)
	{
		vector<Pokemon*> results;
		root->findPokemon(indexTop, indexBot, count, results);
		return results;
	}
};