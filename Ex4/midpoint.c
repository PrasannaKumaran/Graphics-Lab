#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

void myInit() {
    glClearColor(0.5, 0.8, 0.5, 0.0);
    glColor3f(0.65, 0.3, 0.45);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(2);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void mPCircle(int xm, int ym, int r) {
    int x = 0;
    int y = r;
    float p = 5 / 4 - r;
    glBegin(GL_POINTS);
    glVertex2d(x+xm,y+ym);
    while (y > x) {
        if (p < 0) {
            x++;
            p += 2 * x + 1;
        }
        else {
            y--;
            x++;
            p += 2 * (x - y) + 1;
        }
        glVertex2d(x + xm, y + ym);
        glVertex2d(x + xm, -y + ym);
        glVertex2d(-x + xm, y + ym);
        glVertex2d(-x + xm, -y + ym);
        glVertex2d(y + xm, x + ym);
        glVertex2d(-y + xm, x + ym);
        glVertex2d(y + xm, -x + ym);
        glVertex2d(-y + xm, -x + ym);
    }
    glEnd();
}

void customDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    mPCircle(250, 250, 100);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 1024);
    glutCreateWindow("Implementing Midpoint Circle Algorithm");
    glutDisplayFunc(customDisplay);
    myInit();
    glutMainLoop();
    return 1;
}