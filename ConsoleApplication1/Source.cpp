#include <GL\glut.h> 
#include "Vector3.h"
#include "GameManager.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
#include "Butter.h"

GameManager *gm;
void display() { gm->display(); }
void reshape(int width, int height) { gm->reshape(width, height); }
//FIX ME
//void keyboardfunc_up(unsigned char key, int x, int y) { gm->keyUp(key); }
//void keyboardfunc_down(unsigned char key, int x, int y) { gm->keyPressed(key); }

/* Program entry point */

int main(int argc, char *argv[])
{
	gm = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(640, 640);
	//glutInitWindowPosition(10,10);

	glutCreateWindow("MicroMachines");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glClearColor(0, 0, 0, 0);

	//glutKeyboardUpFunc(keyboardfunc_up);
	//glutKeyboardFunc(keyboardfunc_down);
	glutMainLoop();

	return 0;
}
