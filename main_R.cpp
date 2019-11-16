#include <GL/gl.h>
#include <GL/glut.h>
#include "classes/object.cpp"
#include <stdlib.h>

//posicao do observador (camera)
GLdouble viewer[] = {0.0, 6.0, 10.0};
GLfloat ocean[8][3] = { {-1.0,-1.0,1.0} , {-1.0,1.0,1.0} , {1.0,1.0,1.0} , {1.0,-1.0,1.0} ,
{-1.0,-1.0,-1.0} , {-1.0,1.0,-1.0} , {1.0,1.0,-1.0} , {1.0,-1.0,-1.0} };

Object sub;

void quad(int a, int b, int c, int d, int ncolor) {
    glBegin(GL_QUADS);
        glVertex3fv(ocean[a]);
        glVertex3fv(ocean[b]);
        glVertex3fv(ocean[c]);
        glVertex3fv(ocean[d]);
    glEnd();
}

void draw_ocean(){
    glColor4f(0.0, 0.0, 1, 0.8);
    glBegin(GL_QUADS);
        glVertex3f(-20, 0, -10);
        glVertex3f(20, 0, -10);
        glVertex3f(20, 0, 10);
        glVertex3f(-20, 0, 10);
    glEnd();
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); //cor para limpeza do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
       
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);

    sub.charge("submarine");
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a janela
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2], // define posicao do observador
    0.0, 0.0, 0.0,                           // ponto de interesse (foco)
    0.0, 1.0, 0.0);                          // vetor de "view up"
    
    sub.draw();

    draw_ocean();
 
    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc,argv); // inicializa a glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // tipo de buffer/cores/profundidade
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT)); // dimensões da janela
    glutInitWindowPosition(0, 0); // posicao da janela
    glutCreateWindow("Submarino"); // cria a janela
    init();
    glutDisplayFunc(display); // determina funçãoo callback de desenho
    glEnable(GL_DEPTH_TEST); // habilita remoção de superfícies ocultas
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // habilita transparencia
    glEnable(GL_BLEND); // hablita transparência
    glutMainLoop();
    return 0;
}
