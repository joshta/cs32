CC=g++
CFLAGS=-g
all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))
%.out: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@ -lm
clean:
	rm *.out         
