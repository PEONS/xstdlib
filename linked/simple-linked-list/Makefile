CXX= gcc
CCFLAGS= -Wall -Werror -pedantic -ansi
INCLUDEDIR= -I. -I../../utils -I../../debug

all: test.out

test.out: ../../debug/debug.o SLL.o test.o
	$(CXX) $(CCFLAGS) -o $@ $^

SLL.o: SLL.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

test.o: test.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

clean:
	rm -irf *.o *~ *.out
