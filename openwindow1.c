// openwindow1.c

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

#define p 3.14159

void Display(void);
void Reshape(int,int);
int w,h;
int start_x,start_y,a;

int main(int argc,char**argv){
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("STAR");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(0,0,0.3,1);
  glutMainLoop();
  
  return 0;
}

void Display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  w = glutGet(GLUT_WINDOW_WIDTH);
  h = glutGet(GLUT_WINDOW_HEIGHT);
  start_x = w / 2;
  start_y = h / 2;
  a = start_x / 2;
  glLineWidth(3.0);
  glColor3ub(255,255,0);
  glBegin(GL_LINES); 
  glVertex2i(start_x - (int)(a * cos(18 * p / 180)),start_y - (int)(a * sin(18 * p / 180))); //2
  glVertex2i(start_x + (int)(a * cos(18 * p / 180)),start_y - (int)(a * sin(18 * p / 180))); //5
  glVertex2i(start_x + (int)(a * cos(18 * p / 180)),start_y - (int)(a * sin(18 * p / 180))); //5
  glVertex2i(start_x - (int)(a * cos(54 * p / 180)),start_y + (int)(a * sin(54 * p / 180))); //3
  glVertex2i(start_x - (int)(a * cos(54 * p / 180)),start_y + (int)(a * sin(54 * p / 180))); //3 
  glVertex2i(start_x,start_y - a); //1  
  glVertex2i(start_x,start_y - a); //1 
  glVertex2i(start_x + (int)(a * cos(54 * p / 180)),start_y + (int)(a * sin(54 * p / 180))); //4
  glVertex2i(start_x + (int)(a * cos(54 * p / 180)),start_y + (int)(a * sin(54 * p / 180))); //4 
  glVertex2i(start_x - (int)(a * cos(18 * p / 180)),start_y - (int)(a * sin(18 * p / 180))); //2 
  glEnd();
  glFlush();
}

void Reshape(int w, int h){
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}
