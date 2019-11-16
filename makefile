all: obj/Object.o obj/main.o obj/Ocean.o
	g++ obj/*.o -lglut -lGLU -lGL

obj/Object.o: classes/Object.h classes/Object.cpp
	g++ -c classes/Object.cpp -o obj/Object.o

obj/Ocean.o: classes/Ocean.h classes/Ocean.cpp
	g++ -c classes/Ocean.cpp -o obj/Ocean.o

obj/main.o: main_R.cpp
	g++ -c main_R.cpp -o obj/main.o

clear:
	rm -r obj/*