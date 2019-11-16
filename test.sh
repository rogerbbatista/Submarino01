
# gcc -ggdb3 -O0 -o test -std=c99 -Wall -Wextra -pedantic test.c -lGL -lGLU -lglut
g++ test.cpp -lglut -lGLU -lGL -o test.out
./test.out $1