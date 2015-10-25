#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#define ORANGE_NUMBERS 3
#define BUTTER_NUMBERS 5
#define CAMERA_NUMBER 3
#define CHEERIOS_NUMBER 100

#include "Camera.h"
#include "Vector3.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Butter.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
#include "Cheerio.h"
#include "Camera.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "GL\glut.h"
#include <math.h>
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <list>
#include <iostream>
#include <vector>
#include <map>

class GameManager {

	bool _keys[256];
	bool _draw_wired = false;
	double _width = 640;
	double _height = 640;
	int _currentTime;
	int _lastTime = 0;
	float xmin = -5, xmax = 5, ymin = -5, ymax = 5;
	float xscale = (xmax - xmin) / 600, yscale = (ymax - ymin) / 600;
	Car  * myCar;
	Camera * _currentCamera;
	Orange * Oranges[ORANGE_NUMBERS];
	int LostOranges[ORANGE_NUMBERS] = { 0 };
	Butter * Butters[BUTTER_NUMBERS];
	Camera * Cameras[CAMERA_NUMBER];
	Cheerio * Cheerios[CHEERIOS_NUMBER];
	double counter = 0;
	int lostOrange;
	Vector3 positionBeforeCollision;
	int forward;
	double counter_delta_t=10;
	double speeder = 1;
	double actual_delta_t;



public:
	//DANGEROUS HACK, COULD NOT FOR SOME REASON CALL EXTERN GAMEMANAGER
	std::list<DynamicObject *> _interactable_game_objects;
	void setInteractableObject(DynamicObject* aux) { _interactable_game_objects.push_back(aux); }
	std::list<DynamicObject *> getInteractableObjects(void) { return _interactable_game_objects; }
	//END OF DANGEROUS HACK
	inline GameManager() {
		init();
	}
	inline ~GameManager() {}

	void HelloOrange(int i) {
		if (counter_delta_t <= actual_delta_t) {
			counter_delta_t = actual_delta_t + 10;
			speeder *= 2;
		}
		if (i % 2 == 0) {
		Oranges[i] = new Orange((rand() % 18)/2 , 9, 1);
		Oranges[i]->setSpeed(0, (rand() % 5 + 5)*0.0001*speeder, 0);
		Oranges[i]->setTurnAngle(-(Oranges[i]->getSpeed().getY()));
		}
		else {
		Oranges[i] = new Orange(9, (rand() % 18)/2, 1);
		Oranges[i]->setSpeed((rand() % 5 + 5)*0.0001*speeder, 0, 0);
		Oranges[i]->setTurnAngle(Oranges[i]->getSpeed().getX());
		}
	}
	void randOranges() {
		srand(time(NULL));
		for (int i = 0; i < ORANGE_NUMBERS; i++) {
			HelloOrange(i);
		}
	}
	/*std::vector<Camera *> getCameras();
	std::vector<GameObject *> getObjects();
	std::vector<LightSource *> getLightSources();
	void setCameras(std::vector<Camera *> v);
	void setObjects(std::vector<GameObject *> v);
	void setLightSources(std::vector<LightSource *> v);*/

