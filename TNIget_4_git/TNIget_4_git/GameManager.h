#pragma once
#include"BallManager.h"
#include"SirenManager.h"

class GameManager {

public:
	BallManager ballmanager;
	SirenManager sirenmanager;

	GameManager();

	//void update();
	//void draw();


};

extern GameManager gamemanager;