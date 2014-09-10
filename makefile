# Define the compiler
CC=g++
# Define the compiler options
CFLAGS=-O2
# Define the linker
LINK=g++
# Define the dependencies

all: SortAutoData

# Define the dependencies
SortAutoData: SortAutoData.o
	$(LINK) -o SortAutoData SortAutoData.o  
SortAutoData.o: SortAutoData.cpp Brick.h QuickSort.h Bubble.h AutoData.h
	$(CC) -c $(CFLAGS) -std=c++0x SortAutoData.cpp

clean:
	/bin/rm -f SortAutoData SortAutoData.o
