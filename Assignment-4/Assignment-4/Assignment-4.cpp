// Assignment-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int GetValidIntFromUserAndDisplayMenu(string Prompt, int Low, int High, bool DisplayMenu);

void GetScoresFromUser(int Scores[], int NumberOfScores);
void GetScoresFromFile(int Scores[], int NumberOfScores);

void DisplayMenu();
void DisplayProgramExit();
void DisplayAllScores(int Scores[], int NumberOfScores);
void DisplayHighestScore(int Scores[], int NumberOfScores);
void DisplayLowestScore(int Scores[], int NumberOfScores);
void DisplayAverageScore(int Scores[], int NumberOfScores);
void DisplayOneScoreSelectedByUser(int Scores[], int NumberOfScores);

int _tmain(int argc, _TCHAR* argv[])
{
	bool Quit = false;
	const int MaxNumberOfScores = 10;
	int Scores[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	do
	{
		switch (GetValidIntFromUserAndDisplayMenu("Enter your choice: ", 1, 8, true))
		{
		case 1:  //Read in scores from user.
			GetScoresFromUser(Scores, MaxNumberOfScores);			
			break;

		case 2:  //Read in scores from the file, scores.txt.
			GetScoresFromFile(Scores, MaxNumberOfScores);
			
			break;

		case 3:  //Print all scores.
			DisplayAllScores(Scores, MaxNumberOfScores);
			break;

		case 4:  //Print the highest score.
			DisplayHighestScore(Scores, MaxNumberOfScores);
			break;

		case 5:  //Print the lowest score.
			DisplayLowestScore(Scores, MaxNumberOfScores);
			break;

		case 6:  //Print the average score.
			DisplayAverageScore(Scores, MaxNumberOfScores);
			break;

		case 7:  //Print one score (give its entry number)
			DisplayOneScoreSelectedByUser(Scores, MaxNumberOfScores);
			break;

		case 8:  //Quit program
			DisplayProgramExit();
			// no break to allow case to fall through into default
		default:
			Quit = true;
		}
	} while (Quit == false);
	
	system("PAUSE");
	return 0;
}

int GetValidIntFromUserAndDisplayMenu(string Prompt, int Low, int High, bool PrintMenu)
{
	int UserSelection;
	bool KeepAsking;

	do
	{
		if (PrintMenu)
		{
			DisplayMenu();
		}
		UserSelection = Low - 1;
		cout << Prompt;
		KeepAsking = false;
		if (!(cin >> UserSelection) || (UserSelection < Low) || (UserSelection > High))
		{
			cout << "INVALID CHOICE ...please retype" << endl << endl;
//			cout << "Choice must be a number between " << Low << " and " << High << endl << endl;
			KeepAsking = true;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (KeepAsking);

	cout << endl;

	return(UserSelection);
};

void DisplayMenu()
{
	cout << "---------------------------------------------------" << endl;
	cout << "1-D ARRAY PROCESSING MENU OPTIONS" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "1. Read in 10 scores from user." << endl;
	cout << "2. Read in 10 scores from the file, scores.txt." << endl;
	cout << "3. Print all scores." << endl;
	cout << "4. Print the highest score." << endl;
	cout << "5. Print the lowest score." << endl;
	cout << "6. Print the average score." << endl;
	cout << "7. Print one score (give its entry number)" << endl;
	cout << "8. Quit program" << endl << endl;
};

void DisplayProgramExit()
{
	cout << "Array processing test now concluded. Exiting program ....." << endl << endl << endl;
	cout << "Process returned 0 (0x0)" << endl;
};

void GetScoresFromUser(int Scores[], int NumberOfScores)
{
	int i;
	bool KeepAsking;

	for (i = 0; i < NumberOfScores; i++)
	{
		do
		{
			KeepAsking = false;
			cout << "Enter Score #:" << (i + 1) << " ";
			if (!(cin >> Scores[i]))
			{
				cout << "Score must be an integer" << endl;
				KeepAsking = true;
			};
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (KeepAsking);
	};
	cout << endl;
}

void GetScoresFromFile(int Scores[], int NumberOfScores)
{
	int i,j;
	bool KeepAsking;
	ifstream Scoresfile;
	string Filename;
	int TempScores[10];

	do
	{
		KeepAsking = false;
		cout << "Please enter filename:";
		if (!(cin >> Filename))
		{
			KeepAsking = true;
			cout << "File name must be a string" << endl;
		}
		else
		{
			Scoresfile.open(Filename);
			if (!Scoresfile)
			{
				KeepAsking = true;
				cout << "File not found" << endl;
			}
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (KeepAsking);
	
	for (i = 0; i < NumberOfScores && !Scoresfile.eof(); i++)
	{
		TempScores[i] = Scores[i];
		Scoresfile >> Scores[i];
	}
	if (i == NumberOfScores)
	{
		cout << "File has successfully opened and " << i << " scores have been read and stored." << endl;
		cout << "Please select the print all scores menu option to view the scores" << endl;
	}
	else
	{
		cout << "File error or file did not have enough data" << endl << endl;
		for (j = 0; j < i; j++)
		{
			Scores[j] = TempScores[j];
		}
	}
	Scoresfile.close();
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

void DisplayHighestScore(int Scores[], int NumberOfScores)
{
	int i;
	int MaxScore;

	MaxScore = Scores[0];
	for (i = 1; i < NumberOfScores; i++)
	{
		if (MaxScore < Scores[i]) MaxScore = Scores[i];
	};

	cout << "The highest score is " << MaxScore << endl << endl;
}

void DisplayLowestScore(int Scores[], int NumberOfScores)
{
	int i;
	int LowScore;

	LowScore = Scores[0];
	for (i = 1; i < NumberOfScores; i++)
	{
		if (LowScore > Scores[i]) LowScore = Scores[i];
	};

	cout << "The lowest score is " << LowScore << endl << endl;
}

void DisplayAverageScore(int Scores[], int NumberOfScores)
{
	int i;
	float TotalOfAllScores = 0;

	for (i = 0; i < NumberOfScores; i++)
	{
		TotalOfAllScores += Scores[i];
	};

	cout << "The average score is ";
	std::cout << std::fixed << std::setprecision(2) << (TotalOfAllScores / NumberOfScores) << endl << endl;

}

void DisplayOneScoreSelectedByUser(int Scores[], int NumberOfScores)
{
	int Row, i;
	int CountHigherThanRow;

	Row = GetValidIntFromUserAndDisplayMenu("Please enter entry or row # of score you want:", 1, NumberOfScores, false);

	cout << endl << "Entry #" << Row << " score:" << Scores[Row - 1] << endl << endl;
	CountHigherThanRow = 0;
	for (i = 0; i < 10; i++)
	{
		if (Scores[Row - 1] < Scores[i])
		{
			CountHigherThanRow++;
		}
	}
	cout << "Score statistics:" << CountHigherThanRow << " higher" << endl << endl;
}
