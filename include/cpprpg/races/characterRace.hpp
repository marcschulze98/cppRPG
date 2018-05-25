#ifndef CPPRPG_RACES_BASERACE
#define CPPRPG_RACES_BASERACE

#include <string>
#include <cpprpg/common/config.hpp>

#define DEFAULT_CONSTITUTION_RACE 10
#define DEFAULT_STRENGTH_RACE 10
#define DEFAULT_INTELLIGENCE_RACE 10
#define DEFAULT_DEXTERITY_RACE 10
#define DEFAULT_INITIATIVE_RACE 10

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
			initiative(DEFAULT_INITIATIVE_RACE)
		{
			auto section = race_ini.section_kv[racename];

			try
			{
				constitution += std::stoi(section["constitution"], nullptr, 0);
			} catch (...){}
			try
			{
				strength += std::stoi(section["strength"], nullptr, 0);
			} catch (...){}
			try
			{
				dexterity += std::stoi(section["dexterity"], nullptr, 0);
			} catch (...){}
			try
			{
				intelligence += std::stoi(section["intelligence"], nullptr, 0);
			} catch (...){}
			try
			{
				initiative += std::stoi(section["initiative"], nullptr, 0);
			} catch (...){}

		}
};

#endif //CPPRPG_RACES_BASERACE
