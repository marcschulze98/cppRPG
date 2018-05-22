#ifndef CPPRPG_CLASSES_SKILLS
#define CPPRPG_CLASSES_SKILLS

#include <cstdio>

class Skill
{
	Skill() = delete;
};

class FistAttack: public Skill
{
	public:
		constexpr static char skillname[] = "Punch";
		FistAttack()
		{
			puts("PUNCH!");
		}
};

#endif // CPPRPG_CLASSES_SKILLS
