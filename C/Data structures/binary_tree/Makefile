all:
	gcc -O0 -g -Wall -Wno-unused-function main.c binary_tree.c tests.c -o run && ./run

test-leak:
	valgrind --leak-check=full --track-origins=yes -s ./run
