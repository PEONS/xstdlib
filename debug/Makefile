CXX= gcc
CCFLAGS= -Wall -Werror -pedantic -ansi

INCLUDEDIR= -I. -I../utils -I../list/simple

TARGET= debug.o

SOURCES= debug
OBJECTSFILES= $(SOURCES:=.o)

all: $(TARGET)

%.o: %.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

clean:
	rm -irf *.o *~ *.out
