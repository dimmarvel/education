
CC=g++
CXXFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp widget.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@
	
clean:
	rm -rf *.o full_out