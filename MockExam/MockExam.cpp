#include <iostream>
#include <conio.h>
#include "MockExam.h"
#include <vector>
#include <time.h>
void MainMenu();
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
int main()
{
	srand(time(0));
    if (Unlocked(3)) {
		MainMenu();
    }
    else {
        return 0;
    }
}

void MainMenu() {
	system("cls");
	std::vector <std::string > tasks{ "Task 1", "Task 2", "Task 3", "Task 4", "Quit" };
	for (int i = 0; i < tasks.size(); i++) {
		std::cout << i + 1 << ". " << tasks[i] << std::endl;
	}
	//Ask what task to do
	std::cout << "What would you like to do?\n";
	char input = _getch();
	switch (input) {
	case '1':
		Task1();
		break;
	case '2':
		Task2();
		break;
	case '3':
		Task3();
		break;
	case '4':
		Task4();
		break;
	case '5':
		Task5();
		break;
	default:
		std::cout << "\nWrong input, do you want to try again?\n[Y] to redo, [N] to quit";
		char j = _getch();
		if (j == 'y') {
			MainMenu();
		}
		else if (j == 'n') {
			Task5();
		}
		else {
			MainMenu();
		}
		break;
	}
}

bool Unlocked(int attempts)
{
	int width = 3;
	int heigth = 3;

	int heightPos = 0;
	int widthPos = 0;

	int moves = 4;
	//Declareing a vector of correct moves to compare them later
	std::vector<char> correctPlaces{ 's','d','w','d'};
	std::vector<char> myMoves{};
	for (int i = 0; i < attempts; i++)
	{
		//Reset for each attempt
		myMoves = {};
		heightPos = 0;
		widthPos = 0;
		for (int p = 0; p < moves; p++) {

			system("cls");
			std::cout << "Controls: W-up, S-down, A-left, D-left\n";

			//Draw attempts left
			std::cout << "Attempts left: " << attempts - i << std::endl;
			
			for (int k = 0; k < heigth; k++) {
				std::cout << "|";
				for (int j = 0; j < width; j++)
				{
					if (heightPos == k && j == widthPos) {
						std::cout << "*" << " | ";
					}
					else {
						std::cout << k + j + 1 << " | ";
					}
				}
				std::cout << "\n";
			}

			//Ask for input
			char input = _getch();
			switch (input)
			{
			case 'w':
				heightPos -= 1;
				break;
			case 's':
				heightPos += 1;
				break;
			case 'a':
				widthPos -= 1;
				break;
			case 'd':
				widthPos += 1;
				break;

			default:
				break;
			}
			//Reset it if you go "outside"
			if (heightPos < 0) {
				heightPos = 0;
			}
			if (widthPos < 0) {
				widthPos = 0;
			}
			if (widthPos >= width) {
				widthPos = width - 1;
			}
			if (heightPos >= heigth) {
				heightPos = heigth - 1;
			}
			myMoves.push_back(input);
		}
		//Check at end of 4 moves, if my moves is equal to correct, then return unlocked true
		if (myMoves == correctPlaces) {
			return true;
		}
	}
	//If all attempst used without return true, return false
	return false;
}

void Task1() {
	system("cls");
	long count = 0;
	std::cout << "After 6 rounds of 2000 rolls of a dice the dice rolls 1 or 6: \n";
	for (int k = 0; k < 6; k++) {
		count = 0;
		for (int i = 0; i < 2000; i++)
		{
			int roll = rand() % 7;
			if (roll == 6 || roll == 1) {
				count += 1;
			}
		}
		std::cout << k << ". " << count << " times!\n";
	}
	
	std::cout << "Roll again?\n";
	std::cout << "[Y] to roll again, [N] to return to main menu\n";
	char input = 'a';
	while (input != 'y' && input != 'n') {
		input = _getch();
		if (input == 'y') {
			Task1();
		}
		else if (input == 'n') {
			MainMenu();
		}
		else {
			std::cout << "Not valid input!\n";
		}
	}

}

