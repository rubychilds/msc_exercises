braille: braille.o main.o	
	g++ -g -Wall -o braille braille.o main.o

main.o: main.cpp braille.h
	g++ -g -Wall -c main.cpp

braille.o: braille.cpp braille.h
	g++ -g -Wall -c braille.cpp

clean:
	rm -f braille.o main.o braille 