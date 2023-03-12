all:
	gcc -O0 -g -Wall main.c array.c tests.c -o run && ./run

test-leak:
	valgrind --leak-check=full -s ./run
	