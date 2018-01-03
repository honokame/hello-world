#include<GL/glut.h> 
#include <GL/glpng.h>
#include<stdio.h> 
#include<stdlib.h>

#define WIDTH 256
#define HEIGHT 256

pngInfo info;
GLuint texture;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);

  glEnable(GL_TEXTURE_2D);
  glEnable(GL_ALPHA_TEST);
  glBegin(GL_POLYGON);
  {
    glTexCoord2f(0.0f, 1.0f); glVertex2d( 0, 255 );
    glTexCoord2f(0.0f, 0.0f); glVertex2d( 0, 0 );
    glTexCoord2f(1.0f, 0.0f); glVertex2d( 255, 0 );
    glTexCoord2f(1.0f, 1.0f); glVertex2d( 255, 255 );
  }
  glEnd();
  glDisable(GL_ALPHA_TEST);
  glDisable(GL_TEXTURE_2D);

  glutSwapBuffers();
}

void idle(void)
{
  glutPostRedisplay();
}

void Init(){
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
  texture = pngBind ("1.png", PNG_NOMIPMAP, PNG_ALPHA, &info, GL_CLAMP, GL_NEAREST, GL_NEAREST);
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInit(&argc, argv);
  glutCreateWindow("Display Image");
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  Init();
  glutMainLoop();
  return 0;
}


