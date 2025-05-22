COMPILER = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp \
	Brain.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Animal

all: $(NAME)
$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -o $@ $^
%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re