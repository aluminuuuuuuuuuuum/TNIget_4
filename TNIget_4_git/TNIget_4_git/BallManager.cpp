#include "BallManager.h"
#include"GameManager.h"

//コンストラクター---------------------------------------------------------
BallManager::BallManager() :
	SBox({ 670,10 }),
	YBox({ 670,120 }),
	RBox({ 670,230 }),
	KBox({ 670,330 })
{
}

//-------------------------------------------------------------
//------------------------------------------------------------
void BallManager::update()
{
	SBox.draw();
	YBox.draw();
	RBox.draw();
	KBox.draw();


	for (auto&& ball : balls) {
		dropcheck(ball);
		ball.update();
		gamemanager.sirenmanager.add(ball);
		gamemanager.sirenmanager.update(ball);
	}

	checkerase();
}

//-----------------------------------------------------------------


void BallManager::draw()
{
	for (auto&& ball : balls) {
		ball.draw();
	}

	gamemanager.sirenmanager.draw();
}

//---------------------------------------------------------------------


void BallManager::add(int _conf)
{
	int z;
	z = Random(1, randomrange);
	if (z == 1 || z == 2) { balls.emplace_back(Ball({ Random(30,510),0 }, Ball::Normal, _conf)); }
	else if (z == 3) { balls.emplace_back(Ball({ Random(30,510),0 }, Ball::Compulsory, _conf)); }
	else if (z == 4) { balls.emplace_back(Ball({ Random(30,510),0 }, Ball::E_Compulsory, _conf)); }
	else if (z == 5) { balls.emplace_back(Ball({ Random(30,510),0 }, Ball::Easy, _conf)); }
}


//---------------------------------------------------------------------------

void BallManager::checkerase()
{
	//画面外に出た時の削除---------------------------------
	auto isout = [&](Ball _ball) {if (_ball.pos.y >= 630)droptni += 1; return !Circle(_ball.pos, _ball.hankei).intersects(Rect(Window::Size())); };//関数定義
	auto rmvIter = std::remove_if(balls.begin(), balls.end(), isout);
	balls.erase(rmvIter, balls.end());
	//---------------------------------

	//秀判定と削除---------------------
	auto isboxSyu = [&](Ball _ball) {if (SBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false)Syu += 1; return SBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false; };
	auto rmvIterSyu = std::remove_if(balls.begin(), balls.end(), isboxSyu);

	balls.erase(rmvIterSyu, balls.end());

	//---------------------------------

	//優判定と削除---------------------
	auto isboxinYu = [&](Ball _ball) {if (YBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false)Yu += 1; return YBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false; };
	auto rmvIterYu = std::remove_if(balls.begin(), balls.end(), isboxinYu);

	balls.erase(rmvIterYu, balls.end());
	//---------------------------------

	//良判定と削除---------------------
	auto isboxinRyou = [&](Ball _ball) {if (RBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false)Ryou += 1; return RBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false; };
	auto rmvIterRyou = std::remove_if(balls.begin(), balls.end(), isboxinRyou);

	balls.erase(rmvIterRyou, balls.end());
	//---------------------------------

	//可判定と削除----------------------
	auto isboxinKa = [&](Ball _ball) {if (KBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false)Ka += 1; return KBox.Box.contains(Circle(_ball.pos, 30.0)) && Input::MouseL.pressed == false; };
	auto rmvIterKa = std::remove_if(balls.begin(), balls.end(), isboxinKa);

	balls.erase(rmvIterKa, balls.end());
	//----------------------------------

	//---------------------------------------------------------------------------------------------------------

}


//---------------------------------------------------------------------

int BallManager::ballnum()
{
	return balls.size();
}


//-----------------------------------------------------------------------


void BallManager::dropcheck(Ball &_ball)
{
	Circle circle(_ball.pos, _ball.hankei);
	//kindをDroppedにする関数,update関数にブチ込む
	if (circle.intersects(gamemanager.sirenmanager.siren1.and_over60)) { _ball.kind = Ball::Dropped; }


	//------------------
	if (_ball.kind == Ball::E_Compulsory) {

		//if(circle.intersects(sirenmanager.reports[1]))
		for (auto&& report : gamemanager.sirenmanager.reports) {
			
			if (circle.intersects(Circle(report.pos, 25.0))) { 
			_ball.kind = Ball::Dropped;
			
			
			}

		}



	}



}