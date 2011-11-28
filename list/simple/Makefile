CXX= gcc
CCFLAGS= -Wall -Werror -pedantic -ansi
INCLUDEDIR= -I. -I../../utils -I../../debug
LIBDIR= -L. -L./lib

SCRIPTDIR=.
SCRIPTFILE=sh_lib.sh

all: test.out

lib: ./lib/libSLL.so

test.out: ../../debug/debug.o ./lib/libSLL.so test.o
	$(CXX) $(CCFLAGS) $(LIBDIR) -o $@ $^ -lSLL
	sh $(SCRIPTDIR)/$(SCRIPTFILE)

./lib/libSLL.so: SLL.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) $< -o $@ -shared -fpic

test.o: test.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

clean:
	rm -irf *.o *~ *.out *.so ./lib/*.so
