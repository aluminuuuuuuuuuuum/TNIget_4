#include"TniBox.h"

TniBox::TniBox(const Vec2 _drawpos) :
	drawpos(_drawpos),
	wide(100),
	hight(90),
	Box(drawpos.x, drawpos.y, wide, hight)
{
}

void TniBox::draw()
{
	Rect(drawpos.x, drawpos.y, wide, hight).draw();
}
