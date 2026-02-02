COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp MutantStack.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = MutantStack 

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