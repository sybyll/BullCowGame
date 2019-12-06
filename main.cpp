/* This is the console execution, that makes the BullCow class
This acts as the view in a MVC pattern, and is reponsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game
// the entry point for our application
int main()
{	
	std::cout << BCGame.GetCurrentTry();
	bool PlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} while (PlayAgain);
	return 0; // exit the application
}
	// introduce the game
void PrintIntro() 
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows 
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}
	// TODO summarise game
}
FText GetGuess() // TODO change to GetValidGuess
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	FBullCowGame BCGame;
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;
	return false;
}
