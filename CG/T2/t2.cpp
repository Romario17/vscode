#include <iostream>
#include  <GL/glut.h>

// compilar: g++ t2.cpp -o t2 -lGL -lGLU -lglut 

class Ponto {
  public:
    GLfloat x, y;
};

Ponto quad[4];
Ponto pt;

/*
Recebe as coordenadas do mouse na tela do computador
e transforma em coordenadas de tela da aplicacao.
*/
Ponto mouse (int x, int y) {
  
  int larguraJanela = 600, alturaJanela = 600;
  pt.x = float(x)/larguraJanela;
  pt.y = 1 - float(y)/alturaJanela;
  
  return pt;
}

/*
Atualiza as coordenadas do quadrado previamente desenhado
*/
void arrastaQuad(Ponto *mouse){
  printf("\nold_q_x1: %f\nold_q_y1: %f\n", quad[0].x, quad[0].y);
  quad[0].x = mouse->x - 0.1;
  quad[0].y = mouse->y - 0.1;
  
  quad[1].x = mouse->x + 0.1;
  quad[1].y = mouse->y - 0.1;
  
  quad[2].x = mouse->x + 0.1;
  quad[2].y = mouse->y + 0.1;
  
  quad[3].x = mouse->x - 0.1;
  quad[3].y = mouse->y + 0.1;

  printf("q_x1: %f\nq_y1: %f\n", quad[0].x, quad[0].y);
  printf("q_x2: %f\nq_y2: %f\n", quad[1].x, quad[1].y);
  printf("q_x3: %f\nq_y3: %f\n", quad[2].x, quad[2].y);
  printf("q_x4: %f\nq_y4: %f\n", quad[3].x, quad[3].y);
}

/*
1. Quando o mouse é clicado e se move
a funcao glutMotionFunc(arrasta) é chamada na main.

2. A funcao "arrastaQuad" as coordenadas do mouse sao convertidas nas coordenadas da tela de
exibicao.

3. Na funcao "arrasta", é verificado se o
ponteiro do mouse esta em cima do quadrado.
Se sim, as coordenadas do quadrado sao atualizadas pela funcao "arrastaQuad".

*/
void arrasta(int x, int y){
  Ponto mousePt = mouse(x,y);
  Ponto *mouse = &mousePt;
    
  if (mouse->x > quad[0].x && mouse->y > quad[0].y){
    if(mouse->x < quad[2].x && mouse->y < quad[2].y){
      arrastaQuad(mouse);
      glutPostRedisplay();
    }
  }
}

void desenha (void){
 
  int i;
  //glColor3f(0.2, 0.2, 0.2);
  glBegin(GL_QUADS);
  for (i = 0; i < 4; ++i)
  {
      glVertex2f(quad[i].x, quad[i].y);
  }
  glEnd(); 
}

void init (void){
/* Coordenadas do quadrado na tela */
  quad[0].x = 0.5;
  quad[0].y = 0.5;

  quad[1].x = 0.7;
  quad[1].y = 0.5;

  quad[2].x = 0.7;
  quad[2].y = 0.7;

  quad[3].x = 0.5;     
  quad[3].y = 0.7;
/* Estabelece parâmetros das coordenadas do mundo  para a janela de clipping*/
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();  
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// desenha o quadrado e coloca na tela
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    desenha();
    glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Transformacoes 2D");
  
  // Detecta movimentacao do mouse 
  // e passa as coordenadas para a funcao "arrasta"
  glutMotionFunc(arrasta);  
  
  init();
  // define a rotina de exibição dos objetos OpenGL
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}