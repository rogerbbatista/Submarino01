// Menu.c - Isabel H. Manssour
// Um programa OpenGL simples que exemplifica
// como exibir textos e utilizar menus e fun��es
// callback para verificar a movimenta��o do
// mouse na janela GLUT.
// Este c�digo est� baseado nos exemplos
// dispon�veis no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

// Constantes
#define QUADRADO 1
#define TRIANGULO 2
#define LOSANGO   3

// Vari�veis
char texto[30];
GLfloat win, r, g, b;
GLint view_w, view_h, primitiva;

// Fun��o que desenha um quadrado
void DesenhaQuadrado(void)
{
     glBegin(GL_QUADS);
               glVertex2f(-25.0f, -25.0f);
               glVertex2f(-25.0f, 25.0f);
               glVertex2f(25.0f, 25.0f);
               glVertex2f(25.0f, -25.0f);
     glEnd();
}

// Fun��o que desenha um tri�ngulo
void DesenhaTriangulo(void)
{
     glBegin(GL_TRIANGLES);
               glVertex2f(-25.0f, -25.0f);
               glVertex2f(0.0f, 25.0f);
               glVertex2f(25.0f, -25.0f);
     glEnd();
}

// Fun��o que desenha um losango
void DesenhaLosango(void)
{
     glBegin(GL_POLYGON);
               glVertex2f(-25.0f, 0.0f);
               glVertex2f(0.0f, 25.0f);
               glVertex2f(25.0f, 0.0f);
               glVertex2f(0.0f, -25.0f);
     glEnd();
}

// Desenha um texto na janela GLUT
void DesenhaTexto(char *string)
{
  	glPushMatrix();
        // Posi��o no universo onde o texto ser� colocado
        glRasterPos2f(-win,win-(win*0.08));
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++);
	glPopMatrix();
}

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glClear(GL_COLOR_BUFFER_BIT);

     // Define a cor corrente
     glColor3f(r,g,b);

     // Desenha uma primitiva
     switch (primitiva) {
            case QUADRADO:  DesenhaQuadrado();
                            break;
            case TRIANGULO: DesenhaTriangulo();
                            break;
            case LOSANGO:   DesenhaLosango();
                            break;
     }

     // Exibe a posi��o do mouse na janela
     glColor3f(0.0f,0.0f,0.0f);
     DesenhaTexto(texto);

     glutSwapBuffers();
}

// Gerenciamento do menu com as op��es de cores
void MenuCor(int op)
{
   switch(op) {
            case 0:
                     r = 1.0f;
                     g = 0.0f;
                     b = 0.0f;
                     break;
            case 1:
                     r = 0.0f;
                     g = 1.0f;
                     b = 0.0f;
                     break;
            case 2:
                     r = 0.0f;
                     g = 0.0f;
                     b = 1.0f;
                     break;
    }
    glutPostRedisplay();
}

// Gerenciamento do menu com as op��es de cores
void MenuPrimitiva(int op)
{
   switch(op) {
            case 0:
                     primitiva = QUADRADO;
                     break;
            case 1:
                     primitiva = TRIANGULO;
                     break;
            case 2:
                     primitiva = LOSANGO;
                     break;
    }
    glutPostRedisplay();
}

// Gerenciamento do menu principal
void MenuPrincipal(int op)
{
}

// Criacao do Menu
void CriaMenu()
{
    int menu,submenu1,submenu2;

    submenu1 = glutCreateMenu(MenuCor);
    glutAddMenuEntry("Vermelho",0);
    glutAddMenuEntry("Verde",1);
    glutAddMenuEntry("Azul",2);

    submenu2 = glutCreateMenu(MenuPrimitiva);
    glutAddMenuEntry("Quadrado",0);
    glutAddMenuEntry("Tri�ngulo",1);
    glutAddMenuEntry("Losango",2);

    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Cor",submenu1);
    glutAddSubMenu("Primitivas",submenu2);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glFlush();
}

// Inicializa par�metros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualiza��o como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    win=150.0f;
    primitiva = QUADRADO;
    r = 0.0f;
    g = 0.0f;
    b = 1.0f;
    strcpy(texto, "(0,0)");

    CriaMenu();

}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Especifica as dimens�es da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

// Fun��o callback chamada sempre que o mouse � movimentado
// sobre a janela GLUT com um bot�o pressionado
void MoveMouseBotaoPressionado(int x, int y)
{
     sprintf(texto, "Botao pressionado (%d,%d)", x, y);
     glutPostRedisplay();
}

// Fun��o callback chamada sempre que o mouse � movimentado
// sobre a janela GLUT
void MoveMouse(int x, int y)
{
     sprintf(texto, "(%d,%d)", x, y);
     glutPostRedisplay();
}

// Fun��o callback chamada para gerenciar eventos do teclado
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
           win -= 10;
           if (win < 10) win = 10;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           gluOrtho2D (-win, win, -win, win);
    }
    if(key == GLUT_KEY_DOWN) {
           win += 10;
           if (win > 500) win = 500;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           gluOrtho2D (-win, win, -win, win);
    }
    glutPostRedisplay();
}


// Programa Principal
int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(350,300);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Exemplo de Menu e Exibi��o de Caracteres");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutMotionFunc(MoveMouseBotaoPressionado);
     glutPassiveMotionFunc(MoveMouse);
     glutSpecialFunc(TeclasEspeciais);
     Inicializa();
     glutMainLoop();
}
