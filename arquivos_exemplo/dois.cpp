#include <GL/glut.h>
#include <math.h>      // For math routines (such as sqrt & trig).
#include <iostream>
using namespace std;

GLdouble radius=1;
GLfloat Red[] = {1.0, 0.0, 0.0, 1.0}; //Red Color


    // Set lighting intensity and color
GLfloat AmbientLight[]    = {0.1, 0.1, 0.1, 1.0};
GLfloat DiffuseLight[]    = {1, 1, 1, 1.0};
GLfloat LightPosition[]    = {2, 0, -10, 1};// Positional Light
GLfloat LightDirection[]    = {2, 0, -10, 0};// Directional Light

void display(void);
void reshape(int x, int y);

void initLighting()
{

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

     // Set lighting intensity and color
    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
     glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
 //   glLightfv(GL_LIGHT0, GL_POSITION, LightDirection);
    ////////////////////////////////////////////////
    //glLightf( GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.2f );
    //glLightf( GL_LIGHT0, GL_LINEAR_ATTENUATION , 0.5f );
    //glLightf( GL_LIGHT0, GL_QUADRATIC_ATTENUATION , 0.009f );


}
void keyboard(unsigned char key, int x, int y)
{


     if (key == 'l' || key == 'L')
    {
          glEnable(GL_LIGHTING);
    }
    else if (key == 'd' || key == 'D')
    {
        glDisable(GL_LIGHTING);
    }

}


//****************************************************************************80

int at_type = 0;

void menu ( int id )
{
  if ( id == 4 )
  {
    exit ( 0 );
  }
  else
  {
    at_type = id;
    glutPostRedisplay ( );
  }
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(750,750);
    glutCreateWindow("Teapot -light attenuation");
    initLighting();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutReshapeFunc(reshape);


  glutCreateMenu ( menu );
  glutAddMenuEntry ( "Atenuacao Constante", 1 );
  glutAddMenuEntry ( "Atenuacao Linear", 2 );
  glutAddMenuEntry ( "Atenuacao Quadratica", 3 );
  glutAttachMenu ( GLUT_RIGHT_BUTTON );

    glutMainLoop();
    return 0;
}

void display(void)
{

  cerr  << "changing to " << at_type << endl;
  initLighting();


  switch ( at_type )
  {

    case 1:
      glLightf( GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.2f );
    break;
    case 2:
      glLightf( GL_LIGHT0, GL_LINEAR_ATTENUATION , 0.5f );
    break;
    case 3:
      glLightf( GL_LIGHT0, GL_QUADRATIC_ATTENUATION , 0.8f );
    break;
  }


    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();

//    glTranslatef(0.0,0.0,10.0);

//      glPushMatrix();

      glTranslatef(0.0,0.0,-10.0);
    // Set material properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Red);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Red);

     glutSolidTeapot(radius);

    glFlush();
    glutSwapBuffers();

}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,40.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

