#include "SirenManager.h"
#include"GameManager.h"

//SirenManager::SirenManager()
//reportA({0,0}),
//reportB({0,600}),
//reportC({800,600}),
//reportD({800,0})
//{
//}
/*
void SirenManager::update(Ball* ballptr)
{

if (ballptr->kind == Ball::E_Compulsory) {
reportA.update(ballptr);
reportB.update(ballptr);
reportC.update(ballptr);
reportD.update(ballptr);
}




}
*/



void SirenManager::draw()
{
	siren1.draw();
	for (auto&& report : reports) {
		report.draw();

	}
}

void SirenManager::update(Ball &_ball)
{
	
	for (auto&& report : reports) {
		
		report.update(_ball);

	}
	reporterase();

}



void SirenManager::add(Ball &_ball)
{
	if (_ball.kind == Ball::E_Compulsory && _ball.grabbed == true && reports.size()==0) {
		reports.emplace_back(Report({ 0,0 }, _ball));
		reports.emplace_back(Report({ 0,600 }, _ball));
		reports.emplace_back(Report({ 800,600 }, _ball));
		reports.emplace_back(Report({ 800,0 }, _ball));//各座標を持つ4つ一気に追加

	}//これ何回もよばれちゃうんじゃ←四個より小さいときにしたで
}

void SirenManager::reporterase()
{
	auto isout = [](Report repo) {return  !Circle(repo.pos, 25.0).intersects(Rect(Window::Size())); };
	auto rmvIter = std::remove_if(reports.begin(), reports.end(), isout);

	reports.erase(rmvIter, reports.end());

}

//!Circle(repo.pos,25.0).intersects(Rect(Window::Size()));