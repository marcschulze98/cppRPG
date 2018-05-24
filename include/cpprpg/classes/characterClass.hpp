#ifndef CPPRPG_CLASSES_CHARACTERCLASS
#define CPPRPG_CLASSES_CHARACTERCLASS

#include <string>
#include <vector>
#include <memory>
#include <cpprpg/classes/skills.hpp>

#define DEFAULT_STRENGTH_CLASS 10
#define DEFAULT_DEXTERITY_CLASS 10
#define DEFAULT_INTELLIGENCE_CLASS 10
#define DEFAULT_INITATIVE_CLASS 10
#define DEFAULT_CONSTITUTION_CLASS 10
#define DEFAULT_ARMOR_TYPE HEAVY
#define LEVEL_CAP 100
#define MAX_SKILLS_PER_CLASS 5
#define MAX_SKILLS_PER_LEVEL 5
using attr_type = int;

class SkillNode
{
	Skill skill;
	std::vector<SkillNode> next;
};

class SkillTree
{
	std::vector<SkillNode> head;
};

enum class ArmorType {LIGHT, MEDIUM, HEAVY}; // more global
enum class WeaponType {SWORD1H, SWORD2H, STAFF2H, STAFF1H, DAGGER, SHIELD, CROSSBOW, BOW, MACE, AXE1H, AXE2H};

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

			}

};

#endif //CPPRPG_CLASSES_CHARACTERCLASS
