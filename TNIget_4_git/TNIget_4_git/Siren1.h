#pragma once
#include<Siv3D.hpp>

class Siren1 {
public:
	Vec2 pos;

	Rect and_over60{ pos.x,pos.y,30,300 };

	Siren1();

	void draw();

};