words: words.o main.o
	g++ -g -Wall -o words words.o main.o

main.o: main.cpp words.h
	g++ -g -Wall -c  main.cpp

words.o: words.cpp words.h
	g++ -g -Wall -c words.cpp

clean:
	rm -f words.o main.o words