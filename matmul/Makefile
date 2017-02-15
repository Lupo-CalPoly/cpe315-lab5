CXX = g++
CXXFLAGS = -Wall -O2
CXXSRCS = matmul.cpp matmul-driver.cpp 
BIN = mm

all:
	$(CXX) $(CXXFLAGS) -c $(CXXSRCS)
	$(CXX) $(CXXFLAGS) -o $(BIN) *.o

clean:
	rm -f $(BIN) *.o
