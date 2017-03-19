
CPP=g++
C=gcc

CFLAGS=-c -Wall -O3 -pthread -std=c++11


all: chess

chess: main.o picture.o mouse.o mice.o board.o ai.o move_gen.o pieces.o
	$(CPP) main.o picture.o mouse.o mice.o board.o ai.o move_gen.o pieces.o -o jht-chess -lncurses -std=c++11 -pthread -O3

main.o: main.cpp
	$(CPP) $(CFLAGS) main.cpp

pic.o: picture.cpp
	$(CPP) $(CFLAGS) picture.cpp -lncurses

board.o: board.cpp
	$(CPP) $(CFLAGS) board.cpp 

mouse.o: mouse.cpp
	$(CPP) $(CFLAGS) mouse.cpp 

mice.o: mice.c
	$(C) -c -Wall -O3  mice.c

ai.o: ai.cpp
	$(CPP) $(CFLAGS) ai.cpp

move_gen.o: move_gen.cpp
	$(CPP) $(CFLAGS) move_gen.cpp

pieces.o: pieces.cpp
	$(CPP) $(CFLAGS) pieces.cpp 


clean:
	rm jht-chess main.o picture.o mouse.o mice.o board.o ai.o move_gen.o pieces.o
