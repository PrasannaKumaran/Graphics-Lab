#include<GL/glut.h>

void display() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POINTS);
    	glColor3f(1.0f,1.0f,1.0f);
        glVertex2i(525,450);
 	glEnd();
	glPointSize(15);
	
	glBegin(GL_LINES);
    	glColor3f(0.6,1.0,0.2);
    	glVertex2i(500,600);
    	glVertex2i(550,600);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glColor3f(1,1,1);
    	glVertex2i(100,350);
    	glVertex2i(125,400);
    	glVertex2i(150,350);
    glEnd();
	
	glBegin(GL_LINE_LOOP);
    	glColor3f(2.0,2.0,1.0);
    	glVertex2i(700,350);
    	glVertex2i(725,375);
    	glVertex2i(700,400);
    	glVertex2i(685,385);
    	glVertex2i(650,305);
    glEnd();
	
	
	glBegin(GL_TRIANGLES);
    	glColor3f(0.7,0.7,0.7);
    	glVertex2i(500,650);
    	glVertex2i(550,650);
    	glVertex2i(525,700);
    glEnd();
	
	glBegin(GL_TRIANGLE_STRIP);
    	glColor3f(0, 0, 0);
    	glVertex2i(500,800);
    	glColor3f(0, 0, 0);
    	glVertex2i(550,800);
    	glColor3f(0, 0, 0);
    	glVertex2i(500,850);
    	glColor3f(0, 0, 0);
    	glVertex2i(600,850);
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    	glColor3f(1, 0.5, 0.4);
    	glVertex2i(100,600);
    	glVertex2i(150,700);
    	glVertex2i(200,650);
    	glVertex2i(200,550);
    	glVertex2i(175,500);
    glEnd();

	
   	glBegin(GL_QUADS);              
      glColor3f(2.0f, 0.0f, 0.0f); 
      glVertex2i(220,500);    
      glVertex2i(350,500);
      glVertex2i(350,550);
      glVertex2i(220,550);
    glEnd();
 
 	
    glBegin(GL_QUAD_STRIP);              
      glColor3f(2.0f, 2.0f, 2.0f);
	  glVertex2i(250,700);
      glVertex2i(250,1000); 
      glVertex2i(350,900);
      glVertex2i(400,700);
      glVertex2i(300,1000);
    glEnd();

    glBegin(GL_POLYGON);              
      glColor3f(0.7, 0.7, 0.7); 
      glVertex2i(650,500);
	  glVertex2i(675,450);    
      glVertex2i(700,500);
      glVertex2i(700,550);
      glVertex2i(675,600);
      glVertex2i(650,550);
    glEnd();

  glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Primitive Shapes");
    glClearColor(0.2,0.2,0.4,0.4);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000, 0.0, 1000);
    glutDisplayFunc(display);
    glutMainLoop();
}
