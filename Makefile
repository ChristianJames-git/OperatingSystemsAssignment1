# CXX Make variable for compiler
CXX=g++
# Make variable for compiler options
#	-std=c++11  C/C++ variant to use, e.g. C++ 2011
#	-g          include information for symbolic debugger e.g. gdb
CXXFLAGS=-std=c++11 -g

# Rules format:
# target : dependency1 dependency2 ... dependencyN
#     Command to make target, uses default rules if not specified

# First target is the one executed if you just type make
# make target specifies a specific target
# $^ is an example of a special variable.  It substitutes all dependencies
countwords : main.o dictionary.o dictNode.o
	$(CXX) $(CXXFLAGS) -o countwords $^

main.o : dictionary.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

dictionary.o : dictionary.h dictionary.cpp
	$(CXX) $(CXXFLAGS) -c dictionary.cpp

dictNode.o : dictNode.h dictNode.cpp
	$(CXX) $(CXXFLAGS) -c dictNode.cpp


clean :
	rm *.o