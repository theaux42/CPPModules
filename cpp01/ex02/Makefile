COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
OUTPUT = main

all:
	$(COMPILER) $(FLAGS) $(SRCS) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

re: clean all

.PHONY: all clean re
