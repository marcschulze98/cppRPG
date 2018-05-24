#ifndef CPPRPG_RACES_BASERACE
#define CPPRPG_RACES_BASERACE

#include <string>

#define DEFAULT_CONSTITUTION_RACE 10
#define DEFAULT_STRENGTH_RACE 10
#define DEFAULT_INTELLIGENCE_RACE 10
#define DEFAULT_DEXTERITY_RACE 10
#define DEFAULT_INITIATIVE_RACE 10
using attr_type = int;

class CharacterRace
{
	public:
		const std::string name;
		attr_type constitution;
		attr_type strength;
		attr_type intelligence;
		attr_type dexterity;
		attr_type initiative;

		CharacterRace(const std::string racename):
			name(racename),
			constitution(DEFAULT_CONSTITUTION_RACE),
			strength(DEFAULT_STRENGTH_RACE),
			intelligence(DEFAULT_INTELLIGENCE_RACE),
			dexterity(DEFAULT_DEXTERITY_RACE),
			initiative(DEFAULT_INITIATIVE_RACE){}
};

#endif //CPPRPG_RACES_BASERACE
