#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace bangtal;
using namespace std;

int main() 
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	srand((unsigned int)time(NULL)); // 랜덤함수 초기화
	time_t start_time;
	time_t start_time1;

	
	auto scene = Scene::create("slide puzzle", "Images/루피.png");
	auto scene1 = Scene::create("Level 1", "Images/루피배경.png");  
	auto scene2 = Scene::create("Level 2", "Images/조로.png");
	auto scene3 = Scene::create("Level 2", "Images/조로배경.png");


	auto restart_button = Object::create("Images/restart.png", scene1, 100, 40, false);
	auto restart_button1 = Object::create("Images/restart.png", scene3, 100, 40, false);
	auto next_button = Object::create("Images/next.png", scene1, 1100, 40, false);
	auto finish_button = Object::create("Images/finish.png", scene3, 1100, 40, false);

	ObjectPtr board[9]; // 3 X 3 퍼즐 보드 생성
	ObjectPtr boardA[9]; // 체크할 보드 생성

	int blank = 8; // 빈공간 위치
	int blank1 = 8;
	for (int i = 0; i < 9; i++) {
		string filename = "Images/" + to_string(i + 1) + ".png";
		cout << filename << endl;

		board[i] = Object::create(filename, scene1, 365 + (i % 3) * 180, 440 - (i / 3) * 180);
		boardA[i] = board[i];
		board[i]->setOnMouseCallback([&](ObjectPtr object, int, int, MouseAction)->bool { // i값을 안쓰기 때문에 =가 아닌 &를 사용
			int j;
			for (j = 0; j < 9; j++) {
				if (board[j] == object)
					break;
			} 
			// 마우스 클릭시 blank의 상하좌우끼리만 바꿀수 있는 조건문 추가
			if ((j%3 > 0 && j-1 == blank) || (j%3 < 2 && j+1 == blank) || (j>2 && j-3 == blank) || (j<6 && j+3 == blank)){
				// 마우스 클릭시 화면의 이미지 바꿈
				board[j]->locate(scene1, 365 + (blank % 3) * 180, 440 - (blank / 3) * 180);
				board[blank]->locate(scene1, 365 + (j % 3) * 180, 440 - (j / 3) * 180);

				// board의 array를 바꿈
				board[j] = board[blank];
				board[blank] = object;
				blank = j;

				// 퍼즐 완성되는 루프
				int k;
				for (k = 0; k < 9; k++) {
					if (board[k] != boardA[k]) break;
				}
				if (k == 9) { // 처음퍼즐 완료
					auto end_time = time(NULL);
					cout << difftime(end_time, start_time) << endl;
					string buf = to_string(difftime(end_time, start_time)) + "초 걸렸습니다.";
					showMessage(buf.c_str());
					restart_button->show();
					next_button->show();
				}
			}
			return true;
		});
	}

	ObjectPtr board1[9]; // 2번쨰 퍼즐 보드 생성
	ObjectPtr boardA1[9]; // 체크할 보드 생성
	for (int a = 0; a < 9; a++) {
		string filename1 = "Images1/" + to_string(a + 1) + ".png";
		cout << filename1 << endl;

		board1[a] = Object::create(filename1, scene3, 372 + (a % 3) * 180, 445 - (a / 3) * 180);
		boardA1[a] = board1[a];
		board1[a]->setOnMouseCallback([&](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 9; j++) {
				if (board1[j] == object)
					break;
			}
			if ((j % 3 > 0 && j - 1 == blank1) || (j % 3 < 2 && j + 1 == blank1) || (j > 2 && j - 3 == blank1) || (j < 6 && j + 3 == blank1)) {
				board1[j]->locate(scene3, 372 + (blank1 % 3) * 180, 445 - (blank1 / 3) * 180);
				board1[blank1]->locate(scene3, 372 + (j % 3) * 180, 445 - (j / 3) * 180);
				board1[j] = board1[blank1];
				board1[blank1] = object;
				blank1 = j;

				int k;
				for (k = 0; k < 9; k++) {
					if (board1[k] != boardA1[k]) break;
				}
				if (k == 9) { 
					auto end_time1 = time(NULL);
					cout << difftime(end_time1, start_time1) << endl;
					string buf1 = to_string(difftime(end_time1, start_time1)) + "초 경과.";
					showMessage(buf1.c_str());
					restart_button1->show();
					finish_button->show();
				}
			}
			return true;
			});
	}

	board[blank]->hide();
	board1[blank1]->hide();

	// 타이머 루프를 이용하여 퍼즐 섞기
	auto count = 0;
	auto timer = Timer::create(0.05f);
	timer->setOnTimerCallback([&](TimerPtr timer1)->bool {
		cout << "timeout!!" << count << endl;
		
		int j = 0;
		do {
			switch (rand() % 4) { // 네가지 방향으로 움직임
			case 0: j = blank - 1; break; // 좌
			case 1: j = blank + 1; break; // 우
			case 2: j = blank - 3; break; // 하
			case 3: j = blank + 3; break; // 상
			}
		}
		// 움직이기 위한 조건-> j값이 board 안에 있도록 추가
		while (j < 0 || j > 8 || !((j % 3 > 0 && j - 1 == blank) || (j % 3 < 2 && j + 1 == blank) || (j > 2 && j - 3 == blank) || (j < 6 && j + 3 == blank)));
		board[j]->locate(scene1, 365 + (blank % 3) * 180, 440 - (blank / 3) * 180);
		board[blank]->locate(scene1, 365 + (j % 3) * 180, 440 - (j / 3) * 180);
		auto object = board[j]; // 없던 object 변수 생성
		board[j] = board[blank];
		board[blank] = object;
		blank = j;

		count++;
		if (count < 5) {
			timer1->set(0.05f);
			timer1->start();
		}
		return true;
	 });

	// start 버튼으로 게임시작
	auto start_button = Object::create("Images/start.png", scene, 590, 50);
	start_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		timer->start();
		start_time = time(NULL);
		return true;
	});
	
	// 재시작 버튼 -> 시간 초기화
	restart_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		count = 0;
		timer->start();
		start_time = time(NULL);
		return true;
	});

	// 다음 퍼즐
	next_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
	});

	// 다음 퍼즐 타이머 루프
	auto count1 = 0;
	auto timer_A = Timer::create(0.05f);
	timer_A->setOnTimerCallback([&](TimerPtr timer2)->bool {
		cout << "timeout!!" << count << endl;
		int b = 0;
		do {
			switch (rand() % 4) { 
			case 0: b = blank1 - 1; break; // 좌
			case 1: b = blank1 + 1; break; // 우
			case 2: b = blank1 - 3; break; // 하
			case 3: b = blank1 + 3; break; // 상
			}
		}
		while (b < 0 || b > 8 || !((b % 3 > 0 && b - 1 == blank1) || (b % 3 < 2 && b + 1 == blank1) || (b > 2 && b - 3 == blank1) || (b < 6 && b + 3 == blank1)));
		board1[b]->locate(scene3, 372 + (blank1 % 3) * 180, 445 - (blank1 / 3) * 180);
		board1[blank1]->locate(scene3, 372 + (b % 3) * 180, 445 - (b / 3) * 180);
		auto object_A = board1[b]; 
		board1[b] = board1[blank1];
		board1[blank1] = object_A;
		blank1 = b;

		count++;
		if (count < 5) {
			timer2->set(0.05f);
			timer2->start();
		}
		return true;
	});

	// 두번째 퍼즐 시작
	auto start_button1 = Object::create("Images/start.png", scene2, 590, 40);
	start_button1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene3->enter();
		count = 0;
		timer_A->start();
		start_time1 = time(NULL);
		return true;
		});

	// 두번째 퍼즐 재시작 -> 시간 초기화
	restart_button1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene3->enter();
		count = 0;
		timer_A->start();
		start_time1 = time(NULL);
		return true;
		});

	// 게임끝
	finish_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();
		return true;
		});

	startGame(scene);

	return 0;

}