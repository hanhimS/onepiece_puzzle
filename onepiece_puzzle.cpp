#include<Bangtal.h>
#pragma comment(lib, "Bangtal.lib")
#include <random>
#include <iterator>
#include <iostream>

SceneID  scene1, scene2, scene3, scene4;
ObjectID board1[3][3], board2[3][3];
ObjectID start, start1, a00, a01, a02, a10, a11, a12, a20, a21, b00, b01, b02, b10, b11, b12, b20, b21, blank, blank2, restart, restart1, next;
TimerID timer;

ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}

int boardX1[3] = {
	365, 545, 725
};

int boardY1[3] = {
	440, 260, 80
};

int board2X[3] = {
	372, 552, 732
};

int board2Y[3] = {
	445, 265, 85
};

const int move = 180;

auto mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	int t1;
	int flag1 = 0;
	int t2;
	int flag2 = 0;
	if (object == start) {
		enterScene(scene2);
		startTimer(timer);
	}
	if (object == restart) {
		stopTimer(timer);
		setTimer(timer, 600.0f);
		enterScene(scene1);
	}

	if (object == next) {
		enterScene(scene3);
		stopTimer(timer);
		setTimer(timer, 600.0f);
	}

	if (object == start1) {
		enterScene(scene4);
		startTimer(timer);
	}
	if (object == restart1) {
		stopTimer(timer);
		setTimer(timer, 600.0f);
		enterScene(scene3);
	}

	for (int i = 0; i < 3; i++) {
		if (flag1 == 1) {
			break;
		}
		for (int j = 0; j < 3; j++) {
			if (object == board1[i][j]) {
				if (a00 == board1[0][0] && a01 == board1[0][1] && a02 == board1[0][2] && a10 == board1[1][0] && a11 == board1[1][1] && a12 == board1[1][2] && a20 == board1[2][0] && a21 == board1[2][1] && blank == board1[2][2]) {
					showMessage("click the next button");
				}
				if (i == 0 && j == 0) {
					if (board1[i][j + 1] == blank) {
						locateObject(object, scene2, boardX1[j] + move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j + 1];
						board1[i][j + 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i + 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] - move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i + 1][j];
						board1[i + 1][j] = t1;
						flag1 = 1;
						break;
					}
				}
				else if (i == 0 && j == 1) {
					if (board1[i][j - 1] == blank) {
						locateObject(object, scene2, boardX1[j] - move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j - 1];
						board1[i][j - 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j + 1] == blank) {
						locateObject(object, scene2, boardX1[j] + move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j + 1];
						board1[i][j + 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i + 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] - move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i + 1][j];
						board1[i + 1][j] = t1;
						flag1 = 1;
						break;
					}
				}
				else if (i == 0 && j == 2) {
					if (board1[i][j - 1] == blank) {
						locateObject(object, scene2, boardX1[j] - move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j - 1];
						board1[i][j - 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i + 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] - move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i + 1][j];
						board1[i + 1][j] = t1;
						flag1 = 1;
						break;
					}
				}

				else if (i == 1 && j == 0) {
					if (board1[i - 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] + move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i - 1][j];
						board1[i - 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j + 1] == blank) {
						locateObject(object, scene2, boardX1[j] + move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j + 1];
						board1[i][j + 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i + 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] - move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i + 1][j];
						board1[i + 1][j] = t1;
						flag1 = 1;
						break;
					}
				}
				else if (i == 1 && j == 1) {
					if (board1[i - 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] + move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i - 1][j];
						board1[i - 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j + 1] == blank) {
						locateObject(object, scene2, boardX1[j] + move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j + 1];
						board1[i][j + 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i + 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] - move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i + 1][j];
						board1[i + 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j - 1] == blank) {
						locateObject(object, scene2, boardX1[j] - move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j - 1];
						board1[i][j - 1] = t1;
						flag1 = 1;
						break;
					}
				}
				else if (i == 1 && j == 2) {
					if (board1[i - 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] + move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i - 1][j];
						board1[i - 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i + 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] - move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i + 1][j];
						board1[i + 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j - 1] == blank) {
						locateObject(object, scene2, boardX1[j] - move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j - 1];
						board1[i][j - 1] = t1;
						flag1 = 1;
						break;
					}
				}

				else if (i == 2 && j == 0) {
					if (board1[i - 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] + move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i - 1][j];
						board1[i - 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j + 1] == blank) {
						locateObject(object, scene2, boardX1[j] + move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j + 1];
						board1[i][j + 1] = t1;
						flag1 = 1;
						break;
					}
				}
				else if (i == 2 && j == 1) {
					if (board1[i - 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] + move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i - 1][j];
						board1[i - 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j + 1] == blank) {
						locateObject(object, scene2, boardX1[j] + move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j + 1];
						board1[i][j + 1] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j - 1] == blank) {
						locateObject(object, scene2, boardX1[j] - move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j - 1];
						board1[i][j - 1] = t1;
						flag1 = 1;
						break;
					}
				}
				else if (i == 2 && j == 2) {
					if (board1[i - 1][j] == blank) {
						locateObject(object, scene2, boardX1[j], boardY1[i] + move);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i - 1][j];
						board1[i - 1][j] = t1;
						flag1 = 1;
						break;
					}
					else if (board1[i][j - 1] == blank) {
						locateObject(object, scene2, boardX1[j] - move, boardY1[i]);
						locateObject(blank, scene2, boardX1[j], boardY1[i]);
						t1 = board1[i][j];
						board1[i][j] = board1[i][j - 1];
						board1[i][j - 1] = t1;
						flag1 = 1;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (flag2 == 1) {
			break;
		}
		for (int j = 0; j < 3; j++) {
			if (object == board2[i][j]) {
				if (b00 == board2[0][0] && b01 == board2[0][1] && b02 == board2[0][2] && b10 == board2[1][0] && b11 == board2[1][1] && b12 == board2[1][2] && b20 == board2[2][0] && b21 == board2[2][1] && blank2 == board2[2][2]) {
					endGame();
				}
				if (i == 0 && j == 0) {
					if (board2[i][j + 1] == blank2) {
						locateObject(object, scene4, board2X[j] + move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j + 1];
						board2[i][j + 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i + 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] - move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i + 1][j];
						board2[i + 1][j] = t2;
						flag2 = 1;
						break;
					}
				}
				else if (i == 0 && j == 1) {
					if (board2[i][j - 1] == blank2) {
						locateObject(object, scene4, board2X[j] - move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j - 1];
						board2[i][j - 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j + 1] == blank2) {
						locateObject(object, scene4, board2X[j] + move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j + 1];
						board2[i][j + 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i + 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] - move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i + 1][j];
						board2[i + 1][j] = t2;
						flag2 = 1;
						break;
					}
				}
				else if (i == 0 && j == 2) {
					if (board2[i][j - 1] == blank2) {
						locateObject(object, scene4, board2X[j] - move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j - 1];
						board2[i][j - 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i + 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] - move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i + 1][j];
						board2[i + 1][j] = t2;
						flag2 = 1;
						break;
					}
				}

				else if (i == 1 && j == 0) {
					if (board2[i - 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] + move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i - 1][j];
						board2[i - 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j + 1] == blank2) {
						locateObject(object, scene4, board2X[j] + move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j + 1];
						board2[i][j + 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i + 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] - move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i + 1][j];
						board2[i + 1][j] = t2;
						flag2 = 1;
						break;
					}
				}
				else if (i == 1 && j == 1) {
					if (board2[i - 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] + move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i - 1][j];
						board2[i - 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j + 1] == blank2) {
						locateObject(object, scene4, board2X[j] + move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j + 1];
						board2[i][j + 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i + 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] - move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i + 1][j];
						board2[i + 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j - 1] == blank2) {
						locateObject(object, scene4, board2X[j] - move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j - 1];
						board2[i][j - 1] = t2;
						flag2 = 1;
						break;
					}
				}
				else if (i == 1 && j == 2) {
					if (board2[i - 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] + move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i - 1][j];
						board2[i - 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i + 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] - move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i + 1][j];
						board2[i + 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j - 1] == blank2) {
						locateObject(object, scene4, board2X[j] - move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j - 1];
						board2[i][j - 1] = t2;
						flag2 = 1;
						break;
					}
				}

				else if (i == 2 && j == 0) {
					if (board2[i - 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] + move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i - 1][j];
						board2[i - 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j + 1] == blank2) {
						locateObject(object, scene4, board2X[j] + move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j + 1];
						board2[i][j + 1] = t2;
						flag2 = 1;
						break;
					}
				}
				else if (i == 2 && j == 1) {
					if (board2[i - 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] + move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i - 1][j];
						board2[i - 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j + 1] == blank2) {
						locateObject(object, scene4, board2X[j] + move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j + 1];
						board2[i][j + 1] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j - 1] == blank2) {
						locateObject(object, scene4, board2X[j] - move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j - 1];
						board2[i][j - 1] = t2;
						flag2 = 1;
						break;
					}
				}
				else if (i == 2 && j == 2) {
					if (board2[i - 1][j] == blank2) {
						locateObject(object, scene4, board2X[j], board2Y[i] + move);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i - 1][j];
						board2[i - 1][j] = t2;
						flag2 = 1;
						break;
					}
					else if (board2[i][j - 1] == blank2) {
						locateObject(object, scene4, board2X[j] - move, board2Y[i]);
						locateObject(blank2, scene4, board2X[j], board2Y[i]);
						t2 = board2[i][j];
						board2[i][j] = board2[i][j - 1];
						board2[i][j - 1] = t2;
						flag2 = 1;
						break;
					}
				}
			}
		}
	}
}

