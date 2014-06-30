codex: codex.o main.o
	g++ -Wall -g -o codex codex.o main.o

main.o: main.cpp codex.h
	g++ -Wall -g -c main.cpp 

codex.o: codex.cpp codex.h
	g++ -Wall -g -c codex.cpp

clean:
	rm - f codex.o codex