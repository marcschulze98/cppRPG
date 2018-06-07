#ifndef CPPRPG_COMMON_CONFIG_HPP
#define CPPRPG_COMMON_CONFIG_HPP


#include <cpprpg/common/iniparse.hpp>
#include <vector>
#include <string>
#include <variant>

using attr_type = int;
using lvl_type = int;

#define CONFIG_FOLDER "/home/marc/Schreibtisch/cppRPG/config/"
#define LEVEL_CAP 100

class Skill;
using skill_ptr = Skill(*)();


struct skilltree_node
{
	lvl_type level = 0;
	std::vector<std::variant<skill_ptr, std::string>> skills;
	std::vector<skilltree_node> next;
};


enum class ArmorType {LIGHT, MEDIUM, HEAVY};
enum class WeaponType {SWORD1H, SWORD2H, STAFF2H, STAFF1H, DAGGER, SHIELD,
                       CROSSBOW, BOW, MACE, AXE1H, AXE2H};

struct attributes
{
	std::string name;
	attr_type constitution;
	attr_type strength;
	attr_type intelligence;
	attr_type dexterity;
	attr_type initiative;
};

extern ini_object class_ini;
extern ini_object race_ini;
extern std::map<std::string, Skill(*)()> all_skills;
extern std::map<std::string, skilltree_node> skilltrees;

void init_class_ini();
void init_race_ini();
void init_skills();
void init_skilltrees();

static inline void init_all()
{
	init_race_ini();
	init_class_ini();
	init_skills();
	init_skilltrees();
}

#endif // CPPRPG_COMMON_CONFIG_HPP
