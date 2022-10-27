# Edit this line to change the optimization level
CXXFLAGS = -g -Wall -O0
CXX = g++
CXXSRCS = matmul.cpp matmul-driver.cpp 
BIN = mm

all:
	$(CXX) $(CXXFLAGS) -c $(CXXSRCS)
	$(CXX) $(CXXFLAGS) -o $(BIN) *.o

clean:
	rm -f *.o $(BIN)
