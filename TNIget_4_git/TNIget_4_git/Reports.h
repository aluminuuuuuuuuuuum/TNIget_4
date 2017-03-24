#pragma once
#include<Siv3D.hpp>
#include"Ball.h"

class Report {
public:
	Vec2 pos;
	Ball ball;
	int hits = 0;

	Report(const Vec2& _pos, Ball &_ball);

	void update(Ball &_ball);
	void draw();


};