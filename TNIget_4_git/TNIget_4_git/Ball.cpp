#include "Ball.h"


Ball::Ball(const Vec2 & _pos, Kind _kind, int _conf) :
	pos(_pos),
	kind(_kind),
	hankei(30.0),
	Speed(4.0),
	grabbed(false),
	flagz(_conf),
	cir(_pos, hankei)
{

}

void Ball::update()
{
	Circle cirr(pos, hankei);
	//------------------------------------------------------------------------------------------------------------------
	if (flagz == 1) {
		//Circle cirr(pos, hankei);

		//ボールとマウスの処理
		if (cirr.leftClicked) {
			grabbed = true;
		}
		else if (Input::MouseL.released) {
			grabbed = false;
		}
		else if (grabbed&&kind != Dropped) {

			pos.y -= Speed;
			pos += Mouse::Delta();
			//
			if (kind == Easy) {
			
				if (Input::KeyC.clicked) pos = { 707,365 };

			}
			//
		}

		if (kind == Normal || kind == Easy) { pos.y += Speed; }
		if (kind == Compulsory || kind == E_Compulsory) { Speed = 2.0; pos.y += Speed; }
		if (kind == Dropped) { Speed = 8.0; pos.y += Speed; }
	}
	//--------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------
	else if (flagz == 0) {
		//Circle cirr(pos, 30.0);
		//ボールとマウスの処理----------------------------------------------------------
		if (cirr.mouseOver) {
			if (Input::MouseL.pressed&&flag == 1) {}//なにもなし
			if (Input::MouseL.pressed&&flag == 0) {
				flag = 0;
				if (kind != Dropped) {
					pos.y -= Speed;
					pos += Mouse::Delta();
				}
			}
			else {
				if (Input::MouseL.pressed == false) flag = 0;//カーソルが上にあるだけの時
			}

		}
		else {//カーソルが触れていないとき
			if (Input::MouseL.pressed == true) flag = 1;//触れてないのに押してるとき
			else flag = 0;//触れてないし押してないとき
		}
		//-------------------------------------------------------------
		if (kind == Normal || kind == Easy) { pos.y += Speed; }
		if (kind == Compulsory || kind == E_Compulsory) { Speed = 2.0; pos.y += Speed; }
		if (kind == Dropped) { Speed = 8.0; pos.y += Speed * 2; }


	}
	//-----------------------------------------------------------------------------------------------------------------------
}

void Ball::draw()
{
	if (kind == Normal) {
		Circle(pos, hankei).draw(Color(r, g, b));
		ch(L"単位").drawCenter(pos, Palette::Black);
	}
	else if (kind == Compulsory) {
		Circle(pos, hankei).draw(Palette::Yellow);
		ch(L"必修").drawCenter(pos, Palette::Black);
	}
	else if (kind == E_Compulsory) {
		Circle(pos, hankei).draw(Palette::Pink);
		ch(L"選必").drawCenter(pos, Palette::Black);
	}
	else if (kind == Easy) {
		Circle(pos, hankei).draw(Palette::Yellowgreen);
		ch(L"単位").drawCenter(pos, Palette::Black);
	}
	else if (kind == Dropped) {
		Circle(pos, hankei).draw(Palette::Gray);
		ch(L"落").drawCenter(pos, Palette::Black);
	}
}
