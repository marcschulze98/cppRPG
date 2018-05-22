#ifndef CPPRPG_CLASSES_SKILLS
#define CPPRPG_CLASSES_SKILLS

#include <cstdio>

enum class SkillType {SELF, TARGETED, AREA};

struct skill_arg
{

};
// to be able to put skills in arrays they need to be the same type,
// so just make different constructors of Skill for different skills
class Skill
{
	private:
	public:
		constexpr Skill(const char* name, const char* description, void (*use_skill)(skill_arg arg), SkillType type):
		name(name), description(description), use_skill(use_skill), type(type) {}

		const char* name;
		const char* description;
		int level = 0;
		void (*use_skill)(skill_arg arg);
		SkillType type;


		constexpr static Skill FistAttack()
		{
			return Skill("Punch", "Inflicts basic attack damage to an enemy", nullptr, SkillType::TARGETED);
		}

		constexpr static Skill Bash()
		{
			return Skill("Bash", "Inflicts 2 * basic attack damage to an enemy", nullptr, SkillType::TARGETED);
		}

		void operator()(skill_arg arg)
		{
			use_skill(arg);
		}
};

#endif // CPPRPG_CLASSES_SKILLS
