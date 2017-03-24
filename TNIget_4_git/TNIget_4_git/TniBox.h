#pragma once
#include<Siv3D.hpp>

class TniBox {
public:

	Vec2 drawpos;
	double wide, hight;


	TniBox(const Vec2 _drawpos);
	Rect Box;
	void draw();

};