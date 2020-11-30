game.x:  main.o Screen.o Screen.o Worm.o getChar.o
	g++ -ggdb -o game.x main.o Screen.o Worm.o getChar.o -lcurses -ltermcap

main.o:	main.cpp Screen.h Cell.h Worm.h
	g++ -c -ggdb main.cpp -o main.o

Screen.o: Screen.cpp
	g++ -c -ggdb Screen.cpp -o Screen.o

Worm.o: Worm.cpp Cell.h
	g++ -c -ggdb Worm.cpp -o Worm.o

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o

clean:
	/bin/rm -f game.x Screen.o main.o Cell.o Worm.o getChar.o *~
	