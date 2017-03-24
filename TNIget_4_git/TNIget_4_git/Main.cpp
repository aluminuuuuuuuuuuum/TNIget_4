# include <Siv3D.hpp>
#include"GameManager.h"

void Main()
{
	Window::Resize(800, 600);
	const Font font(25);
	const Font Bfont(100);
	//BallManager ballmanager;
	int conf = 1;
	int num = 1;
	int test=22;

	while (System::Update())
	{

		switch (num)
		{


		case 1:

			//font(L"TNI").draw(350, 275);
			Bfont(L"単位").draw(250, 150);

			font(L"conf:", conf, L"range", gamemanager.ballmanager.randomrange).draw();

			if (Input::Key0.clicked) {
				if (conf == 0) {
					conf = 1;
				}

				else conf = 0;
			}

			if (Input::Key1.clicked) {
				if (gamemanager.ballmanager.randomrange == 5) {
					gamemanager.ballmanager.randomrange = 2;
				}

				else gamemanager.ballmanager.randomrange = 5;
			}


			if (Input::KeyEnter.clicked)num = 2;
			break;


		case 2://ゲーム画面

			   //ボール処理----------------
			gamemanager.ballmanager.update();
			gamemanager.ballmanager.draw();
			if (Input::KeyZ.clicked)gamemanager.ballmanager.add(conf);
			//--------------------------

			//テキスト----------------------------------
			font(L"現在降ってる単位：", gamemanager.ballmanager.ballnum(), L"\n落単:", gamemanager.ballmanager.droptni, L" 秀:", gamemanager.ballmanager.Syu, L" 優:", gamemanager.ballmanager.Yu, L" 良:", gamemanager.ballmanager.Ryou, L" 可:", gamemanager.ballmanager.Ka).draw();
			font(L"conf:", conf).draw(650, 550);
			//font(L"aaaa", gamemanager.sirenmanager.reports.size()).draw(100, 100);

			font(L"秀").draw(gamemanager.ballmanager.SBox.drawpos, Palette::Black);
			font(L"優").draw(gamemanager.ballmanager.YBox.drawpos, Palette::Black);
			font(L"良").draw(gamemanager.ballmanager.RBox.drawpos, Palette::Black);
			font(L"可").draw(gamemanager.ballmanager.KBox.drawpos, Palette::Black);
			//------------------------------------------


			//ケース移行---------------------------------
			if (Input::Key0.clicked)num = 1;

			break;


		case 3:


			break;


		}
	}
}