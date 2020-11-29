OBJS	= getChar.o main.o Screen.o Worm.o
SOURCE	= getChar.cpp main.cpp Screen.cpp Worm.cpp
HEADER	= Cell.h getChar.hpp Screen.h Worm.h
OUT	= game.x
CC	 = g++
FLAGS	 = -g -c -gstabs -Wall
LFLAGS	 = -lcurses -ltermcap


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) 

getChar.o: getChar.cpp
	$(CC) $(FLAGS) getChar.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Screen.o: Screen.cpp
	$(CC) $(FLAGS) Screen.cpp 

Worm.o: Worm.cpp
	$(CC) $(FLAGS) Worm.cpp 


clean:
	rm -f $(OBJS) $(OUT)