struct ValueStruct
{
	char name;
	int value;
	int place;
};
void Task2() {
	system("cls");
	std::vector<ValueStruct> myStructs;
	for (int i = 0; i < 20; i++) {
		//declare an VlaueStruct
		ValueStruct v;
		v.value = rand() % 21;
		v.name = static_cast<char>('A'+ i);
		v.place = i;
		myStructs.push_back(v);
	}
	std::cout << "Place\t" << "Name\t" << "Value\t" << "HealthBar\t" << "\n";
	for (int i = 0; i < myStructs.size(); i++) {
		std::cout << myStructs[i].place << "\t" << myStructs[i].name << "\t" << myStructs[i].value << "\t";
		for (int k = 0; k < myStructs[i].value; k++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << "Redo?\n [Y]-redo, [N]-exit to main menu\n";
	char input = _getch();
	if (input == 'y') {
		Task2();
	}
	else {
		MainMenu();
	}
}
void Task3() {
	//Declare grid
	const int width = 25;
	const int height = 15;
	int heightPos = 1;
	int widthPos = 1;

	char grid[height][width];

	bool moving = true;
	//fill grid with random # n stuff
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++) {
			if (i == 0 || i == height - 1) {
				grid[i][k] = '#';
			}
			else if (k == 0 || k == width - 1) {
				grid[i][k] = '#';
			}
			else if ((rand() % 20) < 2) {
				//Random chance to be a #
				grid[i][k] = '#';
			}
			else {
				grid[i][k] = ' ';
			}
		}
	}
	while (moving) {
		system("cls");
		std::cout << "Controls: W-up, S-down, A-left, D-left\n";
		for (int i = 0; i < height; i++) {
			for (int k = 0; k < width; k++) {

				if (i == heightPos && k == widthPos) {
					std::cout << 'E';
				}
				else {
					std::cout << grid[i][k];
				}
			}
			std::cout << "\n";
		}
		//Ask for input, check if it is valid, if so, change to pos of the player
		char input = _getch();
		switch (input) {
		case 'w':
			if (grid[heightPos - 1][widthPos] == ' ') {
				heightPos -= 1;
			}
			
			break;
		case 's':
			if (grid[heightPos + 1][widthPos] == ' ') {
				heightPos += 1;
			}
			break;
		case 'a':
			if (grid[heightPos][widthPos-1] == ' ') {
				widthPos -= 1;
			}
			break;
		case 'd':
			if (grid[heightPos][widthPos+1] == ' ') {
				widthPos += 1;
			}
			break;

		default:
			MainMenu();
			break;
		}
	}
}

void Task4() 
{
	int points = 0;
	//Declare grid
	const int width = 25;
	const int height = 15;
	int heightPos = 1;
	int widthPos = 1;

	char grid[height][width];

	bool moving = true;

	
	//fill with random # n stuff
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++) {
			if (i == 0 || i == height - 1) {
				grid[i][k] = '#';
			}
			else if (k == 0 || k == width - 1) {
				grid[i][k] = '#';
			}
			else if ((rand() % 20) < 2) {
				//Random chance to be a #
				grid[i][k] = '#';
			}
			else if((rand() % 20) < 5){
				//random chance to get a reward on this spot
				grid[i][k] = '-';
			}
			else {
				grid[i][k] = ' ';
			}
		}
	}
	
	while (moving) {
		system("cls");
		std::cout << "Controls: W-up, S-down, A-left, D-left\n";
		for (int i = 0; i < height; i++) {
			for (int k = 0; k < width; k++) {
				if (i == heightPos && k == widthPos) {
					std::cout << 'E';
				}
				else {
					std::cout << grid[i][k];
				}
			}
			std::cout << "\n";
		}
		std::cout << "Points: " << points;
		//Ask for input
		char input = _getch();
		switch (input) {
		case 'w':
			if (grid[heightPos - 1][widthPos] != '#') {
				heightPos -= 1;
			}

			break;
		case 's':
			if (grid[heightPos + 1][widthPos] != '#') {
				heightPos += 1;
			}
			break;
		case 'a':
			if (grid[heightPos][widthPos - 1] != '#') {
				widthPos -= 1;
			}
			break;
		case 'd':
			if (grid[heightPos][widthPos + 1] != '#') {
				widthPos += 1;
			}
			break;

		default:
			MainMenu();
			break;
		}
		//Check if the E is on a plum
		if (grid[heightPos][widthPos] == '-') {
			points += 5;
			grid[heightPos][widthPos] = ' ';
		}
	}
}
void Task5() {
	exit(0);
}
        