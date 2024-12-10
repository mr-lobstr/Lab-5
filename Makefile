CC=g++
CFLAGS= -c -g -std=c++20
LDFLAGS= -lm

SOURCES=main.cpp \
		rnd.cpp \
		factory_method.cpp \
		./animal/animal.cpp \
		./animal/predator.cpp \
		./animal/victim.cpp \
		./animal/wolf.cpp \
		./animal/rabbit.cpp \


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(EXECUTABLE)
	find . -type f -name "*.o" -delete && clear

$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS)  $< -o $@ $(LDFLAGS)
