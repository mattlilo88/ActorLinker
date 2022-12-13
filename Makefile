CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = sixdegrees.o sixdegrees_functions.o

sixdegrees: $(OBJECTS)
		$(CXX) -g $(CXXFLAGS) -o $@ sixdegrees.o sixdegrees_functions.o

sixdegrees.o: sixdegrees.cpp sixdegrees.h sixdegrees_functions.cpp
		$(CXX) -g $(CXXFLAGS) -c sixdegrees.cpp

sixdegrees_functions.o: sixdegrees_functions.cpp sixdegrees.h
		$(CXX) -g $(CXXFLAGS) -c sixdegrees_functions.cpp

clean:
	rm *.o
	rm sixdegrees