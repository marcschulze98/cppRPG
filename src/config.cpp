#include <cpprpg/common/config.hpp>

ini_object class_ini;
ini_object race_ini;


void init_class_ini()
{
	class_ini.init(std::string(CONFIG_FOLDER)+std::string("classes/")+std::string("baseClasses.ini"));
}

void init_race_ini()
{
	race_ini.init(std::string(CONFIG_FOLDER)+std::string("races/")+std::string("baseRaces.ini"));
}
