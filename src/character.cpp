#include <cpprpg/characters/character.hpp>

attr_type Character::get_max_hp()
{
	return this->get_constitution()*10;
}
attr_type Character::get_max_energy()
{
	return 100;
}
attr_type Character::get_constitution()
{
	return this->base_attributes.constitution;
}
attr_type Character::get_strength()
{
	return this->base_attributes.strength;
}
attr_type Character::get_dexterity()
{
	return this->base_attributes.dexterity;
}
attr_type Character::get_intelligence()
{
	return this->base_attributes.intelligence;
}
attr_type Character::get_initiative()
{
	return this->base_attributes.initiative;
}
