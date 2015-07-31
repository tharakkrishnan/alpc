CC=g++
INCLUDES=codec.h
SOURCES=codec.cpp encoder.cpp decoder.cpp
CFLAGS=-c -Wall -I$(INCLUDES)
LDFLAGS= -I$(INCLUDES)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= bit14encoder bit14decoder


all: $(SOURCES) $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

bit14encoder: encoder.o codec.o
	$(CC) $(LDFLAGS) encoder.o codec.o -o $@

bit14decoder: decoder.o codec.o
	$(CC) $(LDFLAGS) decoder.o codec.o -o $@


clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

package: 
	cd ..; tar -cvzf alpc.tgz alpc
