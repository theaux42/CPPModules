COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror 
FILES = main.cpp Harl.cpp
OUT = Harl

all:
	$(COMPILER) $(FLAGS) $(FILES) -o $(OUT)

clean:
	rm -f $(OUT)

re: clean all

.PHONY: all clean re