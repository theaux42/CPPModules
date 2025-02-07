COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
OUTPUT = main

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(OUTPUT)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re