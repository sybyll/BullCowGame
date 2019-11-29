#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuessAndPrintBack();
// the entry point for our application
int main()
{	
	PrintIntro();

	PlayGame();

	return 0; // exit the application
}
void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}
}
	// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

string GetGuessAndPrintBack() 
{
	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	// print the guess back
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}