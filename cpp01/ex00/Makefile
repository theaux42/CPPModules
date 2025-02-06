COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror 
FILES = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OUT = zombie

all:
	$(COMPILER) $(FLAGS) $(FILES) -o $(OUT)

clean:
	rm -f $(OUT)

re: clean all

.PHONY: all clean re