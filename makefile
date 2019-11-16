all: obj/*.o # Object.o main.o Ocean.o
	g++ obj/*.o -lglut -lGLU -lGL

Object.o: classes/Object.h classes/Object.cpp
	g++ -c classes/Object.cpp -o obj/Object.o

Ocean.o: classes/Ocean.h classes/Ocean.cpp
	g++ -c classes/Ocean.cpp -o obj/Ocean.o

main.o: main.cpp
	g++ -c main_R.cpp -o obj/main.o

clear:
	rm -r obj/*