CXX = g++
CC = gcc
CFLAGS = -Wall -O2 -std=gnu11
CXXFLAGS = -Wall -O2
LDFLAGS = -lrt
CXXSRCS = matmul.cpp matmul-driver.cpp 
SRCS = hrt.c
BIN = mm

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $(CXXSRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRCS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(BIN) *.o

clean:
	rm -f $(BIN) *.o
