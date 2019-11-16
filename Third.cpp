#include <GL/glut.h>
#include <math.h>

void display(void)
{
    #define PI 3.1415926535898
    GLint circle_points;
    GLfloat r, angle;

	/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

    /*  desenha um circulo de raio r centrado na origem */

    glColor3f (0.1, 0.0, 0.8);

	r = 30;
	circle_points = 50;
    glBegin(GL_POLYGON);
      for (int i = 0; i < circle_points; i++) {
          angle = 2*PI*i/circle_points;
          glVertex2f(r * cos(angle), r * sin(angle));
	  }
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
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
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
    glutCreateWindow ("Meu Terceiro programa");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}
