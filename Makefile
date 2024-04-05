COMPILER = g++
CFLAGS = -c -Wall
WINFLAGS = -lfltk -lX11

ALL = main.o \
	Math_vector.o \
	Painter.o \
	Particle.o \
	Circle.o \
	System.o \
	Simulator.o

all: ./a.out

./a.out: $(ALL)
	$(COMPILER) $(ALL) $(WINFLAGS)

main.o: main.cpp
	$(COMPILER) $(CFLAGS) main.cpp

Math_vector.o: Math_vector.cpp
	$(COMPILER) $(CFLAGS) Math_vector.cpp

Painter.o: Painter.cpp
	$(COMPILER) $(CFLAGS) Painter.cpp

Particle.o: Particle.cpp
	$(COMPILER) $(CFLAGS) Particle.cpp

Circle.o: Circle.cpp
	$(COMPILER) $(CFLAGS) Circle.cpp

System.o: System.cpp
	$(COMPILER) $(CFLAGS) System.cpp

Simulator.o: Simulator.cpp
	$(COMPILER) $(CFLAGS) Simulator.cpp



clear:
	rm *.o a.out