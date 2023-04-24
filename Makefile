CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: main

main: main.o functions.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp functions.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

functions.o: functions.cpp functions.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main *.o



