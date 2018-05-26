#define LEVEL_CAP 100

#include <cpprpg/characters/character.hpp>
#include <cpprpg/common/config.hpp>
#include <iostream>

void print_skilltree(skilltree_node& root, int a = 0);


int main()
{
	init_all();
	print_skilltree(skilltrees["Warrior"]);
	Character w("Elf","Mage");
	std::cout << w.get_intelligence() << std::endl;
	std::cout << w.get_dexterity() << std::endl;
	//w.current_skills[0](skill_arg()); planned
}
