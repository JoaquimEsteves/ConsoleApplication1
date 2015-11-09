#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#define ORANGE_NUMBERS 3
#define BUTTER_NUMBERS 6
#define CAMERA_NUMBER 3
#define CHEERIOS_NUMBER 100
#define LIGHTS_NUMBER 7

#include "Camera.h"
#include "LightSource.h"
#include "Vector3.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Butter.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
#include "Cheerio.h"
#include "Candle.h"
#include "Background.h"
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
	LightSource * Lights[LIGHTS_NUMBER];
	Candle * Candles[LIGHTS_NUMBER];
	bool _day = true;
	bool _lights_on = false;
	bool _lights_active = false;

	double counter = 0;
	int lostOrange;
	//Vector3 positionBeforeCollision;
	int forward;
	double counter_delta_t = 10;
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
		//if (i % 2 == 0) {
		if (Oranges[i] == NULL) {
			Oranges[i] = new Orange(rand() % 18 - 18 / 2, 9, .5);
		}
		else {
			Oranges[i]->setPosition(rand() % 18 - 18 / 2, 9, .5);
			Oranges[i]->setCounter(rand() % 20 + 1);
		}
		Oranges[i]->setSpeed(0, (rand() % 5 + 5)*0.0003*speeder, 0);
		Oranges[i]->setTurnAngle(-(Oranges[i]->getSpeed().getY()));
	}
	void randOranges() {

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
		case 'n':
			Lights[0]->setState((_day = (!_day)));
			break;

		case 'l':
			if ((_lights_active = (!_lights_active))) glEnable(GL_LIGHTING);
			else glDisable(GL_LIGHTING);
			break;

		case 'g':
			break;

		case 'c':
			_lights_on = (!_lights_on);
			for (int i = 1; i < LIGHTS_NUMBER; i++) {
				Lights[i]->setState(_lights_on);
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

	void handleKeyBuffer() {
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
	}

	

	void display() {
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glViewport(0, 0, _width, _height); <----vestigial code
		_currentCamera->computeProjectionMatrix();
		_currentCamera->update(_width, _height);
		_currentCamera->computeVisualizationMatrix();
		//background -> table
		//draw_background();
		Background * background = new Background();
		background->draw();
		//draw stuff
		for (int i = 1; i < 7; i++) {
			Candles[i]->draw(_lights_on);
		}

		for (int i = 0; i < CHEERIOS_NUMBER; i++) {
			if (Cheerios[i] != NULL)
				Cheerios[i]->draw();
		}
		for (int i = 0; i < BUTTER_NUMBERS; i++) {
			Butters[i]->draw();
		}
		for (int i = 0; i < ORANGE_NUMBERS; i++) {
			Oranges[i]->draw();
		}
		myCar->draw();
		for (int i = 0; i < LIGHTS_NUMBER; i++) {
			Lights[i]->draw();
		}
		
		if (_lights_active)	glEnable(GL_LIGHTING);
		else glDisable(GL_LIGHTING);
		

		glutSwapBuffers();
		//glFlush();
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
		handleKeyBuffer();
		myCar->update(delta_t);


		for (int i = 0; i < ORANGE_NUMBERS; i++) {
			if (Oranges[i]->getCounter() <= delta_t) {
				if (Oranges[i]->getLost() == -1) {
					Oranges[i]->setLost(0);
					HelloOrange(i);
				}
			}
			Oranges[i]->update(delta_t, myCar);
		}

		for (int i = 0; i < BUTTER_NUMBERS; i++) {
			Butters[i]->update(delta_t, myCar, forward);
		}

		for (int i = 0; i < CHEERIOS_NUMBER; i++) {
			Cheerios[i]->update(delta_t, myCar, forward);
		}

		if (_currentCamera == Cameras[2]) {
			_currentCamera->setAt(myCar->getPosition().getX() + cos(myCar->getTurnAngle()), myCar->getPosition().getY() + sin(myCar->getTurnAngle()), myCar->getPosition().getZ() + .625/*some number to represent the car size*/);
			_currentCamera->setCenter(myCar->getPosition());
			_currentCamera->setUp(0, 0, 1);
		}

	}
	void init() {
		srand(time(NULL));
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
			Butters[i] = new Butter(rand() % 17 - 8, rand() % 17 - 8, .5);
			//WHILE HAS COLLISION
			while (myCar->HasColision(Butters[i]))
				Butters[i]->setPosition(rand() % 17 - 8, rand() % 17 - 8, .5);
		}

		/*Inicialize the lights*/
		/*direccional light*/
		//falta alterar este (letra N)
		Lights[0] = new LightSource(0);
		Lights[0]->setPosition(-.5, 0, 10);
		Lights[0]->setDirection(0, 0, -1);
		Lights[0]->setSpecular(1.0, 1.0, 1.0, 1.0);
		Lights[0]->setDiffuse(1.0, 1.0, 1.0, 1.0);
		Lights[0]->setAmbient(1, 1, 1, 1.0);
		Lights[0]->setState(true);
		Lights[0]->setCutOff(180);
		
		for (int i = 1; i < LIGHTS_NUMBER; i++) {
			Lights[i] = new LightSource(i);
			Lights[i]->setSpecular(1.0, 1.0, 1.0, 1.0);
			Lights[i]->setDiffuse(1.0, 1.0, 1.0, 1.0);
			Lights[i]->setAmbient(1, 1, 1, 1.0);
			Lights[i]->setDirection(0, 0, -1);
			Lights[i]->setState(_lights_on);
			//Lights[i]->setCutOff(180);
			//Lights[i]->setExponent(0);
			Lights[i]->setAttenuation(true);
			
		}
		

		Lights[1]->setPosition(-10, 9, 1.5);
		//Lights[1]->setDirection(-10, 9, 1.5);
		Candles[1]=new Candle(-10, 9, 0);

		Lights[2]->setPosition(-10, 0, 1.5);
		Candles[2]=new Candle(-10, 0, 0);

		Lights[3]->setPosition(-10, -9, 1.5);
		Candles[3]=new Candle(-10, -9, 0);

		Lights[4]->setPosition(9, -9, 1.5);
		Candles[4]=new Candle(9, -9, 0);

		Lights[5]->setPosition(9, 0, 1.5);
		Candles[5]=new Candle(9, 0, 0);

		Lights[6]->setPosition(9, 9, 1.5);
		Candles[6]=new Candle(9, 9, 0);


		if (_lights_active) {
			glEnable(GL_LIGHTING);
		}
		else {
			glDisable(GL_LIGHTING);
		}
		/*Initiala camera*/
		float c = (xmax + xmin);
		xmax = c + xscale * _width;
		xmin = c - xscale * _height;
		c = (ymax + ymin);
		ymax = c + yscale * _height;
		ymin = c - yscale * _height;
		gluOrtho2D(xmin, xmax, ymin, ymax);
		Cameras[0] = new OrthogonalCamera(xmin, xmax, ymin, ymax, -110, 110);
		Cameras[1] = new PerspectiveCamera(90, 1, 5, -0.1);
		Cameras[2] = new PerspectiveCamera(120, 1, .1, -0.2, myCar);
		_currentCamera = Cameras[0];
	}
};
#endif
