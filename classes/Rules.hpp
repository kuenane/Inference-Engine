
#include "../main.hpp"

#pragma once

class Rules : public Setup {
	public:
		Rules(void) {
			//empty constructor
		}

	private:

		std::vector<std::string>			splitstr(const std::string& str, char c)
		{
			int								i = 0;
			bool							open = false;
			bool 							close = false;
			std::vector<std::string>		strarray;

			while (i < (int)str.length()) {
				std::string					strdup;
				while (str[i]) {
					if (str[i] == '<' || str[i] == '=')
						close = true;
					if (str[i] == '(') {
						open = true;
						if (c == '+')
							i++;
					}
					else if (str[i] == ')') {
						open = false;
						if (c == '+')
							i++;
					}
					if (str[i] != c && open == false && close == false)
						strdup += str[i];
					else if (open == true && close == false)
						strdup += str[i];
					else
						break ;
					i++;
				}
				if (!strdup.empty())
					strarray.emplace_back(strdup);
				i++;
			}
			return strarray;
		}

		bool								evalXORblock(const std::string& line)
		{
			std::map<int, bool>				block;
			std::vector<std::string>		strblock;

			strblock = splitstr(line, '^');
			for (int i = 0; i < (int)strblock.size(); i++) {
				block[i] = evalORblock(strblock[i]);
			}
			if (solveBlocks(block, '^') == true)
				return true;
			return false;
		}

		bool								evalORblock(const std::string& line)
		{
			std::map<int, bool>				block;
			std::vector<std::string>		strblock;

			strblock = splitstr(line, '|');
			for (int i = 0; i < (int)strblock.size(); i++) {
				block[i] = evalANDBlock(strblock[i]);
			}
			if (solveBlocks(block, '|') == true)
				return true;
			return false;
		}

		bool 								evalANDBlock(const std::string& line)
		{
			std::vector<std::string>		strblock;
			std::map<int, bool>				block;
			std::string						str;

			strblock = splitstr(line, '+');
			for  (long i = 0; i < (long)strblock.size(); i++) {
				str = strblock[i];
				if (str.length() == 1 && fact[str[0]] == 1) {
					block[i] = true;
				}
				else if (str.length() == 1 && fact[str[0]] == 0) {
					block[i] = false;
				}
				else if (str.length() == 1 && fact[str[0]] == -1) {
					block[i] = false;
				}
				else if (str.length() == 2 && str[0] == '!') {
					if (fact[str[1]] == false)
						block[i] = true;
					else
						block[i] = false;
				}

				if (str.length() > 2 && str[0] != '?') {
					if (evalXORblock(str)) {
						block[i] = true;
					}
					else {
						block[i] = false;
					}
				}
			}
			if (solveBlocks(block, '+') == true)
				return true;
			return false;
		}

		bool								solveBlocks(std::map<int, bool>& block, char c)
		{
			if (c == '^') {
				if (block.size() > 2)
					return false;
				else if (block.size() == 2) {
					if ((block[0] == true && block[1] == false))
						return true;
					if ((block[0] == false && block[1] == 1))
						return true;
				}
				else if (block.size() < 2 && block[0] == true)
					return true;
				return false;
			}

			if (c == '|') {
				for (int i = 0; i < (int)block.size(); i++) {
					if (block[i] == true)
						return true;
				}
				return false;
			}

			if (c == '+') {
				for(int i = 0; i < (int)block.size(); i++) {
					if (block[i] == false)
						return false;
				}
				return true;
			}
			return false;
		}

		void								setConclusions(const std::string& string)
		{
			int								i = 0;
			std::string						cstr;
			std::vector<std::string>		substr;

			while (string[i] != '>' && i < (int)string.length())
				i++;

			cstr = &string[++i];

			if (cstr.find("|") == std::string::npos) {
				substr = splitstr(cstr, '+');

				for (int j = 0; j < (int)substr.size(); j++) {
					cstr = substr[j];
					for (int k = 0; k < (int)cstr.length(); k++) {
						if (isalpha(cstr[k]) && cstr.length() == 2)
							unsetFact(cstr[k]);
						else if (isalpha(cstr[k]) && (cstr.length() == 1 || cstr.length() > 2))
							setFact(cstr[k]);
					}
				}
			}
			else {
				for (int k = 0; k < (int)cstr.length(); k++) {
					if (isalpha(cstr[k]))
						if (fact[cstr[k]] != 1)
							setundefFact(cstr[k]);
				}
			}

		}

	public:
		std::vector<std::string>			getRules(const std::vector<std::string>& strings)
		{
			std::vector<std::string>		rule;

			for (int i = 0; i < (int)strings.size(); i++) {
				if (strings[i][0] != '?' && strings[i][0] != '=')
					rule.emplace_back(strings[i]);
			}
			return (rule);
		}

		void								Programloop(const std::vector<std::string>& strings)
		{
			int 							ruleamount;
			std::vector<std::string>		rules;

			rules = getRules(strings);
			ruleamount = (int)rules.size();
			for (int k = 0; k < ruleamount; k++) {
				for (int j = 0; j < ruleamount; j++) {
					if (evalXORblock(rules[j]) == true)
						setConclusions(strings[j]);
				}
			}
		}
};
