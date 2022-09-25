P0: main.o tree.o
	g++ main.o tree.o -o P0

main.o: main.cpp tree.o
	g++ main.cpp -c

tree.o: tree.cpp
	g++ tree.cpp -c
