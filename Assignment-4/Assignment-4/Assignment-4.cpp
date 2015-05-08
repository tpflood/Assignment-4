// Assignment-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void DisplayMenuHeader()
{
	cout << "---------------------------------------------------" << endl;
	cout << "1-D ARRAY PROCESSING MENU OPTIONS" << endl;
	cout << "---------------------------------------------------" << endl;
};

int GetUserMenuSelection(int Low, int High)
{
	int UserSelection;
	bool KeepAsking;

	do
	{
		KeepAsking = false;
		UserSelection = 10;
		cout << "Enter your choice: ";
		cin >> UserSelection;
		if ((UserSelection < Low) || (UserSelection > High))
		{
			cout << "Choice must be between " << Low << " and " << High << endl;
			KeepAsking = true;
		}		
	} while (KeepAsking);

	cout << endl;
	
	return(UserSelection);
};

void DisplayMenu()
{
	cout << "1. Read in 10 scores from user." << endl;
	cout << "2. Read in 10 scores from the file, scores.txt." << endl;
	cout << "3. Print all scores." << endl;
	cout << "4. Print the highest score." << endl;
	cout << "5. Print the lowest score." << endl;
	cout << "6. Print the average score." << endl;
	cout << "7. Print one score (give its entry number)" << endl;
	cout << "8. Quit program" << endl << endl;
};

void GetScoresFromUser(int Scores[], int NumberOfScores)
{
	int i;

	for (i = 0; i < NumberOfScores; i++)
	{
		cout << "Enter Score #:" << (i+1) << " ";
		cin >> Scores[i];
	};	
	cout << endl;
}

void DisplayAllScores(int Scores[], int NumberOfScores)
{
	int i;
		
	for (i = 0; i < NumberOfScores; i++)
	{
		cout << "score #:" << (i + 1) << "\t";
		cout << Scores[i] << endl;
	};
	cout << endl;
}

int ReturnHighestScore(int Scores[], int NumberOfScores)
{
	int i;
	int MaxScore;

	MaxScore = Scores[0];
	for (i = 1; i < NumberOfScores; i++)
	{
		if (MaxScore < Scores[i]) MaxScore = Scores[i];
	};

	return (MaxScore);
}

int ReturnLowestScore(int Scores[], int NumberOfScores)
{
	int i;
	int LowScore;

	LowScore = Scores[0];
	for (i = 1; i < NumberOfScores; i++)
	{
		if (LowScore > Scores[i]) LowScore = Scores[i];
	};

	return (LowScore);
}

float ReturnAverageScore(int Scores[], int NumberOfScores)
{
	int i;
	float TotalOfAllScores = 0;
	
	for (i = 0; i < NumberOfScores; i++)
	{
		TotalOfAllScores += Scores[i];
	};

	return (TotalOfAllScores / NumberOfScores);
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool Quit = false;
	int Scores[10] = { 56, 89, 78, 66, 72, 99, 95, 100, 85, 68 };
	int Row, i;
	int CountHigherThanRow;
	ofstream myfile;
	
	do
	{
		DisplayMenuHeader();
		DisplayMenu();
		switch (GetUserMenuSelection(1, 8))
		{
		case 1:  //Read in 10 scores from user.
			GetScoresFromUser(Scores, 10);			
			break;

		case 2:  //Read in 10 scores from the file, scores.txt.
			cout << "User Selected 2" << endl;
			myfile.open("example.txt");
			myfile << "Writing this to a file.\n";
			myfile.close();
			break;

		case 3:  //Print all scores.
			DisplayAllScores(Scores, 10);
			break;

		case 4:  //Print the highest score.
			cout << "The highest score is " << ReturnHighestScore(Scores, 10) << endl << endl;
			break;

		case 5:  //Print the lowest score.
			cout << "The lowest score is " << ReturnLowestScore(Scores, 10) << endl << endl;
			break;

		case 6:  //Print the average score.
			cout << "The average score is ";
			std::cout << std::fixed << std::setprecision(2) <<  ReturnAverageScore(Scores, 10) << endl << endl;
			break;

		case 7:  //Print one score (give its entry number)
			cout << "Please enter entry or row # of score you want:";
			cin >> Row;
			cout << endl << "Entry #" << Row << " score:" << Scores[Row-1] << endl << endl;
			CountHigherThanRow = 0;
			for (i = 0; i < 10; i++)
			{
				if (Scores[Row-1] < Scores[i])
				{
					CountHigherThanRow++;
				}
			}
			cout << "Score statistics:" << CountHigherThanRow << " higher" << endl << endl;
			break;

		case 8:  //Quit program
			cout << "User Selected 8" << endl;
			// no break to allow case to fall through into default
		default:
			Quit = true;
		}
	} while (Quit == false);
		
	return 0;
}

