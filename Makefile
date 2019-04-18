CXXFLAGS= -Wall -Wextra -O0 -g



main: string.o main.o 
	g++ -o main string.o main.o 

string.o: string.cpp string.h
	g++ -o string.o -c ${CXXFLAGS} string.cpp 

main.o: main.cpp string.h
	g++ -o main.o -c ${CXXFLAGS} main.cpp 
	
	
clean:
	rm main.o string.o main
