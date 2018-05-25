#ifndef CPPRPG_CHARACTERS_CHARACTER_HPP
#define CPPRPG_CHARACTERS_CHARACTER_HPP

#include <vector>
#include <cpprpg/classes/characterClass.hpp>
#include <cpprpg/races/characterRace.hpp>
#include <cpprpg/characters/inventory.hpp>
#include <cpprpg/characters/equipment.hpp>
#include <cpprpg/common/config.hpp>

using attr_type = int;

class Character
{
	private:
		const CharacterClass character_class;
		const CharacterRace character_race;

	public:
		attr_type current_hp;
		attr_type current_energy;
		Inventory inventory;
		Equipment equipment;
		//Professions[]
		attributes base_attributes;
		std::vector<Skill> current_skills;

		Character(const std::string racename, const std::string classname): character_class(classname), character_race(racename), inventory(*this)
		{
			base_attributes.name="Nameless";
			base_attributes.strength = character_class.strength + character_race.strength;
			base_attributes.dexterity = character_class.dexterity + character_race.dexterity;
			base_attributes.constitution = character_class.constitution + character_race.constitution;
			base_attributes.initiative = character_class.initiative + character_race.initiative;
			base_attributes.intelligence = character_class.intelligence + character_race.intelligence;
		}
		attr_type get_max_hp();
		attr_type get_max_energy();
		attr_type get_constitution();
		attr_type get_strength();
		attr_type get_dexterity();
		attr_type get_intelligence();
		attr_type get_initiative();
};
#endif //CPPRPG_CHARACTERS_CHARACTER_HPP
