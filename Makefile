
# Folder
SRCDIR :=src
TESTDIR :=test
BUILDDIR :=build
TARGETDIR :=dist

TARGET := converter
TARGET_TEST := test
#TARGET_DOCS := doc
	


# Shared Compiler Flags
# Code Lists
SRCEXT := cpp

# Shared Compiler Flags
INC :=  -I/usr/include/cppunit
# INC := -I/usr/include/cppunit
LIB :=  -L /usr/lib -l cppunit 

CC := g++ 
CFLAGS :=-std=c++14 -Wall -Werror 

all: $(TARGET) $(TARGET_TEST)	
	
	
$(TARGET):converter.o units.o
	$(CC) $(CFLAGS) $^ -o $(TARGET) 
	
$(TARGET_TEST):units.o test.o testrunner.o
	 $(CC) $(CFLAGS)  $^ -o $(TARGET_TEST) $(LIB)
	
units.o: units.cpp units.h
	 $(CC) $(CFLAGS) -c -o $@ $<
	
converter.o: converter.cpp units.h
	 $(CC) $(CFLAGS) -c -o $@ $<
	
	
test.o:test.cpp test.h
	$(CC)  $(CFLAGS) $(INC) -c -o $@ $<

testrunner.o:testrunner.cpp test.h
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f *.o $(TARGET) $(TARGET_TEST)
	
fresh: clean all

.PHONY: clean