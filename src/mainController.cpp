#include <cpprpg/classes/baseClass.hpp>
#include <cpprpg/races/baseRace.hpp>
int main()
{
	BaseClass test;
	puts(test.skill_list[1].name);

	// doesn't compile:
	// test.skill_list[0].level++ <- tries to increment ro-object
	// solution: copy object

	Skill copied = test.skill_list[0];
	copied.level++;
	printf("%d\n",copied.level);
}
