#include <stdlib.h> 
#include <time.h>
#include <GL\glut.h> 
#include "Vector3.h"
#include "GameManager.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
#include "Butter.h"

 

#define UPDATE_TIMER 1

GameManager *gm;
void display() { gm->display(); }
void update(int i) { gm->onTimer(); glutTimerFunc(UPDATE_TIMER, update, UPDATE_TIMER); }
//void reshape(int width, int height) { gm->reshape(width, height); }
void keyboardfunc_up(int key, int x, int y) { gm->keyUp(key); }
void keyboardfunc_down(int key, int x, int y) { gm->keyPressed(key); }
void keyA(unsigned char key, int x, int y) { gm->keyA(key); }

//FIX ME
//void keyboardfunc_up(unsigned char key, int x, int y) { gm->keyUp(key); }
//void keyboardfunc_down(unsigned char key, int x, int y) { gm->keyPressed(key); }

/* Program entry point */

int main(int argc, char *argv[])
{
	srand(time(NULL));
	gm = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(640, 640);
	//glutInitWindowPosition(10,10);

	glutCreateWindow("MicroMachines");
	glutTimerFunc(UPDATE_TIMER, update, UPDATE_TIMER);
	glutReshapeWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glutDisplayFunc(display);

	glClearColor(0, 0, 0, 0);

	glutSpecialUpFunc(keyboardfunc_up);
	glutSpecialFunc(keyboardfunc_down);
	glutKeyboardFunc(keyA);
	glutMainLoop();

	return 0;
}
