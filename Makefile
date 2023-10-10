all: main research test clean

main: 
	g++ main.cpp -o main

research: 
	g++ research/research.cpp -o research
	
test: 
	g++ tests/test.cpp Node.o -o test

clean:
	rm -f *.o