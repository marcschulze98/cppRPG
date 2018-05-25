#define LEVEL_CAP 100

#include <cpprpg/characters/character.hpp>
#include <cpprpg/common/config.hpp>
#include <iostream>

int main()
{
	init_all();
	Character w("Elf","Mage");
	std::cout << w.get_intelligence() << std::endl;
	std::cout << w.get_dexterity() << std::endl;
	//w.current_skills[0](skill_arg()); planned
}
