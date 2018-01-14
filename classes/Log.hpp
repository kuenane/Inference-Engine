
#include "../main.hpp"

#pragma once

class Log {
	public:
		Log () {
			//empty constructor
		}
		
		void println(const std::string& string)
		{
			std::cout << string << std::endl;
		}
		
		void printchar(const char c)
		{
			std::cout << c << std::endl;
		}
		
		void printint(int c)
		{
			std::cout << c << std::endl;
		}
		
		void printbool(bool c)
		{
			if (c == true)
				std::cout << "true" << std::endl;
			else
				std::cout << "false" << std::endl;
		}

		void printvec(const std::vector<std::string>& c)
		{
			for (int i = 0; i < (int)c.size(); i++) {
				std::cout << "block "<< i << " : "<< c[i] << std::endl;
		}
	}
};
