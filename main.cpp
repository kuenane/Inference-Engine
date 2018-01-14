/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:10:05 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/28 12:20:50 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int										main(int argc, char *argv[])
{
	Setup*								s = new Setup();
	InstructionMap*	 					map = new InstructionMap();
	Rules*								rule = new Rules();
	Error*								error = new Error();
	TermUI*								ui = new TermUI();
	std::vector<std::string>			rulearray;
	PRINT CLEAR;

	if (argc < 2) {
		PRINT BOLD RED "No text input: "<<RESET BOLD<<"Exiting" END;
	}
	else {
		rulearray = s->start((std::string)argv[1], false);
	}

	map->initMap();
	if (!rulearray.empty()) {
		if (error->errorCheck(rulearray) == false) {
			map->findfacts(rulearray);
    
			rule->Programloop(rulearray);

	
			map->findquery(rulearray);
		
		}
	}

	delete s;
	delete map;
	delete rule;
	delete error;
	delete ui;

	return (0);
}
