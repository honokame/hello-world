#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

void Display(void);
void Reshape(int,int);
void Keyboard(unsigned char,int,int);

int main(int argc,char**argv){
  glutInit(&argc, argv);
  glutInitWindowSize(320, 240);
  glutCreateWindow("sample");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(0.0, 0.0, 1.0, 1.0);

  glutMainLoop();

  return 0;
}

void Display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void Reshape(int w,int h){
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}

void Keyboard(unsigned char key,int x,int y){
  if((key == 'q') || (key == 27)){
    printf("終了しました\n");
    exit(0);
  }
}
