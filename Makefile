# Edit this line to change the optimization level
CXXFLAGS = -g -Wall -O0
CXX = g++
CXXSRCS = matmul.cpp matmul-driver.cpp 
COL_CXXSRCS = matmul-column-maj.cpp matmul-driver.cpp 
UNROLL_CXXSRCS = matmul-unrolled.cpp matmul-driver.cpp 
COLUNROLL_CXXSRCS = matmul-col-unrolled.cpp matmul-driver.cpp 
BIN = mm mm-col mm-unrolled mm-col-unrolled

all: $(BIN)

mm: $(patsubst %.cpp,%.o,$(CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

mm-col: $(patsubst %.cpp,%.o,$(COL_CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

mm-unrolled: $(patsubst %.cpp,%.o,$(UNROLL_CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

mm-col-unrolled: $(patsubst %.cpp,%.o,$(COLUNROLL_CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f *.o $(BIN)
