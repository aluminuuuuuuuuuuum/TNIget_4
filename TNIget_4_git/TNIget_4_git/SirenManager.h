#pragma once
#include<vector>
#include<algorithm>
#include"Siren1.h"
#include"Reports.h"
#include"Ball.h"



class SirenManager {
public:
	std::vector<Report> reports;
	Siren1 siren1;

	//Report reportB(Ball* _ballptr), reportC(Ball* _ballptr), reportD(Ball* _ballptr);

	

	void draw();
	void update(Ball &_ball);
	void add(Ball &_ball);
	void reporterase();





};