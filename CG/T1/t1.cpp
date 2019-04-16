#include <GL/glut.h>
#include <tgmath.h>
#include <math.h>
#include <stdio.h>

class wcPt2D {
  public:
    GLfloat x, y;
};

void init (void){
/* Estabelece parâmetros das coordenadas do mundo  para a janela de clipping*/
  glMatrixMode (GL_PROJECTION);
  gluOrtho2D (-100.0,100.0, -100.0, 100.0);
}

void translatePolygon (wcPt2D * verts, GLint nVerts, GLfloat tx, GLfloat ty){
  GLint k;
  for (k = 0; k < nVerts; k++) {
    verts [k].x = verts [k].x + tx;
    verts [k].y = verts [k].y + ty;
  }
  glBegin (GL_POLYGON);
    for (k = 0; k < nVerts; k++)
      glVertex2f (verts [k].x, verts [k].y);
  glEnd ( );

}

void rotatePolygon (wcPt2D * verts, GLint nVerts, wcPt2D pivPt, GLdouble theta){
  wcPt2D vertsRot[nVerts];
  GLint k;

  for (k = 0; k < nVerts; k++) {
    vertsRot[k].x = pivPt.x + (verts[k].x - pivPt.x) * cos (theta) 
    - (verts[k].y - pivPt.y) * sin (theta);    
    vertsRot[k].y = pivPt.y + (verts [k].x - pivPt.x) * sin (theta) 
    + (verts [k].y - pivPt.y) * cos (theta);
  }
  
  glBegin (GL_POLYGON);
    for (k = 0; k < nVerts; k++)
      glVertex2f (vertsRot [k].x, vertsRot [k].y);
  glEnd ( );  
}

void scalePolygon (wcPt2D * verts, GLint nVerts, wcPt2D fixedPt,
GLfloat sx, GLfloat sy){
  wcPt2D vertsNew[nVerts];
  GLint k;
  
  for (k = 0; k < nVerts; k++) {
    vertsNew [k].x = verts [k].x * sx + fixedPt.x * (1 - sx);
    vertsNew [k].y = verts [k].y * sy + fixedPt.y * (1 - sy);
  }
  glBegin (GL_POLYGON);
    for (k = 0; k < nVerts; k++)
      glVertex2f (vertsNew [k].x, vertsNew [k].y);
  glEnd ( );
}

void desenha (void){
  GLint nVerts = 4; // numero de vertices
  
  // linha horizontal para orientacao
  glBegin(GL_LINES);
    glVertex2f(-100, 0);
    glVertex2f(100, 0);
  glEnd();

  // linha vertical para orientacao
  glBegin(GL_LINES);
    glVertex2f(0, -100);
    glVertex2f(0, 100);
  glEnd();

// ------ Definição das Coordenadas do Poligono ------  
  wcPt2D quad[nVerts];
  quad[0].x = 15.0;
  quad[0].y = 0.0;
  
  quad[1].x = 0.0;
  quad[1].y = 0.0;
  
  quad[2].x = 0.0;
  quad[2].y = 15.0;
  
  quad[3].x = 15.0;     
  quad[3].y = 15.0; 

// ------ Utilizacao das Funcoes ------ 
  //translatePolygon(quad, nVerts, 20, 20);
  
  wcPt2D pivPt; // ponto de rotacao/escala
  pivPt.x = 0.0;
  pivPt.y = 0.0;    
  rotatePolygon (quad, nVerts, pivPt, M_PI/2);
  
  //scalePolygon (quad, nVerts, pivPt, 2, 3);
  
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Transformacoes 2D");
  
  // Função chamada toda vez que a tela precisa ser  
  // redesenhada. Serve para exibir objetos.
  init(); 
  glutDisplayFunc(desenha);

  glutMainLoop();
  return 0;
}