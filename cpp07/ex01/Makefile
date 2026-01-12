COMPILER = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = program

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