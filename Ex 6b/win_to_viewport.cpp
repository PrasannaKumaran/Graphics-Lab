#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

float x[] = { 100, 200, 300, 200 }, y[] = {200, 300, 200, 100};
float transx[4] = { 0 }, transy[4] = { 0 };
float x_min_v = 0, x_max_v = 250, y_min_v = 0, y_max_v = 250;
float x_min_w = 0, x_max_w = 500, y_min_w = 0, y_max_w = 500;

void myInit() {
	glClearColor(1, 1, 1, 0);
	glColor3f(1, 0, 0);
	glPointSize(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void drawWindow() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(x[i], y[i]);
	}
	glEnd();
	glFlush();
}

void computeTransformed() {

	float sx = (x_max_v - x_min_v) / (x_max_w - x_min_w);
	float sy = (y_max_v - y_min_v) / (y_max_w - y_min_w);

	for (int i = 0; i < 4; i++)
	{
		transx[i] = (x[i] - x_min_w) * sx + x_min_v;
		transy[i] = (y[i] - y_min_w) * sy + y_min_v;
	}
}

void drawViewport() {
	computeTransformed();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(transx[i], transy[i]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	GLint w1, w2;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	w1 = glutCreateWindow("Window");
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(drawWindow);
	myInit();
	gluOrtho2D(0, 500, 0, 500);

	glutInitWindowSize(250, 250);
	w2 = glutCreateWindow("Viewport");
	glutDisplayFunc(drawViewport);
	myInit();
	gluOrtho2D(0, 250, 0, 250);
	glutMainLoop();

	return 1;
}