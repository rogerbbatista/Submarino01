#include <GL/glut.h>

void display(void)
{
/*  limpa a janela */
    glClear (GL_COLOR_BUFFER_BIT);

/*  desenha um retangulo amarelo com vertices em
             (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
 */
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();

/*
     inicia o processamento imediatamente
*/
    glFlush ();
}

void init (void)
{
/*  define a cor de background da janela       */
    glClearColor (0.0, 0.0, 1.0, 0.0);

/*  define o sistema de visualização - tipo de projeção  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Um primeiro programa");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
