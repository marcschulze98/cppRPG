#include <cpprpg/classes/skills.hpp>
#include <cpprpg/characters/character.hpp>
#include <optional>
#include <stdexcept>

std::map<std::string, Skill(*)()> all_skills;
std::map<std::string, skilltree_node> skilltrees;

skilltree_node root;


void init_skills()
{
	all_skills["Hit"] = Skill::Hit;
	all_skills["Bash"] = Skill::Bash;
	all_skills["Defend"] = Skill::Defend;
	all_skills["Taunt"] = Skill::Taunt;
}

static std::vector<std::string> string_split(const std::string str, char delim)
{
	std::vector<std::string> ret(1);
	for(char c: str)
	{
		if(c != delim)
		{
			ret[ret.size()-1].push_back(c);
		} else {
			ret.emplace_back();
		}
	}

	return ret;
}

std::vector<skilltree_node> parse_skilltree_line(std::ifstream& file)
{
	std::vector<skilltree_node> nodes;

	if(file.eof())
		return nodes;

	std::string line;
	size_t next;
	lvl_type level;

	do
	{
		if(file.eof())
			return nodes;
		std::getline(file, line);
	} while(line.size() == 0);

	try
	{
		level = std::stoi(line, &next, 0);
	} catch(...){
		std::cerr << "Level number out of range" << std::endl;
		std::abort();
	}

	if(line[next++] != ':')
	{
		std::cerr << "Expected ':', got " << line[next-1] << std::endl;
		std::abort();
	}


	auto branches = string_split(line.substr(next), '|');
	for(size_t i = 0; i < branches.size(); i++)
	{
		nodes.emplace_back();
		nodes.back().level = level;
		auto choices = string_split(branches[i], '~');
		for(size_t j = 0; j < choices.size(); j++)
		{
			nodes.back().skills.push_back(all_skills[choices[j]]);
		}

	}


	return nodes;
}

void print_skilltree(skilltree_node& root, int a = 0)
{
	for(auto i: root.skills)
	{
		std::cout << "current " << a << ": " << i().name << std::endl;
	}

	for(auto i: root.next)
	{
		std::cout << "children of " << a << ": " << std::endl;
		print_skilltree(i, a+1);
	}
}

static void parse_skilltree_sub(std::vector<skilltree_node*> last, std::ifstream& skilltree_file)
{
	if(skilltree_file.eof())
		return;

	size_t current_parent = 0;
	size_t left = last[current_parent]->skills.size();
	auto tmp = parse_skilltree_line(skilltree_file);
	for(skilltree_node& current_child: tmp)
	{
		if(left-- == 0)
		{
			current_parent++;
			left = last[current_parent]->skills.size();
		}
		last[current_parent]->next.push_back(std::move(current_child));
	}

	std::vector<skilltree_node*> current;
	for(auto old_node: last)
	{
		for(auto& new_node: old_node->next)
		{
			current.push_back(&new_node);
		}
	}

	parse_skilltree_sub(current, skilltree_file);

	return;
}
// TODO: add skilltree continuation, allow left skill skip (|Bash)
std::optional<skilltree_node> parse_skilltree(std::string filename)
{
	std::ifstream skilltree_file(filename);
	if(!skilltree_file.is_open())
		return std::nullopt;

	auto tmp = parse_skilltree_line(skilltree_file);
	if(tmp.size() != 1)
	{
		std::cerr << "Found multiple skill branches at root level" << std::endl;
		std::abort();
	}
	root = std::move(tmp[0]);
	std::vector<skilltree_node*> ptr;
	ptr.push_back(&root);
	parse_skilltree_sub(ptr, skilltree_file);

	return root;
}

void init_skilltrees()
{
	//TODO: actually walk through the config folder
	skilltrees["Warrior"] = *parse_skilltree(std::string(CONFIG_FOLDER)+std::string("skills/")+std::string("Warrior.skilltree"));
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
	return Skill("Defend", "defends", nullptr, SkillType::TARGETED);
}

constexpr Skill Skill::Taunt()
{
	return Skill("Taunt", "taunts", nullptr, SkillType::TARGETED);
}
