#include <GL/glut.h>
#include <stdlib.h>


void display(void)
{
     /*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    
    typedef float point2[2];
    /* arbitrary triangle */
    point2 vertices[3] = { {0.0,0.0}, {250.0,500.0}, {500.0,0.0} };
    /* any desired initial point */
    point2 p = { 75.0,75.0 };
    for(int i=0; i<50000; i++) {
        /* pick a random vertex from 0,1,2 */
	    int j=rand()%3; 
	    /* compute new point */
     	p[0] = (p[0]+vertices[j][0])/2.0;
	    p[1] = (p[1]+vertices[j][1])/2.0;
	    /* display new point */
	    glBegin(GL_POINTS);
            glVertex2fv(p);
	    glEnd();
    }
    glFlush();
}

void init (void) 
{
/*  define a cor de background da janela       */
    glClearColor (1.0, 1.0, 1.0, 0.0);

/*  define o sistema de visualização - tipo de projeção  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

 
/* 
 *  Define o tamanho inicial e a posição  da janela e o modo de "display" 
*  (single buffer and RGBA).  Abre a janela com o título Meu primeiro programa 
 *  Chama as rotinas de inicialização  
 *  Registra as funções de callback.
 *  Entra no loop principal e processa os eventos.
 */


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Sierpinski");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;   
}
