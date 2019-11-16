//#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

	glColor3f (1.0, 0.0, 0.0);
    glPointSize (10.0);
//    glPolygonMode (GL_FRONT, GL_POINT);
 //   glPolygonMode (GL_FRONT, GL_LINE);
//    glPolygonMode (GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
	    glVertex2i (40, 30);
		glVertex2i (-40, 5);
		glVertex2i (-25, -30);

        /*
             SOMENTE ACEITA POLIGONOS CONVEXOS
             TESTE INCLUINDO OS PONTOS ABAIXO E
             FAZENDO glPolygonMode (GL_FRONT, GL_LINE);

		glVertex2i (10,  -5);
		glVertex2i (20, 25);

		glVertex2i (-30, -15);

		*/
  glEnd();

/*  don't wait!
 *  start processing buffered OpenGL routines
 */
    glFlush ();
}

void init (void)
{
/*  select clearing (background) color       */
    glClearColor (1.0, 1.0, 1.0, 1.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -200.0, 50.0);
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Segundo programa");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}
