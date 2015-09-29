
#include "Camera.h"
#include "Vector3.h"
#include "LightSource.h"
#include "GameObject.h"
#include "GL\glut.h"
#include <vector>
#include <map>
#include <list>
#include <iostream>

class GameManager {

	/*Deviam ser ponteiros? Assumo que sim*/
	std::vector<Camera *> _cameras; //vectr ou list?
	std::vector<GameObject *> _game_objects;
	std::vector<LightSource *> _light_sources;


public:
	GameManager();
	~GameManager();

	std::vector<Camera *> getCameras();
	std::vector<GameObject *> getObjects();
	std::vector<LightSource *> getLightSources();
	void setCameras(std::vector<Camera *> v);
	void setObjects(std::vector<GameObject *> v);
	void setLightSources(std::vector<LightSource *> v);

	void display(void);
	void reshape(GLsizei w, GLsizei h); //NÃO ESTOU A ENCONTRAR O DIABO DO GLUT OUTRA VEZ
	void keyPressed();
	void onTimer();
	void idle();
	void update();
	void init();
};