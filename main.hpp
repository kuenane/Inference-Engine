

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include <cstdlib>
# include <cstdio>
#include <unistd.h>
# include <map>

# define CLEAR	    	"\33[H\33[2J"
# define RED	    	"\x1b[31m"
# define GREY	    	"\x1b[37m"
# define GREEN	    	"\x1b[32m"
# define YELLOW	    	"\x1b[33m"
# define BLUE	    	"\x1b[34m"
# define LBLUE	    	"\x1b[36m"
# define MAGENTA    	"\x1b[35m"
# define CYAN	    	"\033[0;36m"
# define RESET		    "\x1b[0m"
# define BOLD		    "\033[1m"
# define LPURP		    "\x1b[1;35m"

# define PRINT		    std::cout<<
# define END		    <<RESET<<std::endl

std::map<char, int>    fact;

# include "classes/Log.hpp"
# include "classes/InstructionMap.hpp"
# include "classes/Setup.hpp"
# include "classes/Rules.hpp"
# include "classes/Error.hpp"
# include "classes/TermUI.hpp"

#endif