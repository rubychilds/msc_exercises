string: string.o main.o
	g++ -g -Wall -o string string.o main.o

main.o: main.cpp string.h
	g++ -g -Wall -c main.cpp

string.o: string.cpp string.h
	g++ -g -Wall -c string.cpp

clean:
	rm -f string.o main.o string