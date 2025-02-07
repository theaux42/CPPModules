COMPILER = c++
FLAGS = --std=c++98 -Werror -Wextra -Wall
OUT = main
FILES = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJECTS = $(FILES:.cpp=.o)

all: $(OUT)

$(OUT): $(OBJECTS)
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(OUT)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re