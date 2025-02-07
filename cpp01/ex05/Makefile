COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror 
FILES = main.cpp Harl.cpp
OBJS = $(FILES:.cpp=.o)
OUT = Harl

all: $(OUT)

$(OUT): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(OUT)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re