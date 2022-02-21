all: a.out

a.out:
	g++ -std=c++17 ./Routines/task3/routine.cpp ./Routines/catch/catch.hpp  ./Routines/catch/testlib.cpp functions.cpp   -I./

test: a.out
	./a.out

clean:
	rm a.out
