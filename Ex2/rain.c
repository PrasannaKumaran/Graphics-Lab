#include <stdio.h>
#include <GL/glut.h>

int width;
int height;

void dda (int x1, int y1, int x2, int y2)
{
  int dx, dy, steps, i = 1;
  double Xin, Yin, x, y;
  dx = x2 - x1;
  dy = y2 - y1;
  steps = (abs (dx) > abs (dy)) ? abs (dx) : abs (dy);
  Xin = dx / steps;
  Yin = dy / steps;
  x = x1;
  y = y1;
  glBegin (GL_POINTS);
  while (i<=steps) {
    glVertex2f ((2.0 * x)/width, (2.0 * y)/height);
    x += Xin;
    y += Yin;
    i++;
  }
  glEnd ();
  glFlush ();
}

void init (void) {
  glMatrixMode (GL_PROJECTION);
  glClearColor (0, 0, 0, 1);
  glClear (GL_COLOR_BUFFER_BIT);
  glLoadIdentity ();
  glMatrixMode (GL_MODELVIEW);
}

void display (void) {
  float x_1, y_1, x_2, y_2;
  glClear (GL_COLOR_BUFFER_BIT);
  width = glutGet (GLUT_WINDOW_WIDTH);
  height = glutGet (GLUT_WINDOW_HEIGHT);
  int i = 0;
  while (i  < 200)
  {
    x_1 = rand () % width  - (width  /2);
    y_1 = rand () % height - (height /2);
    x_2 = x_1 - 50;  
    y_2 = y_1 - 50; 
    dda (x_1, y_1, x_2, y_2);
    i++;
  }
}

int main (int argc, char *argv[]) {
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(512,512);
  init ();
  glutCreateWindow ("RainPattern");
  glutDisplayFunc (display);
  glutMainLoop ();
  return 0;
}   