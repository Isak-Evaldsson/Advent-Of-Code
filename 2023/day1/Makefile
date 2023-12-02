.PHONY: all task1 task2 clean

CC=clang++
CXX=-I../common -g -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer

src=\
	main.cpp \
	../common/AdventOfCodeRunner.cpp \

a.out:
	$(CC) $(src) $(CXX)

task1: a.out
	./a.out 1 task1

task2: a.out
	./a.out 2 task2

all: a.out
	./a.out 0 input

clean:
	rm a.out