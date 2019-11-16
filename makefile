all: obj/Object.o obj/main.o obj/Ocean.o obj/Submarine.o obj/GlobalConfig.o
	g++ obj/*.o -lglut -lGLU -lGL

obj/Object.o: classes/Object.h classes/Object.cpp
	g++ -c classes/Object.cpp -o obj/Object.o

obj/Ocean.o: classes/Ocean.h classes/Ocean.cpp
	g++ -c classes/Ocean.cpp -o obj/Ocean.o

obj/Submarine.o: classes/Submarine.h classes/Submarine.cpp
	g++ -c classes/Submarine.cpp -o obj/Submarine.o

obj/GlobalConfig.o: classes/GlobalConfig.h classes/GlobalConfig.cpp
	g++ -c classes/GlobalConfig.cpp -o obj/GlobalConfig.o

obj/main.o: main.cpp
	g++ -c main.cpp -o obj/main.o

clear:
	rm -r obj/*