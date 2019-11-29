all: obj/Object.o obj/main.o obj/Ocean.o obj/Submarine.o obj/GConf.o obj/Camera.o obj/Help.o obj/Text.o obj/Lights.o obj/Matrix.o obj/display.o obj/handle.o  obj/init.o obj/mainLoop.o
	g++ obj/*.o -lglut -lGLU -lGL -o main.out

obj/Text.o: classes/Text.h classes/Text.cpp
	g++ -c classes/Text.cpp -o obj/Text.o

obj/Help.o: classes/Help.h classes/Help.cpp
	g++ -c classes/Help.cpp -o obj/Help.o

obj/Lights.o: classes/Lights.h classes/Lights.cpp
	g++ -c classes/Lights.cpp -o obj/Lights.o

obj/Camera.o: classes/Camera.h classes/Camera.cpp
	g++ -c classes/Camera.cpp -o obj/Camera.o

obj/Object.o: classes/Object.h classes/Object.cpp
	g++ -c classes/Object.cpp -o obj/Object.o

obj/Ocean.o: classes/Ocean.h classes/Ocean.cpp
	g++ -c classes/Ocean.cpp -o obj/Ocean.o

obj/Submarine.o: classes/Submarine.h classes/Submarine.cpp
	g++ -c classes/Submarine.cpp -o obj/Submarine.o

obj/GConf.o: classes/GConf.h classes/GConf.cpp
	g++ -c classes/GConf.cpp -o obj/GConf.o

obj/Matrix.o: classes/Matrix.h classes/Matrix.cpp
	g++ -c classes/Matrix.cpp -o obj/Matrix.o

obj/display.o: openGL/Functions.h openGL/display.cpp
	g++ -c openGL/display.cpp  -o obj/display.o

obj/handle.o: openGL/Functions.h openGL/handle.cpp
	g++ -c openGL/handle.cpp  -o obj/handle.o

obj/init.o: openGL/Functions.h openGL/init.cpp
	g++ -c openGL/init.cpp  -o obj/init.o

obj/mainLoop.o: openGL/Functions.h openGL/mainLoop.cpp 
	g++ -c openGL/mainLoop.cpp  -o obj/mainLoop.o

obj/main.o: main.cpp
	g++ -c main.cpp -o obj/main.o

clear:
	rm -r obj/*