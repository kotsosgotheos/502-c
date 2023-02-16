NAME = merge

CC = clang
OPT = -march=native -O2
VERSION = -std=c89
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-format-pedantic -Wno-unused-label
REMOVE_WARN = -g
HEADERS =
LIBS =

INPUT = $(NAME).c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(REMOVE_WARN) $(LIBS) -o $(OUTPUT) $(INPUT)
	@echo
	./$(OUTPUT)

clean:
	rm -rf $(OUTPUT)
