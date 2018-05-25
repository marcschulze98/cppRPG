#include <cpprpg/classes/skills.hpp>
#include <cpprpg/characters/character.hpp>

std::map<std::string, Skill(*)()> all_skills;
std::vector<std::map<std::string, skilltree_node>> skilltrees;


void init_skills()
{
	all_skills["Hit"] = Skill::Hit;
	all_skills["Bash"] = Skill::Bash;
	all_skills["Defend"] = Skill::Defend;
	all_skills["Taunt"] = Skill::Taunt;
}

void init_skilltrees()
{
	/*
	//iterate over all skilltree files
	std::string filename = "Warrior.skilltree"
	std::ifstream skilltree_file(std::string(CONFIG_FOLDER)+std::string("skills/")+filename);

	auto splitter = filename.find(".");

	std::string skilltree_name = filename.substr(0, filename.find("."));
	skilltrees.emplace_back();
	auto& current_killtree = skilltrees[skilltrees.size()-1][skilltree_name];

	*/
}

constexpr Skill Skill::Hit()
{
	return Skill("Hit", "Inflicts basic attack damage to an enemy", [](skill_arg arg){/*arg.target.hp -= 10*/}, SkillType::TARGETED);
}

constexpr Skill Skill::Bash()
{
	return Skill("Bash", "Inflicts 2 * basic attack damage to an enemy", nullptr, SkillType::TARGETED);
}

constexpr Skill Skill::Defend()
{
	return Skill("Defennd", "defends", nullptr, SkillType::TARGETED);
}

constexpr Skill Skill::Taunt()
{
	return Skill("Taunt", "taunts", nullptr, SkillType::TARGETED);
}
