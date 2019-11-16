all: obj/*.o # Object.o main.o
	g++ obj/*.o -lglut -lGLU -lGL

Object.o: classes/Object.h classes/Object.cpp
	g++ -c classes/Object.cpp -o obj/Object.o

main.o: main.cpp
	g++ -c main_R.cpp -o obj/main.o

clear:
	rm -r obj/*