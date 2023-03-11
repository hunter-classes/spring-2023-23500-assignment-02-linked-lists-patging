OBJECTS=OList.o main.o Node.o


main: $(OBJECTS)
	g++ -std=c++11 -o main $(OBJECTS)

tests: tests.o OList.o doctest.h Node.o
	g++ -std=c++11 -o tests tests.o OList.o Node.o

OList.o: OList.cpp Node.h OList.h
	g++ -std=c++11 -c OList.cpp Node.cpp
main.o: main.cpp OList.h Node.h
	g++ -std=c++11 -c main.cpp 

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c node.cpp 

tests.o: tests.cpp doctest.h OList.cpp
	g++ -std=c++11 -c tests.cpp OList.cpp

clean:
	rm -rf *.o main tests *.out
