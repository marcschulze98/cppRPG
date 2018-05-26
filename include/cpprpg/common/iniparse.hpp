#ifndef CPPRPG_COMMON_INIPARSE_HPP
#define CPPRPG_COMMON_INIPARSE_HPP

#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>

using ini_kv = std::map<std::string, std::string>;
using ini_section =  std::map<std::string, ini_kv>;

static inline void string_strip(std::string& str, const char* chars)
{
	for (size_t i = 0; i < strlen(chars); ++i)
		str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
}


class ini_object
{
	private:
		void remove_comments(std::string& str)
		{
			for(size_t i = 0; i < str.length(); i++)
			{
				if(str[i] == ';')
					str.erase(i);
			}
		}
	public:
		ini_section section_kv;

		bool init(std::string filename)
		{
			section_kv.clear();
			std::ifstream ini_file(filename);

			if(!ini_file.is_open())
				return false;

			std::string current_section;
			while(!ini_file.eof())
			{
				std::string line;
				std::getline(ini_file, line);
				remove_comments(line);

				if(line.length() == 0)
				{
					continue;
				} else if(line.length() > 0 && line[0] == '[') {
					//section header
					string_strip(line, "[]");
					current_section = line;
					if(line.length() != 0)
						section_kv[line];
				} else {
					//kv pair
					if(current_section.length() == 0)
						continue;

					auto splitter = line.find("=");

					if(splitter == std::string::npos)
					{
						section_kv.erase(current_section);
						current_section = "";
						continue;
					}

					std::string key = line.substr(0, splitter);
					std::string val = line.substr(splitter+1);

					section_kv[current_section][key] = val;
				}

			}
			return true;
		}

		void print()
		{
			for(auto section = section_kv.cbegin(); section != section_kv.cend(); ++section)
			{
				std::cout << "[" << section->first << "]" << std::endl;
				for(auto pair = section->second.cbegin(); pair !=  section->second.cend(); ++pair)
				{
					std::cout << pair->first << "=" << pair->second << std::endl;
				}
			}
		}
};

#endif //CPPRPG_COMMON_INIPARSE_HPP
