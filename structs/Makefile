CXX = g++
CXXFLAGS = -Wall -O2
CXXSRCS = structs.cpp 
BIN = computeavg 

all:
	$(CXX) $(CXXFLAGS) -c $(CXXSRCS)
	$(CXX) $(CXXFLAGS) -o $(BIN) *.o

clean:
	rm -f $(BIN) *.o
