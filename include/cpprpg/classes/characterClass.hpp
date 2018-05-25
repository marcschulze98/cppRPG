#ifndef CPPRPG_CLASSES_CHARACTERCLASS
#define CPPRPG_CLASSES_CHARACTERCLASS

#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cpprpg/classes/skills.hpp>
#include <cpprpg/common/config.hpp>

#define DEFAULT_STRENGTH_CLASS 10
#define DEFAULT_DEXTERITY_CLASS 10
#define DEFAULT_INTELLIGENCE_CLASS 10
#define DEFAULT_INITATIVE_CLASS 10
#define DEFAULT_CONSTITUTION_CLASS 10
#define DEFAULT_ARMOR_TYPE HEAVY
#define MAX_SKILLS_PER_CLASS 5
#define MAX_SKILLS_PER_LEVEL 5


class SkillNode //extra file
{
	Skill skill;
	std::vector<SkillNode> next;
};

class SkillTree
{
	std::vector<SkillNode> head;
};
class CharacterClass
{
	public:
		const std::string name;
		attr_type constitution;
		attr_type strength;
		attr_type intelligence;
		attr_type dexterity ;
		attr_type initiative;
		ArmorType armor_type;
		std::vector<WeaponType> weapon_types;
		std::vector<Skill> skill_list;
		SkillTree skill_tree;

		CharacterClass(const std::string classname):
			name(classname),
			constitution(DEFAULT_CONSTITUTION_CLASS),
			strength(DEFAULT_STRENGTH_CLASS),
			intelligence(DEFAULT_INTELLIGENCE_CLASS),
			dexterity(DEFAULT_DEXTERITY_CLASS),
			initiative(DEFAULT_INITATIVE_CLASS),
			armor_type(ArmorType::DEFAULT_ARMOR_TYPE),
			weapon_types(),
			skill_list(),
			skill_tree()
			{
				auto section = class_ini.section_kv[classname];

				try
				{
					constitution += std::stoi(section["constitution"], nullptr, 0);
				} catch (...){}
				try
				{
					strength += std::stoi(section["strength"], nullptr, 0);
				} catch (...){}
				try
				{
					dexterity += std::stoi(section["dexterity"], nullptr, 0);
				} catch (...){}
				try
				{
					intelligence += std::stoi(section["intelligence"], nullptr, 0);
				} catch (...){}
				try
				{
					initiative += std::stoi(section["initiative"], nullptr, 0);
				} catch (...){}

			}

};

#endif //CPPRPG_CLASSES_CHARACTERCLASS
