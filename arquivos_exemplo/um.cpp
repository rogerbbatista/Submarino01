#include <GL/glut.h>

void myinit(void)
{
		//GL_LIGHT0, GL_LIGHT1, ... GL_LIGHT8 sao pontos de luz
		//sao constantes vindas do opengl..

		//cor da luz ambiente...
		//1,1,1 --> luz branca de maxima intensidade...
		//1,1,0 --> luz parece ter cor amarela...
    GLfloat mat_ambient[ ] = { 0.1	, 0.1	, 0.1, 1.0 }; 
    GLfloat mat_specular[ ] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[ ] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[ ] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[ ] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat red_light[ ] = { 1.0, 0.0, 0.0, 0.0 };
 
    glClearColor (1.0, 1.0, 1.0, 1.0);
    
    
    //a cor da luz de um material indica o quanto de cada componente ele reflete.
    //exemplo: 1,0.5,0 --> reflete 100% do componente R, 50% da G e 0 da B
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    //pode-se definir como a luz sera: omni, spot, um sol, etc...
    //vamos definir as caracteristicas da luz 0...
    //Posicao pode ser usada para colocar uma lampada em um teto,
    //simular um sol (luz infinitamente longe), etc..
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient); //luz ambiente...
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, mat_shininess);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
    glColor3f (0, 0, 1.0);
    glutSolidSphere(1.0, 50, 16);
    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) 
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 
            1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else 
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h, 
            1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Modelos de Iluminacao");
    glutInitWindowPosition(300,300);

    myinit();

    glutDisplayFunc(display); 
    glutReshapeFunc (myReshape);
    glutMainLoop();

    return 0;

}
