#include "Reports.h"
#include"GameManager.h"



Report::Report(const Vec2 & _pos, Ball &_ball) :
	pos(_pos),
	ball(_ball)
{
}

void Report::update(Ball &_ball)
{
	if (_ball.kind == Ball::E_Compulsory ) {
		pos += 1.5*(_ball.pos - pos).normalized();
	}

	else if (_ball.kind == Ball::Dropped) {
	
		pos.y += 8.0;

	}

	


}

void Report::draw()
{
	Circle(pos, 20.0).draw();
}