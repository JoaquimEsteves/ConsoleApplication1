#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "Camera.h"
#include "Vector3.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Butter.h"
#include "Car.h"
#include "Orange.h"
#include "Road.h"
#include "GL\glut.h"
#include <math.h>

#define CARSPEED 0.005

class GameManager {

	/*Deviam ser ponteiros? Assumo que sim*/
	//std::vector<Camera *> _cameras; //vectr ou list?
	//std::vector<GameObject *> _game_objects;
	//std::vector<LightSource *> _light_sources;
	bool draw_wired = false;
	Car  * c;
	int currentTime;
	int lastTime = 0;

public:
	inline GameManager() {
		c = new Car();
	}
	inline ~GameManager() {}

	/*std::vector<Camera *> getCameras();
	std::vector<GameObject *> getObjects();
	std::vector<LightSource *> getLightSources();
	void setCameras(std::vector<Camera *> v);
	void setObjects(std::vector<GameObject *> v);
	void setLightSources(std::vector<LightSource *> v);*/

	void keyPressed(unsigned char key) {
		switch (key) {
		case 'a': 
			if (draw_wired) {
				draw_wired = false;
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else {
				draw_wired = true;
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			break;
			
		case 'A': 
			if (draw_wired) {
				draw_wired = false;
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else {
				draw_wired = true;
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			break;
				//nothing to do yet
		case 't':
			c->setSpeed(c->getSpeed().getX() + 1 * CARSPEED, c->getSpeed().getY(), 0); break;
			//c->setSpeed((1 + c->getDirection().getX()) * CARSPEED,
			//			(1 + c->getDirection().getY()) * CARSPEED,
			//			0); break;
		case 'g':
			c->setSpeed(c->getSpeed().getX() -1 * CARSPEED, c->getSpeed().getY(), 0); break;
			//c->setSpeed(-(1 + c->getDirection().getX()) * CARSPEED,
			//			 - ((1 + c->getDirection().getY())) * CARSPEED,
			//			0); break;
		case 'f':
			c->turnLeft(); break;
		case 'h':
			c->turnRight(); break;
		}
	}
	void display() {
			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//background -> table
			for (int i = -10; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i % 2 == 0) {
						if (j % 2 == 0)glColor3d(0.74902, 0.847059, 1.847059); //0.74902 green 0.847059 blue 0.847059
						else glColor3d(1, 1, 1);
						glPushMatrix();
						glTranslated(i, j, 0);
						glutSolidCube(1);
						glPopMatrix();

						glPushMatrix();
						glTranslated(-i - 2, -j, 0);
						glutSolidCube(1);
						glPopMatrix();
					}
					else {
						if (j % 2 == 1)glColor3d(0.74902, 0.847059, 1.847059);
						else glColor3d(1, 1, 1);
						glPushMatrix();
						glTranslated(i, j, 0);
						glutSolidCube(1);
						glPopMatrix();

						glPushMatrix();
						glTranslated(-i, -j, 0);
						glutSolidCube(1);
						glPopMatrix();
					}
				}

			}

			//draw stuff

			Orange *o = new Orange();
			o->draw();
			Butter * b = new Butter();
			b->draw();
			c->draw();
			Road *rs = new Road();
			rs->draw();

			glutSwapBuffers();
	}
	void reshape(int width, int height) {
		const float ar = (float)width / (float)height;

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
		glOrtho(-12.0f*ar, 12.0f*ar, -12.0f, 12.0f*ar, -5.0f*ar, 5.0f*ar);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void keyPressed();
	void onTimer(){
		currentTime = glutGet(GLUT_ELAPSED_TIME);
		update((currentTime - lastTime));
		lastTime = currentTime;
	}
	void idle();
	inline void update(double delta_t) {
		c->update(delta_t);
		glutPostRedisplay();
	}
	void init() {
		c = new Car();
	}
};
#endif