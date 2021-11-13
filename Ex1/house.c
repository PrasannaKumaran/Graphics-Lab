#include<GL/glut.h>

void init()
{
    glClearColor(0.6, 0.5, 0.2, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000, 0.0, 1000);
}
void drawHouse()
{
    glClear(GL_COLOR_BUFFER_BIT);     
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 450);
    glVertex2i(500, 800);
    glVertex2i(900, 450);
    glEnd();

// WALL
    glColor3f(0.1, 0.2, 0.3);
    glBegin(GL_POLYGON);
        glVertex2i(100,50);
        glVertex2i(900,50);
        glVertex2i(900,450);
        glVertex2i(100,450);
    glEnd();

 // DOOR 
    glColor3f(0.7, 0.2, 0.9);
    glBegin(GL_POLYGON);
        glVertex2i(450,50);
        glVertex2i(600,50);
        glVertex2i(600,200);
        glVertex2i(450,200);
    glEnd();

    glColor3f(0.3, 0.7, 0.9);
    glPointSize(15);
    glBegin(GL_POINTS);
        glVertex2i(460, 125);
    glEnd();

// window one
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
        glVertex2i(150, 200);
        glVertex2i(350, 200);
        glVertex2i(350, 350);
        glVertex2i(150, 350);
    glEnd();
// line of window one
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex2i(150, 275);
        glVertex2i(350, 275);
        glVertex2i(250, 200);
        glVertex2i(255, 350);
    glEnd();


// window two
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
        glVertex2i(650, 200);
        glVertex2i(850, 200);
        glVertex2i(850, 350);
        glVertex2i(650, 350);
    glEnd();
// line of window two
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex2i(650, 275);
        glVertex2i(850, 275);
        glVertex2i(750, 200);
        glVertex2i(755, 350);
    glEnd();
// base
    glColor3f(0.2, 0.1, 0.1);
    glBegin(GL_POLYGON);
        glVertex2i(100,50);
        glVertex2i(900,50);
        glVertex2i(900,0);
        glVertex2i(100,0);
    glEnd();
   glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Drawing a House in OpenGL");
    init();
    glutDisplayFunc(drawHouse);
    glutMainLoop();
}