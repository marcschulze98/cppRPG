#include <cpprpg/classes/skills.hpp>
#include <cpprpg/characters/character.hpp>
#include <optional>
#include <stdexcept>

using namespace std;

map<string, Skill(*)()> all_skills;
map<string, skilltree_node> skilltrees;

skilltree_node root;


void init_skills()
{
	all_skills["Hit"] = Skill::Hit;
	all_skills["Bash"] = Skill::Bash;
	all_skills["Defend"] = Skill::Defend;
	all_skills["Taunt"] = Skill::Taunt;
}

static vector<string> string_split(const string str, char delim)
{
	vector<string> ret(1);
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

optional<vector<skilltree_node>> parse_skilltree_line(ifstream& file)
{
	vector<skilltree_node> nodes;

	if(file.eof())
		return nodes;

	string line;
	size_t next;
	lvl_type level;

	do
	{
		if(file.eof())
			return nodes;
		getline(file, line);
	} while(line.size() == 0);

	try
	{
		level = stoi(line, &next, 0);
	} catch(...){
		cerr << "Level number couldn't be parsed" << endl;
		return nullopt;
	}

	if(line[next++] != ':')
	{
		cerr << "Expected ':', got " << line[next-1] << endl;
		return nullopt;
	}


	auto branches = string_split(line.substr(next), '|');
	for(size_t i = 0; i < branches.size(); i++)
	{
		nodes.emplace_back();
		nodes.back().level = level;
		auto choices = string_split(branches[i], '~');
		for(size_t j = 0; j < choices.size(); j++)
		{
			if(all_skills.count(choices[j]) == 0)
			{
				nodes.back().skills.push_back(choices[j]);
			} else {
				nodes.back().skills.push_back(all_skills[choices[j]]);
			}
		}

	}


	return nodes;
}

void print_skilltree(skilltree_node& root, int a = 0)
{
	for(auto i: root.skills)
	{

		if(std::holds_alternative<skill_ptr>(i))
			cout << "current " << a << ": " << std::get<skill_ptr>(i)().name<< endl;
	}

	for(auto i: root.next)
	{
		cout << "children of " << a << ": " << endl;
		print_skilltree(i, a+1);
	}
}

static bool parse_skilltree_sub(vector<skilltree_node*> last, ifstream& skilltree_file)
{
	if(skilltree_file.eof())
		return true;;

	size_t current_parent = 0;
	size_t left = last[current_parent]->skills.size();
	auto tmp = parse_skilltree_line(skilltree_file);
	if(!tmp)
	{
		return false;
	}
	for(skilltree_node& current_child: *tmp)
	{
		if(left-- == 0)
		{
			current_parent++;
			if(current_parent >= last.size())
			{
				cout << "Too many branches, expected " << last.size() << " but got more" << endl;
				return false;
			}
			left = last[current_parent]->skills.size();
		}
		last[current_parent]->next.push_back(move(current_child));
	}

	vector<skilltree_node*> current;
	for(auto old_node: last)
	{
		for(auto& new_node: old_node->next)
		{
			current.push_back(&new_node);
		}
	}

	return parse_skilltree_sub(current, skilltree_file);
}
// TODO: add skilltree continuation, allow left skill skip (|Bash)
optional<skilltree_node> parse_skilltree(string filename)
{
	ifstream skilltree_file(filename);
	if(!skilltree_file.is_open())
	{
		cerr << "Couldn't open " << filename << endl;
		return nullopt;
	}

	auto tmp = parse_skilltree_line(skilltree_file);
	if(!tmp)
	{
		return nullopt;
	} else if(tmp->size() != 1) {
		cerr << "Found multiple skill branches at root level" << endl;
		return nullopt;
	}
	root = move(tmp->front());
	vector<skilltree_node*> ptr;
	ptr.push_back(&root);
	if(!parse_skilltree_sub(ptr, skilltree_file))
		return nullopt;

	return root;
}

void init_skilltrees()
{
	//TODO: actually walk through the config folder
	auto tmp = parse_skilltree(string(CONFIG_FOLDER)+string("skills/")+string("Warrior.skilltree"));
	if(!tmp)
	{
		cerr << "Failed to parse Warrior.skilltree" << endl;
		std::abort();
	}
	skilltrees["Warrior"] = *tmp;
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
