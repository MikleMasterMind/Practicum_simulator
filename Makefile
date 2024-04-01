COMPILER = g++
FLAGS = -c -Wall

all: main

main: main.o Math_vector.o
	$(COMPILER) -o main main.o Math_vector.o

main.o: main.cpp
	$(COMPILER) $(FLAGS) main.cpp

Math_vector.o: Math_vector.cpp
	$(COMPILER) $(FLAGS) Math_vector.cpp

clear:
	rm *.o main