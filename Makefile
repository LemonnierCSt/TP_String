CXXFLAGS= -Wall -O0 -g



main: String.o main.o 
	g++ -o main String.o main.o 

String.o: String.cpp String.h
	g++ -o String.o -c ${CXXFLAGS} String.cpp 

main.o: main.cpp String.h
	g++ -o main.o -c ${CXXFLAGS} main.cpp 
	
	
clean:
	rm main.o String.o main
