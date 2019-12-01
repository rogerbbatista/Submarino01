#include <GL/glut.h>
#include <bits/stdc++.h>
void myinit(void)
{
    GLfloat mat_ambient[ ] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[ ] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[ ] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[ ] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat light_position[ ] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[ ] = { 1.0, 1.0, 0.0, 0.0 };
    GLfloat red_light[ ] = { 1.0, 0.0, 0.0, 0.0 };
 
    glClearColor (1.0, 1.0, 1.0, 1.0);
   
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
}

void keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 'l' : 
            glEnable(GL_LIGHTING);
            break;
        case 'a' :
            glDisable(GL_LIGHTING);
            break;
        case 'f' : 
            glShadeModel(GL_FLAT);;
            break;
        case 'g' :
            glShadeModel(GL_SMOOTH);
            break;
        case 27: // �esc� on keyboard
             exit(0);
        break;
        default: // �a� on keyboard
             break;
    }
}

void display(void)
{
    printf("%d\n", GL_SHADE_MODEL);
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
    glColor3f (0.5, 0.5, 0.5);
    glutSolidSphere(1.0, 50, 16);
    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) 
        glFrustum (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 
            1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else 
        glFrustum (-1.5*(GLfloat)w/(GLfloat)h, 
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
    glutKeyboardFunc(keyboard);
    glutReshapeFunc (myReshape);
   	glutIdleFunc ( display );
    glutMainLoop();

    return 0;

}
