// clock.c

#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

void Display(void);
void Reshape(int,int);
void Timer(int);

int main(int argc,char**argv){
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("clock");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape); 
  glutTimerFunc(500,Timer,0);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glClearColor(1,0.9,0.8,1);
  glutMainLoop();

  return 0;
}

void Display(void){ 
  int start_x,start_y;
  int i;
  int w,hh;
  int h,m,s;
  int lh,lm,ls;
  double theta_h,theta_m,theta_s;
  glClear(GL_COLOR_BUFFER_BIT);
  w = glutGet(GLUT_WINDOW_WIDTH);
  hh = glutGet(GLUT_WINDOW_HEIGHT);
  start_x = w / 2;
  start_y = hh / 2;
  time_t tt;
  struct tm *ts;
  time(&tt); 
  ts = localtime(&tt); 
  h = ts->tm_hour % 12;
  m = ts->tm_min;
  s = ts->tm_sec;
  lh = 120;
  lm = 180;
  ls = 150;
  theta_h = 2 * M_PI * (3600 * h + 60 * m + s) / 43200;
  theta_m = 2 * M_PI * (60 * m + s) / 3600;
  theta_s = 2 * M_PI * s / 60;

  glLineWidth(2.0); 
  glPointSize(4.0);
  glBegin(GL_POLYGON); 
  glColor3ub(242,216,140);
  for(i = 0;i < 360;i++){ 
    glVertex2d(start_x + 199 * cos(i * M_PI / 180),start_y - 199 * sin(i * M_PI / 180));
  }
  glEnd();
  glBegin(GL_POINTS);
  glColor3ub(0,0,0);
  for(i = 0;i < 360;i++){ 
    glVertex2d(start_x + 200 * cos(i * M_PI / 180),start_y - 200 * sin(i * M_PI / 180));
  }
  i = 0;
  glColor3ub(194,154,88);
  for(i = 0;i < 360;i++){ 
    glVertex2d(start_x + 202 * cos(i * M_PI / 180),start_y - 202 * sin(i * M_PI / 180));
    glVertex2d(start_x + 204 * cos(i * M_PI / 180),start_y - 204 * sin(i * M_PI / 180));
    glVertex2d(start_x + 206 * cos(i * M_PI / 180),start_y - 206 * sin(i * M_PI / 180));
    glVertex2d(start_x + 208 * cos(i * M_PI / 180),start_y - 208 * sin(i * M_PI / 180));
    glVertex2d(start_x + 210 * cos(i * M_PI / 180),start_y - 210 * sin(i * M_PI / 180));
    glVertex2d(start_x + 212 * cos(i * M_PI / 180),start_y - 212 * sin(i * M_PI / 180));
  }
  i = 0;
  glColor3ub(75,62,21);
  while(i < 360){
    glVertex2d(start_x + 185 * cos(i * M_PI / 180),start_y - 185 * sin(i * M_PI / 180));
    i += 6;
  }
  glEnd();
  glColor3ub(25,25,25);
  glBegin(GL_LINES); 
  glVertex2i(start_x,start_y);
  glVertex2i(start_x + (int)(lh * sin(theta_h)),start_y - (int)(lh * cos(theta_h)));
  glVertex2i(start_x + 1,start_y + 1);
  glVertex2i(start_x + 1 + (int)(lh * sin(theta_h)),start_y + 1 - (int)(lh * cos(theta_h)));
  glVertex2i(start_x - 1,start_y - 1);
  glVertex2i(start_x - 1 + (int)(lh * sin(theta_h)),start_y - 1 - (int)(lh * cos(theta_h)));
  glVertex2i(start_x + 2,start_y + 2);
  glVertex2i(start_x + 2 + (int)(lh * sin(theta_h)),start_y + 2 - (int)(lh * cos(theta_h)));
  glVertex2i(start_x - 2,start_y - 2);
  glVertex2i(start_x - 2 + (int)(lh * sin(theta_h)),start_y - 2 - (int)(lh * cos(theta_h)));
  glColor3ub(25,25,25);
  glVertex2i(start_x,start_y);
  glVertex2i(start_x + (int)(lm * sin(theta_m)),start_y - (int)(lm * cos(theta_m)));
  glVertex2i(start_x + 1,start_y + 1);
  glVertex2i(start_x + 1 + (int)(lm * sin(theta_m)),start_y + 1 - (int)(lm * cos(theta_m)));
  glVertex2i(start_x - 1,start_y - 1);
  glVertex2i(start_x - 1 + (int)(lm * sin(theta_m)),start_y - 1 - (int)(lm * cos(theta_m)));
  glColor3ub(165,165,165);
  glVertex2i(start_x,start_y);
  glVertex2d(start_x + (ls * sin(theta_s)),start_y - (ls * cos(theta_s)));
  glEnd();
  glColor3ub(116,169,214);
  glRasterPos2i(start_x + 1 + 150 * cos(60 * M_PI / 180),start_y - 150 * sin(60 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x + 150 * cos(60 * M_PI / 180),start_y - 150 * sin(60 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 1 + 150 * cos(60 * M_PI / 180),start_y - 150 * sin(60 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glColor3ub(239,117,188);
  glRasterPos2i(start_x + 4 + 150 * cos(30 * M_PI / 180),start_y + 5 - 150 * sin(30 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  glRasterPos2i(start_x + 3 + 150 * cos(30 * M_PI / 180),start_y + 5 - 150 * sin(30 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  glRasterPos2i(start_x + 2 + 150 * cos(30 * M_PI / 180),start_y + 5 - 150 * sin(30 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  glColor3ub(64,0,178);
  glRasterPos2i(start_x + 9 + 150 * cos(0 * M_PI / 180),start_y + 8 - 150 * sin(0 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
  glRasterPos2i(start_x + 8 + 150 * cos(0 * M_PI / 180),start_y + 8 - 150 * sin(0 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
  glRasterPos2i(start_x + 7 + 150 * cos(0 * M_PI / 180),start_y + 8 - 150 * sin(0 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
  glColor3ub(11,218,81);
  glRasterPos2i(start_x + 9 + 150 * cos(330 * M_PI / 180),start_y + 14 - 150 * sin(330 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
  glRasterPos2i(start_x + 8 + 150 * cos(330 * M_PI / 180),start_y + 14 - 150 * sin(330 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
  glRasterPos2i(start_x + 7 + 150 * cos(330 * M_PI / 180),start_y + 14 - 150 * sin(330 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
  glColor3ub(236,165,23);
  glRasterPos2i(start_x + 2 + 150 * cos(300 * M_PI / 180),start_y + 20 - 150 * sin(300 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
  glRasterPos2i(start_x + 1 + 150 * cos(300 * M_PI / 180),start_y + 20 - 150 * sin(300 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
  glRasterPos2i(start_x + 0 + 150 * cos(300 * M_PI / 180),start_y + 20 - 150 * sin(300 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
  glColor3ub(249,37,0);
  glRasterPos2i(start_x - 3 + 150 * cos(270 * M_PI / 180),start_y + 19 - 150 * sin(270 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'6');
  glRasterPos2i(start_x - 4 + 150 * cos(270 * M_PI / 180),start_y + 19 - 150 * sin(270 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'6');
  glRasterPos2i(start_x - 5 + 150 * cos(270 * M_PI / 180),start_y + 19 - 150 * sin(270 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'6');
  glColor3ub(116,169,214);
  glRasterPos2i(start_x - 8 + 150 * cos(240 * M_PI / 180),start_y + 18 - 150 * sin(240 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'7');
  glRasterPos2i(start_x - 9 + 150 * cos(240 * M_PI / 180),start_y + 18 - 150 * sin(240 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'7');
  glRasterPos2i(start_x - 10 + 150 * cos(240 * M_PI / 180),start_y + 18 - 150 * sin(240 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'7');
  glColor3ub(239,117,188);
  glRasterPos2i(start_x - 14 + 150 * cos(210 * M_PI / 180),start_y + 15 - 150 * sin(210 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'8');
  glRasterPos2i(start_x - 15 + 150 * cos(210 * M_PI / 180),start_y + 15 - 150 * sin(210 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'8');
  glRasterPos2i(start_x - 16 + 150 * cos(210 * M_PI / 180),start_y + 15 - 150 * sin(210 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'8');
  glColor3ub(64,0,178);
  glRasterPos2i(start_x - 19 + 150 * cos(180 * M_PI / 180),start_y + 10 - 150 * sin(180 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'9');
  glRasterPos2i(start_x - 20 + 150 * cos(180 * M_PI / 180),start_y + 10 - 150 * sin(180 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'9');
  glRasterPos2i(start_x - 21 + 150 * cos(180 * M_PI / 180),start_y + 10 - 150 * sin(180 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'9');
  glColor3ub(11,218,81);
  glRasterPos2i(start_x - 19 + 150 * cos(150 * M_PI / 180),start_y + 5 - 150 * sin(150 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 20 + 150 * cos(150 * M_PI / 180),start_y + 5 - 150 * sin(150 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 21 + 150 * cos(150 * M_PI / 180),start_y + 5 - 150 * sin(150 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glColor3ub(11,218,81);
  glRasterPos2i(start_x - 5 + 150 * cos(150 * M_PI / 180),start_y + 5 - 150 * sin(150 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0');
  glRasterPos2i(start_x - 6 + 150 * cos(150 * M_PI / 180),start_y + 5 - 150 * sin(150 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0');
  glRasterPos2i(start_x - 7 + 150 * cos(150 * M_PI / 180),start_y + 5 - 150 * sin(150 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0');
  glColor3ub(236,165,23);
  glRasterPos2i(start_x - 20 + 150 * cos(120 * M_PI / 180),start_y - 150 * sin(120 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 21 + 150 * cos(120 * M_PI / 180),start_y - 150 * sin(120 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 22 + 150 * cos(120 * M_PI / 180),start_y - 150 * sin(120 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glColor3ub(236,165,23);
  glRasterPos2i(start_x - 15 + 150 * cos(120 * M_PI / 180) + 10,start_y - 150 * sin(120 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 16 + 150 * cos(120 * M_PI / 180) + 10,start_y - 150 * sin(120 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 17 + 150 * cos(120 * M_PI / 180) + 10,start_y - 150 * sin(120 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glColor3ub(249,37,0);
  glRasterPos2i(start_x - 11 + 150 * cos(90 * M_PI / 180),start_y -3 - 150 * sin(90 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 12 + 150 * cos(90 * M_PI / 180),start_y -3 - 150 * sin(90 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glRasterPos2i(start_x - 13 + 150 * cos(90 * M_PI / 180),start_y -3 - 150 * sin(90 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
  glColor3ub(249,37,0);
  glRasterPos2i(start_x + 4 + 150 * cos(90 * M_PI / 180),start_y -3 - 150 * sin(90 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  glRasterPos2i(start_x + 3 + 150 * cos(90 * M_PI / 180),start_y -3 - 150 * sin(90 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  glRasterPos2i(start_x + 2 + 150 * cos(90 * M_PI / 180),start_y -3 - 150 * sin(90 * M_PI / 180));
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
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

void Timer(int value){
  Display();
  glutTimerFunc(500,Timer,0);
}


