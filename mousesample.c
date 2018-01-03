#include<GL/glut.h>
#include<stdio.h>

void Display(void);
void Reshape(int,int);
void Mouse(int,int,int,int);
void PassiveMotion(int,int);
void Motion(int,int);
void Entry(int);

int main(int argc,char**argv){
  glutInit(&argc, argv);
  glutInitWindowSize(340,240);
  glutCreateWindow("マウスのサンプル");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(0,0,1,1);

  glutMouseFunc(Mouse);
  glutPassiveMotionFunc(PassiveMotion);
  glutMotionFunc(Motion);
  glutEntryFunc(Entry);
 
  glutMainLoop();

  return 0;
}

void Display(void){
  glClear(GL_COLOR_BUFFER_BIT);
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

void Mouse(int b,int s,int x,int y){
  if(b == GLUT_LEFT_BUTTON){
    if(s == GLUT_UP){
      printf("左ボタンアップ");
    }
    if(s == GLUT_DOWN){
      printf("左ボタンダウン");
    }
  }

  if(b == GLUT_MIDDLE_BUTTON){
    if(s == GLUT_UP){
      printf("中央ボタンアップ");
    }
    if(s == GLUT_DOWN){
      printf("中央ボタンダウン");
    }
  }

  if(b == GLUT_RIGHT_BUTTON){
    if(s == GLUT_UP){
      printf("右ボタンアップ");
    }
    if(s == GLUT_DOWN){
      printf("右ボタンダウン");
    
    }
  }

  printf("at(%d,%d)\n",x,y);
}

void PassiveMotion(int x,int y){
  printf("PassiveMotion : (x,y)=(%d,%d)\n",x,y);
}

void Motion(int x,int y){ 
  glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
  printf("Motion : (x,y)=(%d,%d)\n",x,y);
}

void Entry(int s){
  if(s == GLUT_ENTERED){
    printf("入りました");
  }
  if(s == GLUT_LEFT){
    printf("出ました");
  }
