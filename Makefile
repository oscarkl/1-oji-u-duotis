output: main.o
	g++ main.o -o output

main.o: main.cpp skaiciai.h struktura.h
	g++ -c main.cpp

clean:
	rm *.o output
