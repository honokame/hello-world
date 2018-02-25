//mogura.c
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
void Timer(int);
void Keyboard(unsigned char,int,int);

GLuint img[34];
pngInfo info[34];
int board[6][10];  
int rimit = 0;
int hit = 0;
int timeout = 0;
int main(int argc,char**argv){
  int x,y;
  int no = 0;
  int i = 0;
  char fname[34];
  
  srand((unsigned int)time(NULL));
  
  //初期状態
  // 背景
  for(y = 0;y < 2;y++){
    for(x = 0;x < 10;x++){
      board[y][x] = no;
      no++;
    }
  }
  
  //穴
  for(y = 2;y < 5;y++){
    for(x = 0;x < 10;x++){
      board[y][x] = 30;
    }
  }
  
  //草
  no = 20;
  for(y = 5;y < 6;y++){
    for(x = 0;x < 10;x++){
      board[y][x] = no;
      no++;
    }
  }
  glutInit(&argc,argv);
  glutInitWindowSize(640,384);
  glutCreateWindow("mogura\n");
  
  //画像の読み込み
  for(i = 0;i < 34;i ++){
    sprintf(fname,"%d.png",i);
    img[i] = pngBind(fname,PNG_NOMIPMAP,PNG_ALPHA,&info[i],GL_CLAMP,GL_NEAREST,GL_NEAREST);
  }
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutMouseFunc(Mouse); 
  glutTimerFunc(1000,Timer,0);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();
  return 0;
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
  int y,x;
  int m_x[3],m_y[3];
  int i;
  
  srand((unsigned int)time(NULL));
  
  //普通のモグラ出現
  if(rimit == 1){ 
    for(y = 0;y < 6;y++){
      for(x = 0;x < 10;x++){
        if(board[y][x] == 31 || board[y][x] == 32 || board[y][x] == 33){
          board[y][x] = 30;
        }
        PutSprite(img[board[y][x]],64 * x,64 * y,&info[board[y][x]]);
      }
    }
    glFlush();
    for(i = 0;i < 2;i++){
      m_y[i] = rand()% 3 + 2;
      m_x[i] = rand()% 10;
      board[m_y[i]][m_x[i]] = 31;
    }
    rimit = 0;
  }
  
  //金のモグラ出現
  if(rimit == 2){ 
    for(y = 0;y < 6;y++){
      for(x = 0;x < 10;x++){
        if(board[y][x] == 31 || board[y][x] == 33){
          board[y][x] = 30;
        }
        PutSprite(img[board[y][x]],64 * x,64 * y,&info[board[y][x]]);
      }
    }
    glFlush();
    for(i = 0;i < 2;i++){
      m_y[i] = rand()% 3 + 2;
      m_x[i] = rand()% 10;
      board[m_y[i]][m_x[i]] = 31;
    }
    m_y[2] = rand()% 3 + 2;
    m_x[2] = rand()% 10;
    board[m_y[2]][m_x[2]] = 32;
    rimit = 0;
  }
  //熊出現
  if(rimit == 3){ 
    for(y = 0;y < 6;y++){
      for(x = 0;x < 10;x++){
        if(board[y][x] == 31 || board[y][x] == 33){
          board[y][x] = 30;
        }
        PutSprite(img[board[y][x]],64 * x,64 * y,&info[board[y][x]]);
      }
    }
    glFlush();
    for(i = 0;i < 2;i++){
      m_y[i] = rand()% 3 + 2;
      m_x[i] = rand()% 10;
      board[m_y[i]][m_x[i]] = 31;
    }
    m_y[2] = rand()% 3 + 2;
    m_x[2] = rand()% 10;
    board[m_y[2]][m_x[2]] = 33;
    rimit = 0;
  }

  //モグラの出現、モグラが押された時の画面更新
  for(y = 0;y < 6;y++){
    for(x = 0;x < 10;x++){
      PutSprite(img[board[y][x]],64 * x,64 * y,&info[board[y][x]]);
    }
  }
  glFlush();
}

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

void Mouse(int button,int ud,int old_x,int old_y){
  int x,y;

  if(button == GLUT_LEFT_BUTTON){
    if(ud == GLUT_DOWN){
      x = old_x / 64;
      y = old_y / 64;

      //普通のモグラが押された時
      if(board[y][x] == 31){
        board[y][x] = 30;
        hit++;
      }

      //金のモグラが押された時
      else if(board[y][x] == 32){
        board[y][x] = 30;
        hit += 3; 
      } 

      //熊が押された時
      else if(board[y][x] == 33){
        board[y][x] = 30;
        hit -= 5; 
      }
      Display();
    }
  }
}

  void Timer(int t){
    rimit = 1;
    timeout++;

    //普通のモグラ出現
    Display();
    glutTimerFunc(1000,Timer,0);

    //金のモグラ出現
    if(timeout == 5 || timeout == 10 || timeout == 15 || timeout == 20 || timeout == 25){
      rimit = 2;
      Display();
    }
    //熊出現
    if(timeout == 3 || timeout == 9 || timeout == 12 || timeout == 18 || timeout == 23 || timeout == 27){
      rimit = 3;
      Display();
    }

      //ゲーム時間
      if(timeout == 30){
        printf("あなたの点数は７５点中 %d 点です\n",hit);
        exit(0);
      }
  }

  void Keyboard(unsigned char key,int x,int y){

    //途中終了
    if(key == 'q'){
      printf("あなたの点数は７５点中 %d 点です\n",hit);
      exit(0);
    }
  }
