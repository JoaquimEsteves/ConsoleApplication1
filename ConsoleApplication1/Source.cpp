#include <GL\glut.h> 
#include "Vector3.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
float xmin = -2., xmax = 2., ymin = -2., ymax = 2.;
float xscale = (xmax - xmin) / 400, yscale = (ymax - ymin) / 400;


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


void myDisplay(void) {
	//GameManager GM.Display();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	Car  * c = new Car();
	Orange * o = new Orange();
	Road * r = new Road();
	r->draw();
	//c->draw();
	//o->draw();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Teste");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}