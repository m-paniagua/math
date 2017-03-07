#include "mathgame.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct Player {
	double cash;
	int correct, wrong;
	string userName;
};

MathGame::MathGame() {
	user = nullptr;
	isCorrect = false;
	answer = 0; 
	num1 = 0;  
	num2 = 0;
	userInput = "";
}

MathGame::~MathGame() {
	delete user;
}

void MathGame::retrieveStats() {
	ifstream inFile;
	ofstream outFile;

	user = new Player;

	int stringLength, counter = 0;

	cout << "Enter your name and pres <ENTER>" << endl;
	getline(cin, user->userName);

	stringLength = user->userName.length();

	while (counter < stringLength || stringLength == 0)							//validates user's name is composed of only letters
	{
		if (!isalpha(user->userName[counter]))
		{
			cout << "This is not a name." << endl;
			cout << "Enter your name and pres <ENTER>" << endl;
			getline(cin, user->userName);
			stringLength = user->userName.length();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}

	inFile.open(user->userName + ".txt");												//opens text file

	if (!inFile)																//if text file does not exist, creates one
	{
		outFile.open(user->userName + ".txt");
		user->cash = 0.00, user->correct = 0, user->wrong = 0;													//initializes number correct, wrong and earnings to 0
		outFile << user->userName << endl << user->correct << endl << user->wrong << endl;					//populates text file
		outFile << fixed << showpoint << setprecision(2);
		outFile << user->cash;

	}

	inFile >> user->userName >> user->correct >> user->wrong >> user->cash;											//imports data from text file
	outFile.close();
	inFile.close();
}
void MathGame::generateAdd() {
	unsigned seed = time(0);

	srand(seed);

	num1 = MIN + rand() % MAX;													//generates two random numbers
	num2 = MIN + rand() % MAX;

	system("cls");

	cout << setfill(' ') << right << setw(5) << num1 << endl					//displays addition problem
		<< "+" << setw(4) << num2 << endl
		<< "-----\n";
	getline(cin, userInput);
	validateUserResponse();
}
void MathGame::generateSub() {
	unsigned seed = time(0);

	srand(seed);

	num1 = MIN + rand() % MAX;													//generates two random numbers
	num2 = MIN + rand() % MAX;

	while (num2 > num1)															//while num2 is less than num1, num2 will continue to be randomized
	{
		num2 = MIN + rand() % MAX;
	}

	system("cls");

	cout << setfill(' ') << right << setw(5) << num1 << endl
		<< "-" << setw(4) << num2 << endl
		<< "-----\n";
	getline(cin, userInput);
	validateUserResponse();
}
void MathGame::generateMul() {
	unsigned seed = time(0);

	srand(seed);

	num1 = MIN + rand() % MAX;													//generates two random numbers
	num2 = MIN + rand() % MAX;

	system("cls");

	if (num2 > num1)															//formats multiplication problem to display number with least digits on bottom
	{
		cout << setfill(' ') << right << setw(5) << num2 << endl
			<< "x" << setw(4) << num1 << endl
			<< "-----\n";
		getline(cin, userInput);
	}
	else
	{
		cout << setfill(' ') << right << setw(5) << num1 << endl
			<< "x" << setw(4) << num2 << endl
			<< "-----\n";
		getline(cin, userInput);
	}
	validateUserResponse();
}
void MathGame::generateDiv() {
	unsigned seed = time(0);

	srand(seed);

	num1 = MIN + rand() % MAX;													//generates two random numbers
	num2 = 1 + rand() % MAX;													//minimum number set to 1, avoid division by 0

	while ((num1 % num2) != 0)													//while num1 is not divisble by num2, continues to randomize num2 
	{
		num2 = 1 + rand() % MAX;
	}

	system("cls");

	cout << setfill(' ') << right << setw(5) << num1 << endl
		<< "/" << setw(4) << num2 << endl
		<< "-----\n";
	getline(cin, userInput);
	validateUserResponse();
}
void MathGame::validateUserResponse() {
	int integer = 0;
	char nextChar;
	int strLength = userInput.length();
	int counter = 0;

	while (counter < strLength || strLength == 0)								//validates user input is a number greater than 0, prompts user when any character other than a number detected
	{
		if (!isdigit(userInput[counter]))
		{
			cout << "that is not a number >= 0, try again\n";
			getline(cin, userInput);
			strLength = userInput.length();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
	counter = 0;
	while (counter < strLength)													//converts string to integer
	{
		nextChar = userInput[counter];

		if (isdigit(nextChar))
		{
			integer = integer * 10 + (nextChar - '0');
		}
		counter++;
	}
	system("cls");
	answer = integer;
}
void MathGame::checkUserAnswer(string math) {
	int check;

	if (math == ADD)
	{
		check = num1 + num2;
	}
	else if (math == SUBTRACT)
	{
		check = num1 - num2;
	}
	else if (math == MULTIPLY)
	{
		check = num1 * num2;
	}
	else if (math == DIVIDE)
	{
		check = num1 / num2;
	}

	if (check == answer)
	{
		cout << "       ____ " << endl												//splashscreen for correct answer, displays ascii art
			<< "     (|    |)" << endl
			<< "       \\  /" << endl
			<< "        )(" << endl
			<< "      _|~~|_" << endl
			<< "     |______|" << endl;

		cout << "\nThat is correct!" << endl;
		cout << "Good job!" << endl;
		system("pause");
		isCorrect = true;
	}
	else
	{
		system("cls");
		cout << "\n     _____" << endl												//splashscreen for correct answer, displays ascii art
			<< " |--'  ()_)" << endl
			<< " |    ()__)" << endl
			<< " |   ()___)" << endl
			<< " |-.  ()__)" << endl
			<< "    \\ \\" << endl
			<< "     |_)" << endl;

		cout << "\nThat is wrong!" << endl;
		cout << "Better luck next time!" << endl;
		system("pause");
		isCorrect = false;
	}
	updateStats();
}
void MathGame::updateStats() {
	if (isCorrect)
	{
		user->correct++;
		user->cash += .05;
	}
	else if (!isCorrect)
	{
		user->wrong++;
		user->cash -= .03;
	}
}
void MathGame::displayStats() {
	system("cls");

	cout << setfill('=') << setw(1) << "+" << setw(34) << "=" << setw(1) << "+" << endl;
	cout << setfill(' ') << setw(1) << "|" << setw(13) << " " << left << "Game Stats" << setw(11) << " " << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(18) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	cout << setfill(' ') << setw(1) << "|" << setw(18) << left << "User" << setw(1) << "|" << setw(15) << left << user->userName << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(18) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	cout << fixed << showpoint << setprecision(2);
	cout << setfill(' ') << setw(1) << "|" << setw(18) << left << "Total Earnings" << setw(1) << "|" << left << "$" << setw(14) << left << user->cash << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(18) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;


	cout << setfill(' ') << setw(1) << "|" << setw(18) << left << "Total Correct" << setw(1) << "|" << setw(15) << left << user->correct << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(18) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;


	cout << setfill(' ') << setw(1) << "|" << setw(18) << left << "Total Wrong" << setw(1) << "|" << setw(15) << left << user->wrong << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(18) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;
	system("pause");
}
void MathGame::saveStats() {
	ofstream outFile;

	outFile.open(user->userName + ".txt");
	outFile << user->userName << endl << user->correct << endl << user->wrong << endl;
	outFile << fixed << showpoint << setprecision(2);
	outFile << user->cash;

	outFile.close();
}