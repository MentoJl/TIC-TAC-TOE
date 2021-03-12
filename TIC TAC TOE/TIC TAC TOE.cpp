#include <iostream>
#include <ctime>
#include <conio.h>
void fail() {
	std::cout << "\a\n+----------+\n"
		<< "|Try again!|\n"
		<< "+----------+\n\n";
}
void battle(char c[3][3]) {
	std::cout << "\n+---+---+---+\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			std::cout << "| " << c[i][j] << " ";
		std::cout << "|\n+---+---+---+\n";
	}
}
int genocide() {
	system("cls");
	system("color 40");
	std::system("mode con cols=300 lines=100");
	for (; ;)
		std::cout << "666 ";
}
char rate(char c[3][3], char symbol, char enemy, int result = 0) {
	if ((c[0][0] == symbol && c[0][1] == symbol && c[0][2] == symbol) || (c[1][0] == symbol && c[1][1] == symbol && c[1][2] == symbol) || (c[2][0] == symbol && c[2][1] == symbol && c[2][2] == symbol) ||
		(c[0][0] == symbol && c[1][0] == symbol && c[2][0] == symbol) || (c[0][1] == symbol && c[1][1] == symbol && c[2][1] == symbol) || (c[0][2] == symbol && c[1][2] == symbol && c[2][2] == symbol) ||
		(c[0][0] == symbol && c[1][1] == symbol && c[2][2] == symbol) || (c[2][0] == symbol && c[1][1] == symbol && c[0][2] == symbol))
		result = 1;
	if ((c[0][0] == enemy && c[0][1] == enemy && c[0][2] == enemy) || (c[1][0] == enemy && c[1][1] == enemy && c[1][2] == enemy) || (c[2][0] == enemy && c[2][1] == enemy && c[2][2] == enemy) ||
		(c[0][0] == enemy && c[1][0] == enemy && c[2][0] == enemy) || (c[0][1] == enemy && c[1][1] == enemy && c[2][1] == enemy) || (c[0][2] == enemy && c[1][2] == enemy && c[2][2] == enemy) ||
		(c[0][0] == enemy && c[1][1] == enemy && c[2][2] == enemy) || (c[2][0] == enemy && c[1][1] == enemy && c[0][2] == enemy))
		result = 2;
	return result;
}
int main()
{
	srand(unsigned(time(NULL)));
	system("color F0");
	std::string mode = "Computer", difficulty;
	char symbol, enemy, c[3][3], empty = ' ', number;
	bool failcounters = false;
main:
	system("cls");
	int x, y, menu, step = 0, result = 0;
	std::cout << "\t\t\t\t\t\t +-----------+\n"
		<< "\t\t\t\t\t\t~|TIC TAC TOE|~\n"
		<< "\t\t\t\t\t\t +-----------+"
		<< "\nYour game mode: " << mode
		<< "\n1 - Start game.\n"
		<< "2 - Select other game mode.\n"
		<< ">";
	std::cin >> menu;
	switch (menu) {
	case 1: break;
	case 2:  failmode: std::cout << "Game mods:" << " 1VS1\n"
		<< "\t   Computer\n"
		<< "\nChoose game mode which you prefer: ";
		std::cin >> mode;
		if (mode == "Computer" || mode == "computer" || mode == "1vs1" || mode == "1VS1") {}
		else {
			fail();
			goto failmode;
		}
		goto main;
		break;
	default: fail(); goto main; break;

	}
	if (mode == "computer" || mode == "Computer") {
	faildifficulties: std::cout << "Difficulties:" << " Easy\n"
		<< "\t      Normal\n"
		<< "\t      Hard\n"
		<< "\t      Uber\n"
		<< "\nChoose difficulty which you prefer.\n"
		<< ">";
	std::cin >> difficulty;
	if (difficulty == "Easy" || difficulty == "easy" || difficulty == "Normal" || difficulty == "normal" || difficulty == "Hard" || difficulty == "hard" || difficulty == "Uber" || difficulty == "uber")
		std::cout << "\nYour difficulty: " << difficulty;
	else if (difficulty == "genocide")
		genocide();
	else {
		fail();
		goto faildifficulties;
	}
	}
failsymbol:
	std::cout << "\nChoose your symbol (X or O).\n"
		<< ">";
	std::cin >> symbol;
	switch (symbol) {
	case 'X': enemy = 'O'; break;
	case 'O': enemy = 'X'; break;
	default: fail(); goto failsymbol;
	} // Начало
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			c[i][j] = empty;
		}
	}
	do
	{
		bool extraExit = false;
		step++;
		battle(c); // Ход игрока
		if (mode == "computer" || mode == "Computer")
			std::cout << "\nYou are going.\n";
		else
			std::cout << "\nFirst player going.\n";
		do {
			failcounters = false;
			std::cout << "Input counter. [Numpad]";
			number = _getch();
			switch (number) {
			case '1': x = 2; y = 0; break;
			case '2': x = 2; y = 1; break;
			case '3': x = 2; y = 2; break;
			case '4': x = 1; y = 0; break;
			case '5': x = 1; y = 1; break;
			case '6': x = 1; y = 2; break;
			case '7': x = 0; y = 0; break;
			case '8': x = 0; y = 1; break;
			case '9': x = 0; y = 2; break;
			default: failcounters = true; fail(); break;
			}
			if (c[x][y] == symbol || c[x][y] == enemy) {
				if (failcounters == false)
					fail();
				failcounters = true;
			}
		} while (failcounters == true); // Конец хода игрока
		c[x][y] = symbol;
		result = rate(c, symbol, enemy, result);
		if (result == 1 || result == 2)
			break;
		if (mode == "computer" || mode == "Computer" && step < 5) { // Ход компьютера
			for (int z = 0; z < 3; z++) {
				if (c[1][1] == empty && (difficulty == "Hard" || difficulty == "hard" || difficulty == "Uber" || difficulty == "uber")) {
					c[1][1] = enemy;
					break;
				} // Победа компьютера
				if (difficulty != "Easy" && difficulty != "easy") {
					if ((c[0][0] == enemy && c[1][1] == enemy && c[2][2] == empty) || (c[0][0] == enemy && c[1][1] == empty && c[2][2] == enemy) || (c[0][0] == empty && c[1][1] == enemy && c[2][2] == enemy)) {
						for (int v = 0; v < 3; v++) {
							if (c[v][v] == empty)
								c[v][v] = enemy;
						}
						break;
					}
					if ((c[0][2] == enemy && c[1][1] == enemy && c[2][0] == empty) || (c[0][2] == enemy && c[1][1] == empty && c[2][0] == enemy) || (c[0][2] == empty && c[1][1] == enemy && c[2][0] == enemy)) {
						if (c[0][2] == enemy && c[1][1] == enemy && c[2][0] == empty)
							c[2][0] = enemy;
						if (c[0][2] == enemy && c[1][1] == empty && c[2][0] == enemy)
							c[1][1] = enemy;
						if (c[0][2] == empty && c[1][1] == enemy && c[2][0] == enemy)
							c[0][2] = enemy;
						break;
					}
					for (int o = 0; o < 3; o++) {
						if ((c[o][0] == empty && c[o][1] == enemy && c[o][2] == enemy) || (c[o][0] == enemy && c[o][1] == empty && c[o][2] == enemy) || (c[o][0] == enemy && c[o][1] == enemy && c[o][2] == empty)) {
							do {
								y = rand() % 3;
							} while (c[o][y] != empty);
							c[o][y] = enemy;
							extraExit = true;
							break;
						}
					}
					if (extraExit == true)
						break;
					for (int o = 0; o < 3; o++) {
						if ((c[0][o] == empty && c[1][o] == enemy && c[2][o] == enemy) || (c[0][o] == enemy && c[1][o] == empty && c[2][o] == enemy) || (c[0][o] == enemy && c[1][o] == enemy && c[2][o] == empty)) {
							do {
								x = rand() % 3;
							} while (c[x][o] != empty);
							c[x][o] = enemy;
							extraExit = true;
							break;
						}
					}
					if (extraExit == true)
						break; // Конец победы
					if ((c[0][0] == symbol && c[1][1] == symbol && c[2][2] == empty) || (c[0][0] == symbol && c[1][1] == empty && c[2][2] == symbol) || (c[0][0] == empty && c[1][1] == symbol && c[2][2] == symbol)) { // Блокиратор
						for (int v = 0; v < 3; v++) {
							if (c[v][v] == empty)
								c[v][v] = enemy;
						}
						break;
					}
					if ((c[0][2] == symbol && c[1][1] == symbol && c[2][0] == empty) || (c[0][2] == symbol && c[1][1] == empty && c[2][0] == symbol) || (c[0][2] == empty && c[1][1] == symbol && c[2][0] == symbol)) {
						if (c[0][2] == symbol && c[1][1] == symbol && c[2][0] == empty)
							c[2][0] = enemy;
						if (c[0][2] == symbol && c[1][1] == empty && c[2][0] == symbol)
							c[1][1] = enemy;
						if (c[0][2] == empty && c[1][1] == symbol && c[2][0] == symbol)
							c[0][2] = enemy;
						break;
					}
					if ((c[z][0] == empty && c[z][1] == symbol && c[z][2] == symbol) || (c[z][0] == symbol && c[z][1] == empty && c[z][2] == symbol) || (c[z][0] == symbol && c[z][1] == symbol && c[z][2] == empty)) {
						do {
							y = rand() % 3;
						} while (c[z][y] == symbol);
						c[z][y] = enemy;
						break;
					}
					if ((c[0][z] == empty && c[1][z] == symbol && c[2][z] == symbol) || (c[0][z] == symbol && c[1][z] == empty && c[2][z] == symbol) || (c[0][z] == symbol && c[1][z] == symbol && c[2][z] == empty)) {
						do {
							x = rand() % 3;
						} while (c[x][z] == symbol);
						c[x][z] = enemy;
						break;
					}
				} // Конец основного блокиратора победы
				if (difficulty != "Easy" && difficulty != "easy" && difficulty != "Normal" && difficulty != "normal") { // Победа по вертикали и горизонтали (О)
					if (c[1][1] == enemy && z == 2 && ((c[0][1] == empty && c[2][1] == empty) || (c[1][0] == empty && c[1][2] == empty))) {
						do {
							do {
								x = rand() % 3;
								y = rand() % 3;
							} while (((x != 0 && x != 2) && y != 1) && (x != 1 && (y != 0 && y != 2)));
						} while (c[x][y] != empty);
						std::cout << "\nWin vertical and gorisontal\n" << x << " " << y << std::endl;
						c[x][y] = enemy;
						break;
					}
					if (c[1][1] == symbol && z == 2 && ((c[0][0] == empty && c[2][2] == empty) || (c[2][0] == empty && c[0][2] == empty))) { // Победа по диагонали справо и слево (Х)
						do {
							do {
								x = rand() % 3;
								y = rand() % 3;
							} while (((x != 0 && y != 2) || (x != 2 && y != 0)) && ((x != 0 && y != 0) || (x != 2 && y != 2)));
						} while (c[x][y] != empty);
						std::cout << "\nWin diagonal\n" << x << " " << y << std::endl;
						c[x][y] = enemy;
						break;
					}
				}
				if (difficulty == "Uber" || difficulty == "uber") { //Блокиратор X
					if (c[1][0] == symbol && c[0][1] == symbol && c[0][0] == empty && z == 2) {
						c[0][0] = enemy;
						break;
					}
					if (c[0][1] == symbol && c[1][2] == symbol && c[0][2] == empty && z == 2) {
						c[0][2] = enemy;
						break;
					}
					if (c[2][0] == empty && c[1][0] == symbol && c[2][1] == symbol && z == 2) {
						c[2][0] = enemy;
						break;
					}
					if (c[2][2] == empty && c[1][2] == symbol && c[2][1] == symbol && z == 2) {
						c[2][2] = enemy;
						break;
					}
					if (c[2][0] == empty && c[0][2] == empty && c[1][1] == enemy && z == 2) { // Вероятность победы по диагонали (О)
						do {
							x = rand() % 3;
							y = rand() % 3;
						} while (x != 0 && y != 0 || x != 2 && y != 2);
						std::cout << "\nWin left(1)\n" << x << " " << y << std::endl;
						c[x][y] = enemy;
						break;
					}
					if (c[0][0] == empty && c[2][2] == empty && c[1][1] == enemy && z == 2) {
						do {
							x = rand() % 3;
							y = rand() % 3;
						} while (x != 2 && y != 0 || x != 0 && y != 2);
						std::cout << "\nWin left(2)\n" << x << " " << y << std::endl;
						c[x][y] = enemy;
						break;
					}
				} // Конец утилит
				if (z == 2) {
					do {
						x = rand() % 3;
						y = rand() % 3;
					} while (c[x][y] != empty);
					std::cout << "\n\nRandom\n\n";
					c[x][y] = enemy;
					break;
				}
			}
		} // Конец хода компьютера
		else if (step < 5) { //Ход 2-ого игрока
			battle(c);
			std::cout << "\nSecond player going.\n";
			do {
				failcounters = false;
				std::cout << "Input counter. [Numpad]";
				number = _getch();
				switch (number) {
				case '1': x = 2; y = 0; break;
				case '2': x = 2; y = 1; break;
				case '3': x = 2; y = 2; break;
				case '4': x = 1; y = 0; break;
				case '5': x = 1; y = 1; break;
				case '6': x = 1; y = 2; break;
				case '7': x = 0; y = 0; break;
				case '8': x = 0; y = 1; break;
				case '9': x = 0; y = 2; break;
				}
				if (c[x][y] != symbol && c[x][y] != enemy)
					c[x][y] = symbol;
				else {
					fail();
					failcounters = true;
				}
			} while (failcounters == true); // Конец хода игрока
		} //Конец хода 2-ого игрока
		result = rate(c, symbol, enemy, result);
		if (result == 1 || result == 2)
			break;
	} while (step != 5); // Конец
	battle(c);
	switch (result) {
	case 0: std::cout << "Draw...";
		break;
	case 1: if (mode == "computer" || mode == "Computer")
		std::cout << "Congrats, you are winner.";
		  else
		std::cout << "First player win.";
		break;
	case 2: if (mode == "computer" || mode == "Computer")
		std::cout << "Field...";
		  else
		std::cout << "Second player win.";
		break;
	}
	std::cout << "\n\nDo you want try?"
		<< "\nEnter:";
	std::cin >> difficulty;
	if (difficulty == "YES" || difficulty == "Yes" || difficulty == "yEs" || difficulty == "yeS" || difficulty == "yes")
		goto main;
	else
		std::cout << "\nHave a good day.\n";
	system("pause");
	return 0;
}
