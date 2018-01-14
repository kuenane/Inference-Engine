
#include "../main.hpp"

#pragma once

class Setup : public InstructionMap {
	public:

		Setup(void) {
			//empty constructor	
		}

	private:

		bool						isValid(const char c)
		{
			if ((c >= 'A' && c <= 'Z') || c == '+'
					|| c == '|' || c == '?' || c == '<' || c == '>'
					|| c == '!' || c == '^' || c == '=' || c == '('
					|| c == ')') {
				return true;
			}
			return false;
		}
		
		std::string					instructions(const std::string& line, bool val)
		{
			std::string				linedup;

			for (int i = 0; i < (int)line.length(); i++) {
				if (line[i] == '#')
					break ;
				if (isValid(line[i]))
					linedup += line[i];
			}
			if (linedup.find("<") != std::string::npos && val == false)
				linedup = setONLYif(linedup);
			return (linedup);
		}

		std::string					setONLYif(const std::string& str)
		{
			int						i = 0;
			std::string				line;

			while (str[i] != '>')
				i++;
			line = &str[++i];
			line += "=>";
			i = 0;
			while (str[i] != '<') {
				line += str[i];
				i++;
			}
			return line;
		}

	public:

		std::vector<std::string>		start(const std::string& argv, bool val)
		{
			std::ifstream				file;
			
			file.open(argv);
			if (file.fail()) {
				PRINT RED BOLD "Error: "<<RESET BOLD<<"could not open file!" END;
				return std::vector<std::string>();
			}
			
			std::string line;
			std::vector<std::string> stringarray;

			while (!file.eof()) {
				std::getline(file, line);
				line = instructions(line, val);
				if (!line.empty())
					stringarray.emplace_back(line); //use emplace_back and compile with -std=c++14
			}
			file.close();
			return stringarray;
		}
};
