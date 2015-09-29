#include <GL\glut.h> 
#include "Vector3.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Car.h"
#include "Orange.h"
float xmin = -2., xmax = 2., ymin = -2., ymax = 2.;
float xscale = (xmax - xmin) / 400, yscale = (ymax - ymin) / 400;
GLdouble innerRaidus = 0.1;
GLdouble outterRaidus = 1;
GLint sides = 50;
GLint rings = 50;

void myReshape(int w, int h) {
	//Game :: GameManager GM.Display();
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float c = (xmax + xmin) * .5;
	xmax = c + xscale  *w *  .5;
	xmin = c - xscale  *w *  .5;
	c = (ymax + ymin) * .5;
	ymax = c + yscale  *h *  .5;
	ymin = c - yscale  *h *  .5;
	gluOrtho2D(xmin, xmax, ymin, ymax);
}


/*void myDisplay(void) {
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex3f(-1.0f, -1.0f, 0.0f);
glVertex3f(1.0f, -1.0f, 0.0f);
glVertex3f(1.0f, 1.0f, 0.0f);
glVertex3f(-1.0f, 1.0f, 0.0f);
glEnd();
glFlush();
}*/

void myDisplay(void) {
	//Game :: GameManager GM.Display();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	Car  * x = new Car();
	Orange * o = new Orange();
	x->draw();
	o->draw();
	glFlush();
	//glPushMatrix();
	/*glBegin(GL_POLYGON);
		glVertex3f(-0.42857142857, -0.77777777777, 0.0);
		glVertex3f(0.42857142857, -0.77777777777, 0.0);
		glVertex3f(0.42857142857, 0.77777777777, 0.0);
		glVertex3f(-0.42857142857, 0.77777777777, 0.0);
	glEnd();
	glPopMatrix();*/
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); /*glut_RGBA|glut_single?*/
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Teste");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}