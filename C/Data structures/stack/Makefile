all:
	gcc -O0 -g -Wall -Wno-unused-function main.c stack.c tests.c -o run && ./run

test-leak:
	valgrind --leak-check=full -s ./run
