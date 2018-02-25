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

GLuint img[33];
pngInfo info[33];
int board[6][10];  
int main(int argc,char**argv){
  int x,y;
  int no = 0;
  int i = 0;
  char fname[33];
  /*srand((unsigned int)time(NULL));
  for(y = 0;y < 7;y++){
    for(x = 0;x < 12;x++){
      no = rand() % 2;
      board[y][x] = no;
    }
  }*/
  for(y = 0;y < 2;y++){
    for(x = 0;x < 10;x++){
      board[y][x] = no;
      no++;
    }
  }
  no = 30;
  for(y = 2;y < 5;y++){
    for(x = 0;x < 10;x++){
      board[y][x] = no;
    }
  }
  no = 20;
  for(y = 5;y < 6;y++){
    for(x = 0;x < 10;x++){
      board[y][x] = no;
      no++;
    }
  }



  glutInit(&argc,argv);
  glutInitWindowSize(640,384);
  glutCreateWindow("seiseki\n");
  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA);
  glClearColor(0.0,0.0,1.0,1.0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

  //PNG画像の読み込み
  for(i = 0;i < 33;i ++){
    sprintf(fname,"%d.png",i);
    img[i] = pngBind(fname,PNG_NOMIPMAP,PNG_ALPHA,&info[i],GL_CLAMP,GL_NEAREST,GL_NEAREST);
  }
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

  glClear(GL_COLOR_BUFFER_BIT);
  for(y = 0;y < 6;y++){
    for(x = 0;x < 10;x++){
      PutSprite(img[board[y][x]],64 * x,64 * y,&info[board[y][x]]);
    }
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
      x = old_x / 64;
      y = old_y / 64;
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




