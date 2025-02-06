COMPILER = c++
FLAGS = --std=c++98 -Werror -Wextra -Wall
OUT = main
FILES = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

all:
	$(COMPILER) $(FLAGS) $(FILES) -o $(OUT)

clean:
	rm -f $(OUT)

re: clean all

.PHONY: all clean re