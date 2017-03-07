#ifndef MATHGAME_H
#define MATHGAME_H
#include <string>
using namespace std;

const double PRIZE = .05, LOSE = .03;
const int	MAX = 100, MIN = 0;
const string ADD = "1", SUBTRACT = "2",
MULTIPLY = "3", DIVIDE = "4", STATS = "5";

struct Player;

class MathGame {
private:
	Player* user;
	bool isCorrect;
	int answer, num1, num2;
	string userInput;
	void validateUserResponse();								//validate user input
	void updateStats();											//updates number of correct and wrong answers, updates winnings
public:
	MathGame();
	~MathGame();
	void retrieveStats();										//import stats from txt file
	void displayStats();										//display users stats (total correct & wrong answers, name, and earnings)
	void saveStats();											//saves player stats after end of program
	void generateAdd();											//generate addition problem
	void generateSub();											//generate subtraction problem
	void generateMul();											//generate multiplication problem
	void generateDiv();											//generate division problem		
	void checkUserAnswer(string);								//given math problem, check if answer entered correct/incorrect
};
#endif