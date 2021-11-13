#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

vector<int> pntX;
vector<int> pntY;
int pntX1, pntY1, choice = 0, edges;
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;

double round(double d) {
	return floor(d + 0.5);
} 

void drawLine() {
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++) {
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}

void drawLineTrans(int x, int y) {
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	for (int i = 0; i < edges; i++) {
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void drawLineScale(double x, double y) {
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	for (int i = 0; i < edges; i++) {
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}

void drawLineRotation(double angleRad) {
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++){
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.3, 0.5, 0.5);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	if (choice == 1) {
		drawLine();
		drawLineTrans(transX, transY);
	}
	else if (choice == 2) {
		drawLine();
		drawLineScale(scaleX, scaleY);
	}
	else if (choice == 3) {
		drawLine();
		drawLineRotation(angleRad);
	}
	glFlush();
}

int main(int argc, char** argv) {
	cout << "Enter your choice:\n\n" << endl;
	cout << "1. Translate" << endl;
	cout << "2. Scaling" << endl;
	cout << "3. Rotation" << endl;
	cout << "4. Exit" << endl;
	cin >> choice;
	if (choice == 4) {
		return 0;
	}
	edges=2;
	for (int i = 0; i < edges; i++) {
		cout << "Enter co-ordinates for vertex " << i + 1 << " : "; 
		cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}
	if (choice == 1) {
		cout << "Enter the translation factor for X and Y: "; 
		cin >> transX >> transY;
	}
	else if (choice == 2) {
		cout << "Enter the scaling factor for X and Y: "; 
		cin >> scaleX >> scaleY;
	}
	else if (choice == 3) {
		cout << "Enter the angle for rotation (in degree): "; 
		cin >> angle;
		angleRad = angle * 3.1416 / 180;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 1024);
	glutCreateWindow("Line Transformation");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}