#ifndef CPPRPG_CHARACTERS_CHARACTER_HPP
#define CPPRPG_CHARACTERS_CHARACTER_HPP

#include <vector>
#include <cpprpg/classes/characterClass.hpp>
#include <cpprpg/races/characterRace.hpp>

using attr_type = int;

class Character
{
	public:
		const CharacterClass& character_class;
		const CharacterRace& character_race;

		attr_type constitution;
		attr_type strength;
		attr_type intelligence;
		attr_type dexterity;
		attr_type initiative;
		std::vector<Skill> current_skills;
	public:
		Character(const CharacterClass& character_class, const CharacterRace& character_race): character_class(character_class), character_race(character_race)
		{
			strength = character_class.strength + character_race.strength;
			dexterity = character_class.dexterity + character_race.dexterity;
			constitution = character_class.constitution + character_race.constitution;
			initiative = character_class.initiative + character_race.initiative;
			intelligence = character_class.intelligence + character_race.intelligence;
		}
};
#endif //CPPRPG_CHARACTERS_CHARACTER_HPP
