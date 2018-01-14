# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkuenane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 17:00:10 by lkuenane          #+#    #+#              #
#    Updated: 2018/01/14 17:00:13 by lkuenane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = expert-system

HDR = ./


SRC = main.cpp

FLAGS = -I $(HDR) -std=c++14 -Wall -Werror -Wextra -O2 -o $(NAME)

OPT = objs/

define p1
tput cuu 1
echo "                                                                         "
tput cuu 1
tput setaf 1
echo $1
tput sgr0
endef

define p2
tput cuu 1
echo "                                                                         "
tput cuu 1
tput setaf 3
echo $1
tput sgr0
endef

define p3
tput cuu 1
echo "                                                                         "
tput cuu 1
tput setaf 2
echo $1
tput sgr0
endef

define colourecho
tput blink
tput setaf 6
@echo $1
tput sgr0
endef

define colourecho1
tput setaf 6
@echo $1
tput sgr0
endef

define colourecho2
tput setaf 87
@echo $1
tput sgr0
endef

define green
tput setaf 2
@echo $1
tput sgr0
endef

define bar
echo $1
tput sgr0
endef

all: me
	@$(call colourecho2, "Compiling $(NAME):\n")
	@export CLICOLOR='1'
	@export TERM='xterm-256color'
	@rm -rf *.dSYM
	@g++ $(SRC) $(FLAGS)
	@$(MAKE) bar
	@$(call colourecho2, "Done Compiling!\n")

q: objs_dir
	@clear
	@export CLICOLOR='1'
	@export TERM='xterm-256color'
	@$(call colourecho2, "\nCompiling $(NAME):\n")
	@rm -rf *.dSYM
	@g++ $(SRC) $(FLAGS)
	@$(MAKE) bar
	@$(call colourecho2, "Done Compiling!\n")

clean:
	@/bin/rm -rf $(OPT)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf *.gch

re: fclean all

me: qme
	@$(call colourecho, "\n---------------------------")
	@$(call colourecho, "-----RUNNING MAKEFILE!-----")
	@$(call colourecho, "---------------------------\n")
	@sleep 1
	@clear
	@$(call colourecho1, "\n---------------------------")
	@$(call colourecho1, "-----RUNNING MAKEFILE!-----")
	@$(call colourecho1, "---------------------------\n")
	@$(call colourecho2, "Creating Author file:")
	@cat -e author
	@$(call colourecho2, "Author File Created!\n")

qme:
	@clear
	@if [ ! -f author ]; then \
		echo "zgodongw" >> author; \
		echo "lmakhath" >> author; \
		fi

objs_dir:
	@mkdir -p objs

val:
	@valgrind --leak-check=full ./$(NAME) && rm -rf *.dSYM

bar:
	@$(call p1, "\r[#                       ]")
	@sleep 0.1
	@$(call p1, "\r[##                      ]")
	@sleep 0.1
	@$(call p1, "\r[###                     ]")
	@sleep 0.1
	@$(call p1, "\r[####                    ]")
	@sleep 0.1
	@$(call p1, "\r[#####                   ]")
	@sleep 0.1
	@$(call p1, "\r[######                  ]")
	@sleep 0.1
	@$(call p1, "\r[#######                 ]")
	@sleep 0.1
	@$(call p1, "\r[########                ]")
	@sleep 0.1
	@$(call p1, "\r[#########               ]")
	@sleep 0.1
	@$(call p1, "\r[##########              ]")
	@sleep 0.1
	@$(call p2, "\r[###########             ]")
	@sleep 0.1
	@$(call p2, "\r[############            ]")
	@sleep 0.1
	@$(call p2, "\r[#############           ]")
	@sleep 0.1
	@$(call p2, "\r[##############          ]")
	@sleep 0.1
	@$(call p2, "\r[###############         ]")
	@sleep 0.1
	@$(call p2, "\r[################        ]")
	@sleep 0.1
	@$(call p2, "\r[#################       ]")
	@sleep 0.1
	@$(call p2, "\r[##################      ]")
	@sleep 0.1
	@$(call p2, "\r[###################     ]")
	@sleep 0.1
	@$(call p3, "\r[####################    ]")
	@sleep 0.1
	@$(call p3, "\r[#####################   ]")
	@sleep 0.1
	@$(call p3, "\r[######################  ]")
	@sleep 0.1
	@$(call p3, "\r[####################### ]")
	@sleep 0.1
	@$(call p3, "\r[########################]")

1:
	@./$(NAME) ./tests/ex1.txt
2:
	@./$(NAME) ./tests/ex2.txt
3:
	@./$(NAME) ./tests/ex3.txt
4:
	@./$(NAME) ./tests/ex4.txt
5:
	@./$(NAME) ./tests/ex5.txt
6:
	@./$(NAME) ./tests/ex6.txt
7:
	@./$(NAME) ./tests/test.txt
8:
	@./$(NAME) ./tests/test1.txt
9:
	@./$(NAME) ./tests/test2.txt
sim:
	@./$(NAME) ./tests/simple.txt
b:
	@./$(NAME) ./tests/blocktest.txt

