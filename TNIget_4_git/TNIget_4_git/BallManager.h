#pragma once
#include<Siv3D.hpp>
#include<vector>
#include<algorithm>
#include"Ball.h"
#include"TniBox.h"

class BallManager {
private:
	std::vector<Ball>balls;
public:
	TniBox SBox, YBox, RBox, KBox;
	int droptni = 0, Syu = 0, Yu = 0, Ryou = 0, Ka = 0;

	

	BallManager();

	void update();
	void draw();
	void add(int _conf);
	void checkerase();
	int ballnum();
	int randomrange = 5;

	void dropcheck(Ball &_ball);




};

extern BallManager ballmanager;