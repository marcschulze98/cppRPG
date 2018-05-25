#ifndef CPPRPG_CHARACTERS_INVENTORY
#define CPPRPG_CHARACTERS_INVENTORY

#include <vector>
#include <cpprpg/items/item.hpp>

class Character;

class Inventory
{
	private:
		Character& owner;
		unsigned max_mass();
	public:
		std::vector<Item> items;
		unsigned mass;
		Inventory(Character& owner): owner(owner) {}
		void put(Item i)
		{
			if(mass+i.mass>max_mass())
			{
				items.push_back(i);
				mass+=i.mass;
			}
		}
		Item pull(size_t index)
		{
			Item tmp = items[index];
			items.erase(items.begin()+index);
			return tmp;
		}
};
#endif //CPPRPG_CHARACTERS_INVENTORY
