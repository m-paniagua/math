#include <iostream>
#include <iomanip>
#include "mathgame.h"
using namespace std;

void menu();
void processChoice(string, MathGame&);
string credits();

int main() {
	string choice;
	MathGame player1;

	choice = credits();
	if (choice == "y" || choice == "Y")
	{
		system("cls");
		player1.retrieveStats();	

		do
		{
			menu();
			getline(cin, choice);

			if (choice != "n" || choice != "N")
			{
				processChoice(choice, player1);
			}
		} while (choice != "n" && choice != "N");

		return 0;
	}
	else
	{
		cout << "End of program" << endl;
		system("pause");
		return 0;
	}
	
	
}
string credits()
{
	string continu;

	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;
	cout << setfill(' ') << setw(1) << "|" << setw(6) << " " << left << "The Math Game" << setw(6) << " " << "|" << endl;
	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;

	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;
	cout << setfill(' ') << setw(1) << "|" << setw(11) << " " << left << "by:" << setw(11) << " " << "|" << endl;
	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;

	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;
	cout << setfill(' ') << setw(1) << "|" << setw(5) << " " << left << "Manuel Paniagua" << setw(5) << " " << "|" << endl;
	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;

	cout << "\ny/Y to continue, any other char to exit: ";

	getline(cin, continu);
	return continu;
}
void menu()
{
	system("cls");

	//borders
	cout << setfill('=') << setw(1) << "+" << setw(25) << "=" << setw(1) << "+" << endl;
	//choose a problem
	cout << setfill(' ') << setw(1) << "|" << setw(4) << " " << left << "Choose a problem:" << setw(4) << " " << "|" << endl;
	cout << setfill('=') << setw(1) << "+" << setw(9) << "=" << setw(1) << "+" << setw(15) << "=" << setw(1) << "+" << endl;

	//add
	cout << setfill(' ') << setw(1) << "|" << setw(9) << left << "1." << setw(1) << "|" << setw(15) << left << "Add" << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(9) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	//subtract
	cout << setfill(' ') << setw(1) << "|" << setw(9) << left << "2." << setw(1) << "|" << setw(15) << left << "Subtract" << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(9) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	//multiply
	cout << setfill(' ') << setw(1) << "|" << setw(9) << left << "3." << setw(1) << "|" << setw(15) << left << "Multiply" << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(9) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	//divide
	cout << setfill(' ') << setw(1) << "|" << setw(9) << left << "4." << setw(1) << "|" << setw(15) << left << "Divide" << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(9) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	//stats
	cout << setfill(' ') << setw(1) << "|" << setw(9) << left << "5." << setw(1) << "|" << setw(15) << left << "Stats" << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(9) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

	//quit
	cout << setfill(' ') << setw(1) << "|" << setw(9) << left << "n/N" << setw(1) << "|" << setw(15) << left << "To Quit" << setw(1) << "|" << endl;
	cout << setfill('-') << setw(1) << "+" << setw(9) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;
}
void processChoice(string choice, MathGame& usr) {
	if (choice == ADD)
	{
		usr.generateAdd();
		usr.checkUserAnswer(choice);
		//usr.updateStats();
	}
	else if (choice == SUBTRACT)
	{
		usr.generateSub();
		usr.checkUserAnswer(choice);
		//usr.updateStats();
	}
	else if (choice == MULTIPLY)
	{
		usr.generateMul();
		usr.checkUserAnswer(choice);
		//usr.updateStats();
	}
	else if (choice == DIVIDE)
	{
		usr.generateDiv();
		usr.checkUserAnswer(choice);
		//usr.updateStats();
	}
	else if (choice == STATS)
	{
		usr.displayStats();
	}
	else if (choice == "n" || choice == "N")
	{
		cout << "End of program" << endl;
		system("pause");
		usr.saveStats();
	}
	else
	{
		cout << "Please enter a valid menu option" << endl;
		system("pause");
	}
}