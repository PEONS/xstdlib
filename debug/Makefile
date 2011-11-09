CXX= gcc
CCFLAGS= -Wall -Werror -pedantic -ansi
INCLUDEDIR= -I.

all: debug.o

debug.o: debug.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

clean:
	rm -irf *.o *~ *.out
