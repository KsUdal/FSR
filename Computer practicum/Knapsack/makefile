all: main.o solver.o

main.o: main.cpp
	g++ -c main.cpp
solver.o: solver.mzn
	minizinc --solver Gecode solver.mzn

clean:
	rm *o
