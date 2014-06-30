multitap: multitap.o main.o	
	g++ -g -Wall -o multitap multitap.o main.o

main.o: main.cpp multitap.h
	g++ -g -Wall -c main.cpp

multitap.o: multitap.cpp multitap.h
	g++ -g -Wall -c multitap.cpp

clean:
	rm -f multitap.o main.o multitap   