int main() {

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	std::vector<int> v1 = { 365, 545, 725 };
	std::vector<int> k1 = { 440, 260, 80 };
	std::random_device rd1;
	std::mt19937 g1(rd1());
	std::shuffle(v1.begin(), v1.end(), g1);
	std::shuffle(k1.begin(), k1.end(), g1);

	scene1 = createScene("SlidePuzzle", "Images/루피.png");
	scene2 = createScene("Level-1", "Images/루피배경.png");
	scene3 = createScene("Level-2", "Images/조로.png");
	scene4 = createScene("Level-2", "Images/조로배경.png");

	start = createObject("start", "Images/start.png", scene1, 590, 70, true);
	a00 = createObject("a00", "Images/00.png", scene2, v1[0], k1[0], true);
	a01 = createObject("a01", "Images/01.png", scene2, v1[1], k1[0], true);
	a02 = createObject("a02", "Images/02.png", scene2, v1[2], k1[0], true);
	a10 = createObject("a10", "Images/10.png", scene2, v1[0], k1[1], true);
	a11 = createObject("a11", "Images/11.png", scene2, v1[1], k1[1], true);
	a12 = createObject("a12", "Images/12.png", scene2, v1[2], k1[1], true);
	a20 = createObject("a20", "Images/20.png", scene2, v1[0], k1[2], true);
	a21 = createObject("a21", "Images/21.png", scene2, v1[1], k1[2], true);
	blank = createObject("blank", "Images/blank.png", scene2, v1[2], k1[2], true);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v1[0] == boardX1[i] && k1[0] == boardY1[j]) {
				board1[j][i] = a00;
			}
			else if (v1[1] == boardX1[i] && k1[0] == boardY1[j]) {
				board1[j][i] = a01;
			}
			else if (v1[2] == boardX1[i] && k1[0] == boardY1[j]) {
				board1[j][i] = a02;
			}
			else if (v1[0] == boardX1[i] && k1[1] == boardY1[j]) {
				board1[j][i] = a10;
			}
			else if (v1[1] == boardX1[i] && k1[1] == boardY1[j]) {
				board1[j][i] = a11;
			}
			else if (v1[2] == boardX1[i] && k1[1] == boardY1[j]) {
				board1[j][i] = a12;
			}
			else if (v1[0] == boardX1[i] && k1[2] == boardY1[j]) {
				board1[j][i] = a20;
			}
			else if (v1[1] == boardX1[i] && k1[2] == boardY1[j]) {
				board1[j][i] = a21;
			}
			else if (v1[2] == boardX1[i] && k1[2] == boardY1[j]) {
				board1[j][i] = blank;
			}

		}
	}

	std::vector<int> v2 = { 372, 552, 732 };
	std::vector<int> k2 = { 445, 265, 85 };
	std::random_device rd2;
	std::mt19937 g2(rd2());
	std::shuffle(v2.begin(), v2.end(), g2);
	std::shuffle(k2.begin(), k2.end(), g2);

	start1 = createObject("start1", "Images/start.png", scene3, 590, 70, true);
	b00 = createObject("b00", "Images/b00.png", scene4, v2[0], k2[0], true);
	b01 = createObject("b01", "Images/b01.png", scene4, v2[1], k2[0], true);
	b02 = createObject("b02", "Images/b02.png", scene4, v2[2], k2[0], true);
	b10 = createObject("b10", "Images/b10.png", scene4, v2[0], k2[1], true);
	b11 = createObject("b11", "Images/b11.png", scene4, v2[1], k2[1], true);
	b12 = createObject("b12", "Images/b12.png", scene4, v2[2], k2[1], true);
	b20 = createObject("b20", "Images/b20.png", scene4, v2[0], k2[2], true);
	b21 = createObject("b21", "Images/b21.png", scene4, v2[1], k2[2], true);
	blank2 = createObject("blank2", "Images/blank.png", scene4, v2[2], k2[2], true);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v2[0] == board2X[i] && k2[0] == board2Y[j]) {
				board2[j][i] = b00;
			}
			else if (v2[1] == board2X[i] && k2[0] == board2Y[j]) {
				board2[j][i] = b01;
			}
			else if (v2[2] == board2X[i] && k2[0] == board2Y[j]) {
				board2[j][i] = b02;
			}
			else if (v2[0] == board2X[i] && k2[1] == board2Y[j]) {
				board2[j][i] = b10;
			}
			else if (v2[1] == board2X[i] && k2[1] == board2Y[j]) {
				board2[j][i] = b11;
			}
			else if (v2[2] == board2X[i] && k2[1] == board2Y[j]) {
				board2[j][i] = b12;
			}
			else if (v2[0] == board2X[i] && k2[2] == board2Y[j]) {
				board2[j][i] = b20;
			}
			else if (v2[1] == board2X[i] && k2[2] == board2Y[j]) {
				board2[j][i] = b21;
			}
			else if (v2[2] == board2X[i] && k2[2] == board2Y[j]) {
				board2[j][i] = blank2;
			}

		}
	}

	restart = createObject("restart", "Images/restart.png", scene2, 100, 40, true);
	restart1 = createObject("restart", "Images/restart.png", scene4, 100, 40, true);
	next = createObject("next", "images/next.png", scene2, 1100, 40, true);

	setMouseCallback(mouseCallback);
	timer = createTimer(600.0f);
	showTimer(timer);


	startGame(scene1);
}