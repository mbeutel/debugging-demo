TARGET = scan
LIBS = -lm
CC = gcc
CXX = g++
CFLAGS = -g -Wall -Wextra -pedantic
CXXFLAGS = -g -Wall -Wextra -pedantic

.PHONY: default all clean

default: $(TARGET)
all: default

SOURCES = scan.c
OBJECTS = $(patsubst %.c, %.o, $(patsubst %.cpp, %.opp, $(SOURCES)))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.opp: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o *.opp
	-rm -f $(TARGET)
