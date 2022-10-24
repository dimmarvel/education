all: full

full: main.o widget.o
	g++ main.o widget.o -o full_out

main.o: main.cpp
	g++ -c main.cpp

widget.o: widget.cpp
	g++ -c widget.cpp

clean:
	rm -rf *.o full_out