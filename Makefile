all: main research tests clean

main: 
	g++ main.cpp -o main

research: 
	g++ research/research.cpp -o research
	
tests: 
	g++ tests/tests.cpp Node.o -o tests

clean:
	rm -f *.o