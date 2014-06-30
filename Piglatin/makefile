piglatin: piglatin.o main.o
	g++ -g -Wall -o piglatin piglatin.o main.o

main.o: main.cpp piglatin.h
	g++ -g -Wall -c main.cpp

piglatin.o: piglatin.cpp piglatin.h
	g++ -g -Wall -c piglatin.cpp

clean:
	rm -f main.o piglatin.o piglatin 