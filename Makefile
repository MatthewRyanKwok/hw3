CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

OBJS := llrec.o llrec-test.o

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o llrec-test $(OBJS)

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 