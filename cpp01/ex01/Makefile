COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror 
FILES = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(FILES:.cpp=.o)
OUT = zombie

all: $(OUT)

$(OUT): $(OBJ)
	$(COMPILER) $(FLAGS) $(OBJ) -o $(OUT)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re