#include <cpprpg/characters/inventory.hpp>
#include <cpprpg/characters/character.hpp>

unsigned Inventory::max_mass()
{
	return owner.get_constitution()*200;
}
