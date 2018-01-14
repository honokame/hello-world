// gamemap.c

#include<GL/glut.h>
#include<GL/glpng.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Display(void);
void Reshape(int,int);
void PutSprite(int,int,int,pngInfo *);
void Mouse(int,int,int,int);
void glutPostRedisplay(void);

GLuint img[2];
pngInfo info[2];
int board[10][10];  
int main(int argc,char**argv){
  printf("☆★星を消して進級しよう★☆\n");
  int x,y;
  int no; 
  srand((unsigned int)time(NULL));
  for(y = 0;y < 10;y++){
   for(x = 0;x < 10;x++){
     no = rand() % 2;
     board[y][x] = no;
   }
  }
  glutInit(&argc,argv);
  glutInitWindowSize(320,320);
  glutCreateWindow("seiseki\n");
  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA);
  glClearColor(0.0,0.0,1.0,1.0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

  //PNG画像の読み込み
  img[0] = pngBind("1.png",PNG_NOMIPMAP,PNG_ALPHA,&info[0],GL_CLAMP,GL_NEAREST,GL_NEAREST);
  img[1] = pngBind("2.png",PNG_NOMIPMAP,PNG_ALPHA,&info[1],GL_CLAMP,GL_NEAREST,GL_NEAREST);

  //コールバック関数の登録
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutMouseFunc(Mouse); 
  glutMainLoop();

  return 0;
}

//ウィンドウのサイズが変更したときに座標系を再設定する関数
void Reshape(int w,int h){
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}

//ウィンドウの表示内容を更新する
void Display(void){
  int y,x;
  int count = 0;

  glClear(GL_COLOR_BUFFER_BIT);
  for(y = 0;y < 10;y++){
    for(x = 0;x < 10;x++){
      PutSprite(img[board[y][x]],32 * x,32 * y,&info[board[y][x]]);
      if(board[y][x] == 0){
        count++;
      }
    }
  }
  if(count == 100){
    printf("**************進級おめでとう************\n");
  }
  glFlush();
}

//PNG画像を座標に表示する
void PutSprite(int no,int x,int y,pngInfo *info){
  int w,h;

  w = info->Width;
  h = info->Height;
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,no);
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

//マウスがクリックされたとき
void Mouse(int button,int ud,int old_x,int old_y){
  int x,y;
  int i;
  if(button == GLUT_LEFT_BUTTON){
    if(ud == GLUT_DOWN){
      x = old_x / 32;
      y = old_y / 32;
      for(i = -1;i < 2;i++){
        if(y+i > -1 && y+i < 10){
          board[y+i][x] = !(board[y+i][x]);
        }
        continue;
      }
      for(i = -1;i < 2;i++){
        if(x+i > -1 && x+i < 10 && !(i == 0)){
          board[y][x+i] = !(board[y][x+i]);
        }
        continue;
      }
      glutPostRedisplay();
      
    }
  }
}
      
      
