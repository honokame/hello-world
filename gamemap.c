// pngread.c

#include<GL/glut.h>
#include<GL/glpng.h>
#include<stdio.h>
#include<stdlib.h>

void Display(void);
void Reshape(int,int);
void Timer(int);
void PutSprite(int,int,int,pngInfo *);

int x = 0,y = 0;
GLuint img[2];
pngInfo info[2];
int map[20][20] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
};

int main(int argc,char**argv){
  glutInit(&argc,argv);
  glutInitWindowSize(400,400);
  glutCreateWindow("read test\n");
  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA);
  glClearColor(0.0,0.0,1.0,1.0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

  img[0] = pngBind("1.png",PNG_NOMIPMAP,PNG_ALPHA,&info[0],GL_CLAMP,GL_NEAREST,GL_NEAREST);
  img[1] = pngBind("2.png",PNG_NOMIPMAP,PNG_ALPHA,&info[1],GL_CLAMP,GL_NEAREST,GL_NEAREST);

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutTimerFunc(1000, Timer, 0);

  glutMainLoop();

  return 0;
}

void Timer(int t){
  x += 5;
  if(x > 240){
    x = 0;
    y += 5;
    if(y > 240){
      y = 0;
    }
  }

  glutPostRedisplay();
  glutTimerFunc(1000,Timer,0);
}

void Reshape(int w,int h){
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}

void Display(void){
  int i,j;

  glClear(GL_COLOR_BUFFER_BIT);
  for(i = 0;i < 20;i++){
    for(j = 0;j < 20;j++){
      PutSprite(img[map[i][j]],32 * i - x,32 * j - y,&info[map[i][j]]);
    }
  }
  glFlush();
}

void PutSprite(int num,int x,int y,pngInfo *info){
  int w,h;

  w = info->Width;
  h = info->Height;

  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,num);
  glColor4ub(255,255,255,255);

  glBegin(GL_QUADS);

  glTexCoord2i(0,0);
  glVertex2i(x,y);
  
  glTexCoord2i(0,1);
  glVertex2i(x,y + h);
 
  glTexCoord2i(1,1);
  glVertex2i(x + w,y + h);

  glTexCoord2i(1,0);
  glVertex2i(x + w,y);

 glEnd();

 glDisable(GL_TEXTURE_2D);
 glPopMatrix();
}

