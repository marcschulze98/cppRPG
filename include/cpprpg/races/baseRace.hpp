#ifndef CPPRPG_RACES_BASERACE
#define CPPRPG_RACES_BASERACE

#include <string>

#define DEFAULT_RACENAME "Raceless"
#define DEFAULT_CONSTITUTION_RACE 10
#define DEFAULT_STRENGTH_RACE 10
#define DEFAULT_INTELLIGENCE_RACE 10
#define DEFAULT_DEXTERITY_RACE 10
using attr_type = int;

class BaseRace
{
	public:
		constexpr static char racename[] = DEFAULT_RACENAME;
		constexpr static attr_type constitution = DEFAULT_CONSTITUTION_RACE;
		constexpr static attr_type strength = DEFAULT_STRENGTH_RACE;
		constexpr static attr_type intelligence = DEFAULT_INTELLIGENCE_RACE;
		constexpr static attr_type dexterity = DEFAULT_DEXTERITY_RACE;
};


class Human : public BaseRace
{
	public:
		constexpr static attr_type intelligence = DEFAULT_INTELLIGENCE_RACE + 2;
};


class Elf : public BaseRace
{
	public:
		constexpr static attr_type dexterity = DEFAULT_DEXTERITY_RACE + 2;
};


class Orc : public BaseRace
{
	public:
		constexpr static attr_type strength = DEFAULT_STRENGTH_RACE + 2;
};

#endif //CPPRPG_RACES_BASERACE
