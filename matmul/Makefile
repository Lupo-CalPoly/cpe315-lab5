CXX = g++
CFLAGS = -Wall -O2
LDFLAGS = -lrt
SRCS = matmul.cpp matmul-driver.cpp hrt.c
BIN = mm

all:
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -f $(BIN)
