all:	main

main: main.o Robots.o
	g++ main.o Robots.o `sdl-config --libs` -o main

main.o: main.cpp
	g++ -c main.cpp

Robots.o:  Robots.cpp
	g++ -c Robots.cpp

clean:
	rm -f *.o main

