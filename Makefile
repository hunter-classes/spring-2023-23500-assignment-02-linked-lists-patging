OBJECTS=List.o main.o Node.o


main: $(OBJECTS)
	g++ -std=c++11 -o main $(OBJECTS)

List.o: List.cpp Node.h List.h
	g++ -std=c++11 -c List.cpp 
main.o: main.cpp List.h Node.h
	g++ -std=c++11 -c main.cpp 

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c node.cpp 


clean:
	rm -rf *.o main tests *.out
