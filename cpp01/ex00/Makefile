COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror 
FILES = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJECTS = $(FILES:.cpp=.o)
OUT = zombie

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

.PHONY: all clean fclean ree