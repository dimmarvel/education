
CC=g++
CXXFLAGS=-c -Wall

all: full

full: main.o widget.o
	$(CC) main.o widget.o -o full_out

main.o: main.cpp
	$(CC) $(CXXFLAGS) main.cpp

widget.o: widget.cpp
	$(CC) $(CXXFLAGS) widget.cpp

clean:
	rm -rf *.o full_out