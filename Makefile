
all: send move

stb.o: stb.c
	gcc -c -o $@ stb.c -O2

send: send.c stb.o config.h
	gcc -o $@ send.c stb.o -march=native -g -O3 -lm

move: move.cpp config.h
	g++ -o $@ move.cpp -march=native -g -O3
	