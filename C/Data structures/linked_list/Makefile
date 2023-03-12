all:
	gcc -O0 -g -Wall -Wno-unused-function main.c linked_list.c tests.c -o run && ./run

test-leak:
	valgrind --leak-check=full --track-origins=yes -s ./run
