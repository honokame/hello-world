// openwindow2.c

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void Display(void);
void Reshape(int,int);
int w,h;
int start_x,start_y,a;
int before_x,before_y;
int next_x,next_y;
int i,angle;

int main(int argc,char**argv){
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("STAR");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(1,1,1,1);
  glutMainLoop();
  
  return 0;
}

void Display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  w = glutGet(GLUT_WINDOW_WIDTH);
  h = glutGet(GLUT_WINDOW_HEIGHT);
  start_x = w / 2;
  start_y = h / 2;
  a = w / 2;
  glLineWidth(5.0);
  glColor3ub(225,0,119);
  glBegin(GL_LINES); 
  before_x = start_x - a / 2;
  before_y = start_y - (int)(a * tan(18 * M_PI / 180));

  for(i = 0;i < 5;i++){
    next_x = before_x + (int)(a * cos(angle * M_PI /180));
    next_y = before_y + (int)(a * sin(angle * M_PI / 180));
    glVertex2i(before_x,before_y); 
    glVertex2i(next_x,next_y);
    before_x = next_x;
    before_y = next_y;
    angle += 144;
  }
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

