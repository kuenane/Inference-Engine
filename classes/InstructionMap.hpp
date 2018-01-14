/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionMap.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:00:43 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/25 08:53:12 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.hpp"

#pragma once

class InstructionMap
{
	public:
		InstructionMap(void) {
			//empty constructor
		}

		void	initMap(void)
		{
            fact['A'] = false;
            fact['B'] = false;
            fact['C'] = false;
            fact['D'] = false;
            fact['E'] = false;
            fact['F'] = false;
            fact['G'] = false;
            fact['H'] = false;
            fact['I'] = false;
            fact['G'] = false;
            fact['K'] = false;
            fact['L'] = false;
            fact['M'] = false;
            fact['N'] = false;
            fact['O'] = false;
            fact['P'] = false;
            fact['Q'] = false;
            fact['R'] = false;
            fact['S'] = false;
            fact['T'] = false;
            fact['U'] = false;
            fact['V'] = false;
            fact['W'] = false;
            fact['X'] = false;
            fact['Y'] = false;
            fact['Z'] = false;
		}

		void	setFact(const std::string& truefacts)
		{
			for (int i = 1; i < (int)truefacts.length(); i++)
				fact[truefacts[i]] = true;
		}

		void	setFact(char c)
		{
			fact[c] = true;
        }
        void	setundefFact(char c)
		{
			fact[c] = (-1);
		}

		void	unsetFact(char c)
		{
			fact[c] = false;
		}

		void	getQuery(const std::string& query)
		{
			if (query.length() > 1) {
				for (int i = 1; i < (int)query.length(); i++) {
					if (fact[query[i]] == true)
						PRINT BOLD MAGENTA <<query[i] <<RESET<< " is " << BOLD GREEN"true!"  END;
					else if (fact[query[i]] == false)
                        PRINT BOLD MAGENTA << query[i] <<RESET<<" is "<< BOLD RED"false!" END;
                    else
                        PRINT BOLD MAGENTA << query[i] <<RESET<<" is "<< BOLD RED"undefined!" END;   
                    }
			}
			else
				std::cout << "No queries found!" << std::endl;
		}
    
        void	findfacts(const std::vector<std::string>& strings)
        {
        
            int i = 0;
        
            while (i < (int)strings.size()) {
                if (strings[i][0] == '=') {
                    setFact(strings[i]);
                }
                i++;
            }
        }
    
        void	findquery(const std::vector<std::string>& strings)
        {
            int i = 0;
        
            while (i < (int)strings.size()) {
                if (strings[i][0] == '?') {
                    getQuery(strings[i]);
                }
                i++;
            }
        }
};
