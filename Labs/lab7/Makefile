NAME = minicp

CC = clang
OPT = -march=native -O2
VERSION = -std=c89
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS =
#REMOVE_WARN = -g
HEADERS =
LIBS =

INPUT = $(NAME).c

all: compiler

compiler:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(REMOVE_WARN) $(LIBS) -o $(OUTPUT) $(INPUT)
	@echo
	./$(OUTPUT) a.out new.out

clean:
	rm -rf $(OUTPUT) *.out
