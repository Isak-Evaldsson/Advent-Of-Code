.PHONY: all task1 task2 clean

CC=clang++
CXX=-I../common -g -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer

src=\
	main.cpp \
	../common/string_functions.cpp \
	../common/AdventOfCodeRunner.cpp \

a.out: $(src)
	$(CC) $(src) $(CXX)

task1: a.out
	./a.out 1 test

task2: a.out
	./a.out 2 test

all: a.out
	./a.out 0 input

clean:
	rm a.out