	void keyA(unsigned char key) {
		switch (key) {
		case '1':
			_currentCamera = Cameras[0];
			break;
		case '2':
			_currentCamera = Cameras[1];
			break;
		case '3':
			_currentCamera = Cameras[2];
			break;
		case 'a':
			_keys['a'] = true;
			if (_draw_wired) {
				_draw_wired = false;
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else {
				_draw_wired = true;
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			break;
		case 'A':
			_keys['A'] = true;
			if (_draw_wired) {
				_draw_wired = false;
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else {
				_draw_wired = true;
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			break;
		}

	}
	void keyUp(unsigned char key) {
		switch (key) {
		case GLUT_KEY_UP:
			myCar->setForceStart(false);  _keys[GLUT_KEY_UP] = false; break;
		case GLUT_KEY_DOWN:
			myCar->setForceStart(false); _keys[GLUT_KEY_DOWN] = false; break;
		case GLUT_KEY_LEFT:
			_keys[GLUT_KEY_LEFT] = false; break;
		case GLUT_KEY_RIGHT:
			_keys[GLUT_KEY_RIGHT] = false; break;
		}
	}
	void keyPressed(unsigned char key) {

		switch (key) {

		case GLUT_KEY_UP:
			_keys[GLUT_KEY_UP] = true;

			break;
		case GLUT_KEY_DOWN:

			_keys[GLUT_KEY_DOWN] = true;

			break;
		case GLUT_KEY_LEFT:
			_keys[GLUT_KEY_LEFT] = true;
			break;
		case GLUT_KEY_RIGHT:
			_keys[GLUT_KEY_RIGHT] = true;
			break;
		}
	}
	void display() {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glViewport(0, 0, _width, _height);
		_currentCamera->computeProjectionMatrix();
		_currentCamera->update(_width, _height);
		_currentCamera->computeVisualizationMatrix();
		//background -> table
		for (int i = -10; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0)glColor3d(0.74902, 0.847059, 1.847059); //0.74902 green 0.847059 blue 0.847059
					else glColor3d(1, 1, 1);
					glPushMatrix();
					glTranslated(i, j, 0);
					glScaled(1, 1, 0);
					glutSolidCube(1);
					glPopMatrix();

					glPushMatrix();
					glTranslated(-i - 2, -j, 0);
					glScaled(1, 1, 0);
					glutSolidCube(1);
					glPopMatrix();
				}
				else {
					if (j % 2 == 1)glColor3d(0.74902, 0.847059, 1.847059);
					else glColor3d(1, 1, 1);
					glPushMatrix();
					glTranslated(i, j, 0);
					glScaled(1, 1, 0);
					glutSolidCube(1);
					glPopMatrix();

					glPushMatrix();
					glTranslated(-i, -j, 0);
					glScaled(1, 1, 0);
					glutSolidCube(1);
					glPopMatrix();
				}
			}

		}
		//draw stuff

		for (int i = 0; i < CHEERIOS_NUMBER; i++) {
			if (Cheerios[i] != NULL)
				Cheerios[i]->draw();
		}

		for (int i = 0; i < ORANGE_NUMBERS; i++) {
			if (i % 2 == 0) {
				Oranges[i]->draw1();
			}
			else Oranges[i]->draw2();
		}

		for (int i = 0; i < BUTTER_NUMBERS; i++) {
			Butters[i]->draw();
		}

		myCar->draw();

		glutSwapBuffers();
		glFlush();
	}
	void reshape(int w, int h) {
		glutReshapeWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glViewport(0, 0, w, h);
		_width = w;
		_height = h;
		//camera original
		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		float c = (xmax + xmin);
		xmax = c + xscale * w;
		xmin = c - xscale * w;
		c = (ymax + ymin);
		ymax = c + yscale * h;
		ymin = c - yscale * h;
		gluOrtho2D(xmin, xmax, ymin, ymax);*/
	}

	void onTimer() {
		_currentTime = glutGet(GLUT_ELAPSED_TIME);
		update((_currentTime - _lastTime));
		_lastTime = _currentTime;
		glutPostRedisplay();
	}
	void idle();
	inline void update(double delta_t) {
		actual_delta_t = delta_t;
		if (_keys[GLUT_KEY_UP] && !myCar->getForceStart()) {
			forward = 1;
			if (myCar->getSpecialSpeed() <= 0)
				myCar->setSpecialSpeed(myCar->getAcceleration());
			else if (myCar->getSpecialSpeed() < myCar->getMaxSpeed()) {
				myCar->setSpecialSpeed(myCar->getSpecialSpeed() + myCar->getAcceleration());
			}
		}
		if (_keys[GLUT_KEY_DOWN] && !myCar->getForceStart()) {
			forward = -1;
			if (myCar->getSpecialSpeed() >= 0)
				myCar->setSpecialSpeed(-myCar->getAcceleration());
			else if (myCar->getSpecialSpeed() > (-myCar->getMaxSpeed())) {
				myCar->setSpecialSpeed(myCar->getSpecialSpeed() - myCar->getAcceleration());
			}
		}
		if (_keys[GLUT_KEY_LEFT])
			myCar->turnLeft();
		if (_keys[GLUT_KEY_RIGHT])
			myCar->turnRight();


		if (myCar->getPosition().getX() >= 9.5 || myCar->getPosition().getX() <= -10 ||
			myCar->getPosition().getY() >= 9.5 || myCar->getPosition().getY() <= -9.5) {
			myCar = new Car();
		}
		myCar->update(delta_t);

		
		for (int i = 0; i < ORANGE_NUMBERS; i++) {
			if (myCar->HasColision(Oranges[i])) {
				myCar = new Car();
			}
			if (Oranges[i]->getPosition().getX() >= 9.5 || Oranges[i]->getPosition().getX() <= -10 ||
				Oranges[i]->getPosition().getY() >= 9.5 || Oranges[i]->getPosition().getY() <= -9.5) {
				Oranges[i]->setPosition(0, 0, 100);
				Oranges[i]->setSpeed(0, 0, 0);
				counter = delta_t + 5;
				LostOranges[i] = -1;

			}
			if (counter <= delta_t) {
				for (int i = 0; i < ORANGE_NUMBERS; i++) {
					if (LostOranges[i] == -1) {
						LostOranges[i] = 0;
						HelloOrange(i);
					}
				}
			}
			Oranges[i]->update(delta_t);
		}

		for (int i = 0; i < BUTTER_NUMBERS; i++) {
			if (myCar->HasColision(Butters[i])) {
				myCar->setForceStart(true);
				myCar->setPosition(positionBeforeCollision);
				Butters[i]->setSpeed(myCar->getDirection()*forward*0.005);
				
				myCar->setSpecialSpeed(0);

			}
			if (Butters[i]->getPosition().getX() >= 9.5 || Butters[i]->getPosition().getX() <= -10 ||
				Butters[i]->getPosition().getY() >= 9.5 || Butters[i]->getPosition().getY() <= -9.5) {
				Butters[i]->setPosition(0, 0, 100);
				Butters[i]->setSpeed(0, 0, 0);
			}
			Butters[i]->update(delta_t);
			positionBeforeCollision = myCar->getPosition();
		}

		for (int i = 0; i < BUTTER_NUMBERS; i++) {
			if (Butters[i]->getSpeed().getX() != 0 || Butters[i]->getSpeed().getY() != 0) {
				Butters[i]->setSpeed(Butters[i]->getSpeed()*0.9);

			}
			Butters[i]->update(delta_t);
		}

		for (int i = 0; i < CHEERIOS_NUMBER; i++) {
			if (Cheerios[i] != NULL) {
				if (myCar->HasColision(Cheerios[i])) {
					myCar->setPosition(positionBeforeCollision);
					myCar->setForceStart(true);
					Cheerios[i]->setSpeed(myCar->getDirection()*forward*0.005);
					
					myCar->setSpecialSpeed(0);
				}
				if (Cheerios[i]->getPosition().getX() >= 9.5 || Cheerios[i]->getPosition().getX() <= -10 ||
					Cheerios[i]->getPosition().getY() >= 9.5 || Cheerios[i]->getPosition().getY() <= -9.5) {
					Cheerio * aux;
					aux = new Cheerio(Cheerios[i]->getInitialPosition());
					delete Cheerios[i];
					Cheerios[i] = aux;
					//Cheerios[i]->setPosition(0, 0, 100);
					//Cheerios[i]->setSpeed(0, 0, 0);
				}
				Cheerios[i]->update(delta_t);
				positionBeforeCollision = myCar->getPosition();
			}
		}


		for (int i = 0; i < CHEERIOS_NUMBER; i++) {
			if (Cheerios[i] != NULL) {
				if (Cheerios[i]->getSpeed().getX() != 0 || Cheerios[i]->getSpeed().getY() != 0) {
					Cheerios[i]->setSpeed(Cheerios[i]->getSpeed()*0.9);

				}
				Cheerios[i]->update(delta_t);
			}
		}

		if (_currentCamera == Cameras[2]) {
			_currentCamera->setAt(myCar->getPosition().getX() + cos(myCar->getTurnAngle()), myCar->getPosition().getY() + sin(myCar->getTurnAngle()), myCar->getPosition().getZ() + .625/*some number to represent the car size*/);
			_currentCamera->setCenter(myCar->getPosition());
			_currentCamera->setUp(0, 0, 1);
		}

	}
	void init() {
		myCar = new Car();
		int currentCheerio = 0;

		//32 cheerios
		for (int i = -8; i < 8; i++) { //exterior horizontal
			Cheerios[currentCheerio++] = new Cheerio(i, 8, 0);
			Cheerios[currentCheerio++] = new Cheerio(i, -8, 0);
		}
		//20
		for (int i = -5; i < 5; i++) { // interior horizontal
			Cheerios[currentCheerio++] = new Cheerio(i, 5, 0);
			Cheerios[currentCheerio++] = new Cheerio(i, -5, 0);
		}
		//30
		for (int i = -7; i < 8; i++) { //exterior vertical
			Cheerios[currentCheerio++] = new Cheerio(-9, i, 0);
			Cheerios[currentCheerio++] = new Cheerio(8, i, 0);
		}
		//18

		for (int i = -4; i < 5; i++) { //interior vertical
			Cheerios[currentCheerio++] = new Cheerio(-6, i, 0);
			Cheerios[currentCheerio++] = new Cheerio(5, i, 0);
		}
		//Inicialization of objects here
		// Orange Initial position set here. 

		randOranges();
		// Butter Initial position set here.
		for (int i = 0; i < BUTTER_NUMBERS; i++) {
			Butters[i] = new Butter(rand() % 20 - 10, rand() % 20 - 10, 0);
		}

		/*Initiala camera*/
		float c = (xmax + xmin);
		xmax = c + xscale * _width;
		xmin = c - xscale * _height;
		c = (ymax + ymin);
		ymax = c + yscale * _height;
		ymin = c - yscale * _height;
		gluOrtho2D(xmin, xmax, ymin, ymax);
		Cameras[0] = new OrthogonalCamera(xmin, xmax, ymin, ymax, -100, 100);
		Cameras[1] = new PerspectiveCamera(90, 1, 5, -0.1);
		Cameras[2] = new PerspectiveCamera(90, 1, 0, -0.2, myCar);
		_currentCamera = Cameras[0];
	}
};
#endif
