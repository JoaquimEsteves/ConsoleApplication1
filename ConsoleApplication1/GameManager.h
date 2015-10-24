#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#define ORANGE_NUMBERS 3
#define BUTTER_NUMBERS 5
#define CAMERA_NUMBER 3

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

class GameManager {

	/*Deviam ser ponteiros? Assumo que sim*/
	 //vectr ou list?
	//std::vector<GameObject *> _game_objects;
	//std::vector<LightSource *> _light_sources;
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
	Butter * Butters[BUTTER_NUMBERS];
	Camera * Cameras[CAMERA_NUMBER];

public:
	inline GameManager() {
		myCar = new Car();
		//Inicialization of objects here
		// Orange Initial position set here. 
		srand(time(NULL));
		Oranges[0] = new Orange(rand() % 10 -9,0, 0);
		Oranges[1] = new Orange(rand() % 5 -5, 0, 0);
		Oranges[2] = new Orange(rand() % 10 + 1, 0, 0);
		// Butter Initial position set here.
		Butters[0] = new Butter(-6, 2, 0);
		Butters[1] = new Butter(4, 7.7, 0);
		Butters[2] = new Butter(0, 0, 0);
		Butters[3] = new Butter(7, -7, 0);
		Butters[4] = new Butter(-4, -1, 0);
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
	inline ~GameManager() {}

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
				_keys[GLUT_KEY_UP] = false; break;
			case GLUT_KEY_DOWN:
				_keys[GLUT_KEY_DOWN] = false; break;
			case GLUT_KEY_LEFT:
				_keys[GLUT_KEY_LEFT] = false; break;
			case GLUT_KEY_RIGHT:
				_keys[GLUT_KEY_RIGHT] = false; break;
		}
	}
	void keyPressed(unsigned char key) {
		//double rotationX;
		//double rotationY;
		//double ANGLE = 0.1;
		switch (key) {

		case GLUT_KEY_UP:
			_keys[GLUT_KEY_UP] = true;
			/*if (c->getSpecialSpeed() <= 0)
				c->setSpecialSpeed(c->getAcceleration()); 
			else if(c->getSpecialSpeed() < c->getMaxSpeed()) {
				c->setSpecialSpeed(c->getSpecialSpeed() + c->getAcceleration());
			}*/
			//c->setSpeed(0, 1 * CARSPEED, 0); 
			/*if (c->getSpeed().getX() == 0 || c->getSpeed().getY() == 0) {
				c->setSpeed(1*cos(ANGLE), 1*sin(ANGLE), 0);
			}
			if (c->getSpeed().getX() == 5 || c->getSpeed().getY() == 5) {
				c->setSpeed(5*cos(ANGLE), 5*sin(ANGLE), 0);
			}
			else {
				c->setSpeed((c->getSpeed().getX()+1)*cos(ANGLE), (c->getSpeed().getY()+1)*sin(ANGLE), 0);
			} */
			break;

		case GLUT_KEY_DOWN:
			_keys[GLUT_KEY_DOWN] = true;
			//c->setSpecialSpeed(-1);
			/*if (c->getSpecialSpeed() >= 0)
				c->setSpecialSpeed(-c->getAcceleration());
			else if (c->getSpecialSpeed() > (- c->getMaxSpeed())) {
				c->setSpecialSpeed(c->getSpecialSpeed() - c->getAcceleration());
			}*/

			//c->setSpeed(0, -1 * CARSPEED, 0); 
			/*if (c->getSpeed().getX() == 0 || c->getSpeed().getY() == 0) {
				c->setSpeed(0, 0, 0);
			}
			else {
				c->setSpeed((c->getSpeed().getX() -1)*cos(ANGLE), (c->getSpeed().getY() -1)*sin(ANGLE), 0);
			}*/
			break;

		case GLUT_KEY_LEFT:
			_keys[GLUT_KEY_LEFT] = true;
			//c->turnLeft(); 
			/*rotationX = cos(ANGLE) - sin(ANGLE) - (c->getPosition().getX()*cos(ANGLE)) + (c->getPosition().getY()*sin(ANGLE)) + c->getPosition().getX();
			rotationY = sin(ANGLE) + cos(ANGLE) - (c->getPosition().getX()*sin(ANGLE)) - (c->getPosition().getY()*cos(ANGLE)) + c->getPosition().getY();
			c->setPosition(rotationX, rotationY, 0);*/
			break;
		case GLUT_KEY_RIGHT:
			_keys[GLUT_KEY_RIGHT] = true;
			//c->turnRight(); 
			/*rotationX = cos(-ANGLE) - sin(-ANGLE) - (c->getPosition().getX()*cos(-ANGLE)) + (c->getPosition().getY()*sin(-ANGLE)) + c->getPosition().getX();
			rotationY = sin(-ANGLE) + cos(-ANGLE) - (c->getPosition().getX()*sin(-ANGLE)) - (c->getPosition().getY()*cos(-ANGLE)) + c->getPosition().getY();
			c->setPosition(rotationX, rotationY, 0); */
			break;
		}
	}
	void display() {
			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//glViewport(0, 0, _width, _height);
			_currentCamera->computeProjectionMatrix();
			_currentCamera->update( _width, _height);
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

			for (int i = 0; i < 1; i++) {
				Oranges[i]->draw();
			}
			for (int i = 0; i < BUTTER_NUMBERS; i++) {
				Butters[i]->draw();
			}
			myCar->draw();
			Road *rs = new Road();
			rs->draw();

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
	void keyPressed();

	void onTimer(){
		_currentTime = glutGet(GLUT_ELAPSED_TIME);
		update((_currentTime - _lastTime));
		_lastTime = _currentTime;
		glutPostRedisplay();
	}
	void idle();
	inline void update(double delta_t) {
		if (_keys[GLUT_KEY_UP]) {
			if (myCar->getSpecialSpeed() <= 0)
				myCar->setSpecialSpeed(myCar->getAcceleration());
			else if (myCar->getSpecialSpeed() < myCar->getMaxSpeed()) {
				myCar->setSpecialSpeed(myCar->getSpecialSpeed() + myCar->getAcceleration());
			}
		}
		if (_keys[GLUT_KEY_DOWN]) {
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

		myCar->update(delta_t);
		/*if (myCar->HasColision(Oranges[0]))
			myCar->setPosition(0, 4, 0);*/
		
		for (int i = 0; i < 1; i++) {
			if (myCar->HasColision(Oranges[i])) {
				//Oranges[i]->setSpeed(0,0,0);
				myCar->setSpeed(0, 0, 0);
				myCar->setPosition(0, 4, 0);//initial position
			}
			Oranges[i]->update(delta_t);

		}
		
		if(_currentCamera == Cameras[2]){
			//if (myCar->getDirection().getX() < 0) {
			//	_currentCamera->setAt(myCar->getPosition().getX() + cos(PI * myCar->getTurnAngle()), myCar->getPosition().getY() - sin(PI * myCar->getTurnAngle()), myCar->getPosition().getZ() + 2/*some number to represent the car size*/);
			//}
			//else
			_currentCamera->setAt(myCar->getPosition().getX() + cos(myCar->getTurnAngle()), myCar->getPosition().getY() + sin(myCar->getTurnAngle()), myCar->getPosition().getZ() +.625/*some number to represent the car size*/);
			//_currentCamera->getAt().invert();
			_currentCamera->setCenter(myCar->getPosition());
			//_currentCamera->getCenter().invert();

			/*set center as carx + cos R; cary + sinR, car Z*/
			_currentCamera->setUp(0,0,1);
		}

	}
	void init() {
		myCar = new Car();
	}
};
#endif
