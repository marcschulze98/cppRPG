#ifndef CPPRPG_CLASSES_BASECLASS
#define CPPRPG_CLASSES_BASECLASS

#include <string>
#include <array>
#include <memory>
#include <cpprpg/classes/skills.hpp>

#define DEFAULT_CLASSNAME "Classless"
#define DEFAULT_STRENGTH_CLASS 10
#define DEFAULT_DEXTERITY_CLASS 10
#define DEFAULT_INTELLIGENCE_CLASS 10
#define DEFAULT_INITATIVE_CLASS 10
#define DEFAULT_CONSTITUTION_CLASS 10
#define DEFAULT_ARMOR_TYPE HEAVY
using attr_type = int;

enum class ArmorType {LIGHT, MEDIUM, HEAVY};
enum class WeaponType {SWORD1H, SWORD2H, STAFF2H, STAFF1H, DAGGER, SHIELD, CROSSBOW, BOW, MACE, AXE1H, AXE2H};

class BaseClass
{
	public:
		constexpr static char classname[] = DEFAULT_CLASSNAME;
		constexpr static attr_type constitution = DEFAULT_CONSTITUTION_CLASS;
		constexpr static attr_type strength = DEFAULT_STRENGTH_CLASS;
		constexpr static attr_type intelligence = DEFAULT_INTELLIGENCE_CLASS;
		constexpr static attr_type dexterity = DEFAULT_DEXTERITY_CLASS;
		constexpr static attr_type initiative = DEFAULT_INITATIVE_CLASS;
		constexpr static ArmorType armor_type = ArmorType::DEFAULT_ARMOR_TYPE;
		constexpr static std::array<WeaponType, 0> weapon_types = {};
		constexpr static std::array<Skill, 2> skill_list = {Skill::FistAttack(), Skill::Bash()};
};

class Warrior: public BaseClass
{
	public:
		constexpr static char racename[] = "Warrior";
		constexpr static attr_type constitution = DEFAULT_CONSTITUTION_CLASS + 1;
		constexpr static attr_type strength = DEFAULT_STRENGTH_CLASS + 1;
};

class Rogue: public BaseClass
{
	public:
		constexpr static char racename[] = "Rogue";
		constexpr static attr_type dexterity = DEFAULT_DEXTERITY_CLASS + 1;
		constexpr static attr_type initiative = DEFAULT_INITATIVE_CLASS + 1;
};

class Mage: public BaseClass
{
	public:
		constexpr static char racename[] = "Mage";
		constexpr static attr_type intelligence = DEFAULT_INTELLIGENCE_CLASS + 2;
};

#endif //CPPRPG_CLASSES_BASECLASS
