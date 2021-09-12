#include <bangtal>
using namespace bangtal;

int main() {
	auto scene = Scene::create("산타레이스", "C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/background.png");
	auto santaX = 0, santaY = 500;
	auto santa = Object::create("C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/santa.png", scene, santaX, santaY);
	
	auto startButton = Object::create("C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/start.png", scene, 590, 70);
	auto endButton = Object::create("C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/end.png", scene, 590, 20);
	auto playButton = Object::create("C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/play.png", scene, 610, 30, false);

	auto timer = Timer::create(10.f);
	showTimer(timer);
	timer->setOnTimerCallback([&](TimerPtr)->bool {
		showMessage("선물 배달 실패!");
		
		startButton->show();
		startButton->setImage("C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/restart.png");
		endButton->show();
		playButton->hide();

		return true;
		});

	

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		endButton->hide();
		playButton->show();
		
		santaX = 0;
		santa->locate(scene, santaX, santaY);
		timer->set(10.f);
		timer->start();

		return true;
		});

	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		
		endGame();
		return true;
		});


	playButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		santaX = santaX + 50;
		santa->locate(scene, santaX, santaY);

		if (santaX > 1280) {
			showMessage("선물 배달 성공!");
			timer->stop();

			startButton->show();
			startButton->setImage("C:/Users/URBAN/OneDrive/Desktop/SantaRace/bangtal.cpp-master/bangtal.cpp-master/SantaRace/Images/restart.png");
			endButton->show();
			playButton->hide();

		}
		return true;

	});



	//게임을 시작한다
	startGame(scene);

	return 0;
}
