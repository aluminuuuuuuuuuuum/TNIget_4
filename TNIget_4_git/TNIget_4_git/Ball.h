#pragma once
#include<Siv3D.hpp>

class Ball {
public:

	Vec2 pos;
	double hankei;
	double Speed;
	Font ch{ 15 };
	int r = 255, g = 255, b = 255;
	bool grabbed;
	int flagz;
	int flag = 0;
	int hit=0;
	Circle cir;

	enum Kind {

		Normal,
		Compulsory,
		E_Compulsory,
		Dropped,
		Easy

	};

	Kind kind;

	Ball(const Vec2& _pos, Kind _kind, int _conf);

	void update();
	void draw();

};