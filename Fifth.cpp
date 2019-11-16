// Interaction.c
// Marcus Vinícius A. Andrade

#include <GL/glut.h>
#include <iostream>
using namespace std;



float xf=20, yf=20, win=250;
float xtemp=xf, ytemp=yf;
bool preenchido=true;

int view_w, view_h;

// Chamada para fazer o desenho
void RenderScene(void)
	{
	  // Limpa a janela
   	glClear(GL_COLOR_BUFFER_BIT);

  	// Desenha um retângulo com a cor corrente

  	glBegin(GL_POLYGON);
  	    glVertex2f(0,0);
  	    glVertex2f(xf,0);
  	    glVertex2f(xf,yf);
  	    glVertex2f(0,yf);
    glEnd();

  	glFlush();
	}


// Inicialização
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f (0.3, 0.3, 0.3);
}


// Chamada pela GLUT quando a janela é redimensionada
void ChangeSize(GLsizei w, GLsizei h)
	{
  	// Especifica o tamanho da viewport
  	glViewport(0, 0, w, h);
  	view_w = w;
  	view_h = h;

    // Inicializa sistema de coordenadas
  	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();

  	// Estabelece volume de visualização
    // (esquerda, direita, inferior, superior)
  	gluOrtho2D (-win, win, -win, win);

  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
	}


// Callback para gerenciar eventos de teclado
void HandleKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 82: // R
		case 114:// r
			   // muda a cor corrente para vermelho
			   glColor3f(1.0, 0.0, 0.0);
			   break;
		case 71: // G
		case 103:// g
			   // muda a cor corrente para verde
			   glColor3f(0.0, 1.0, 0.0);
			   break;
		case 66: // B
		case 98:// b
			   // muda a cor corrente para azul
			   glColor3f(0.0, 0.0, 1.0);
			   break;
		// modifiquei
        case 70: // F
		case 102:// f
			   // alterna preenchido/não-preenchido
               if(preenchido)
               {
                    glPolygonMode (GL_FRONT, GL_LINE);
                    preenchido=false;
               }
               else
               {
                    glPolygonMode (GL_FRONT, GL_FILL);
			        preenchido=true;
               }
               break;
        // final do meu código

		case 67: // B
		case 99:// b

	   	win -= 20;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			   break;
	}
  glutPostRedisplay();
}


// Callback para gerenciar eventos do mouse
void HandleMouse(int button, int state, int x, int y)
{
     /* Os valores de x e y retornados pelo clique do mouse
        sao tomados em relacao ao canto superior esquerdo da
        janela e correspondem ao numero de pixels na janela de
        tamanho (view_w, view_h). Como o sistema de coordenadas
        define que a origem do sistema, ponto (0,0), esta no centro
        da janela de dimensao (2win, 2win), definido pelo viewport,
        entao as coordenadas (x,y) precisam ser ajustadas:

          x pixels na janela de largura view_w valem
          (2win/view_h) * x na janela de largura 2win.
          Idem para a coordenada y.

      */


cout << "x = " << x << "  y = " << y << "(View_h, View_w) = (" << view_h << ", " << view_w << ")" << endl;

	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN) {
			// Troca o tamanho do retângulo, que vai do
			// centro da janela até a posição onde o usuário
			// clicou com o mouse
			xf = ( (2 * win * x) / view_w) - win;
            yf = ( ( (2 * win) * (view_h-y) ) / view_h) - win;
		}
//		if (state == GLUT_UP) {
//            xf=xtemp;
//            yf=ytemp;
//        }
    }
	glutPostRedisplay();
}


// Callback para gerenciar eventos do teclado para teclas
// especiais, SETA_
void SpecialKeys(int key, int x, int y)
 {
		if(key == GLUT_KEY_RIGHT) {
			win -= 20;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

        if(key == GLUT_KEY_LEFT) {
			win += 20;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

        glutPostRedisplay();
  }


// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Tratamento de entrada");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(HandleKeyboard);
	glutMouseFunc(HandleMouse);
	glutSpecialFunc(SpecialKeys);
	init();
	glutMainLoop();

	return 0;
}

