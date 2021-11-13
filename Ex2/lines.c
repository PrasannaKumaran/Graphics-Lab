
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float x_1, y_1, x_2, y_2;
void display() {
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = x_2 - x_1;
	dy = y_2 - y_1;

	if (abs(dx) > abs(dy))
		step = abs(dx) * 500;
	else
		step = abs(dy) * 500;
	Xin = dx / step;
	Yin = dy / step;
	x = x_1;
	y = y_1;
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	for (k = 1; k <= step; k++){
		x = x + Xin;
		y = y + Yin;
		glBegin(GL_POINTS);
			glVertex2i(x, y);
		glEnd();
	}
	glFlush();
}

void init(void)
{
	glClearColor(0.7, 0.7, 0.7, 0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100, 100);
	printf("X1 : ");
	scanf("%f", &x_1);
	printf("Y1 : ");
	scanf("%f", &y_1);
	printf("X2 : ");
	scanf("%f", &x_2);
	printf("Y2 : ");
	scanf("%f", &y_2);
	glutCreateWindow("DDA Line Algorithm");
	init();	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

// Points
/*
L->R +ve slope < 1: x_1 = 0, y_1 = 0 , x_2 = 20, y_2 = 10

L->R +ve slope > 1: x_1 = 0, y_1 = 0, x_2 = 20, y_2 = 30

L->R -ve slope < 1: x_1 = 0, y_1 = 0, x_2 = 20, y_2 = -10 

L->R -ve slope > 1: x_1 = 0, y_1 = 0, x_2 = 20, y_2 = -30

R->L +ve slope < 1: x_1 = -20, y_1 = -10, x_2 = 0, y_2 = 0

R->L +ve slope > 1: x_1 = -20, y_1 = -30, x_2 = 0, y_2 = 0

R->L -ve slope < 1: x_1 = -20, y_1 = 10, x_2 = 0, y_2 = 0

R->L -ve slope > 1: x_1 = -20, y_1 = 30, x_2 = 0, y_2 = 0 
*/