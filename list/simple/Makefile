CXX= gcc
CCFLAGS= -Wall -Werror -pedantic -ansi

DEBUG= ../../debug
UTILS= ../../utils

INCLUDEDIR= -I. -I$(UTILS) -I$(DEBUG)
LIB= ./lib
LIBDIR= -L$(LIB)

TARGET= test.out

SOURCES= test
OBJECTSFILES= $(SOURCES:=.o)

all: $(TARGET)

lib: $(LIB)/libSLL.so

$(TARGET): $(DEBUG)/debug.o $(LIB)/libSLL.so $(OBJECTSFILES)
	$(CXX) $(CCFLAGS) $(LIBDIR) -o $@ $^ -lSLL

$(LIB)/libSLL.so: SLL.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) $< -o $@ -shared -fpic

%.o: %.c
	$(CXX) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

clean:
	rm -irf *.o *~ *.out
