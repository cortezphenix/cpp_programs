/*
Driver License Test; Cortez Phenix
This program is a driver license test, notable for its use of arrays and loops. 
*/

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

bool validateInput(char);
int driverTest();
void getIncorrectlyAnsweredQuestions();
void getOutput(int);

const int NUM_OF_QUESTIONS = 20;
const int PASSING_SCORE = 15;
char correctAnswers[] {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D',
					        'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'};
int incorrectlyAnsweredQuestions[NUM_OF_QUESTIONS];
char userAnswers[NUM_OF_QUESTIONS];

int main()
{
	cout << "Welcome to your driver license test!\n\nThis test has 20 questions. These questions have been provided to you.\nIn order to pass this test, you must correctly answer 15 (75%) of the questions.\nAnswer each question. The only answers allowed are A, B, C or D.\nGood luck!\n\n";

	int correctAnswersCounter = 0;

	for (int i = 0; i < NUM_OF_QUESTIONS; i++)
	{
		//get input and validate it
		do
		{
			cout << "Please enter your answer for question #" << i + 1 << " ";
			cin >> userAnswers[i];
		} while (!validateInput(userAnswers[i]));
	}

	correctAnswersCounter = driverTest();
	if (correctAnswersCounter < NUM_OF_QUESTIONS)
	{
		getIncorrectlyAnsweredQuestions();
	}

	getOutput(correctAnswersCounter);

	return 0;
}

void getOutput(int counter)
{
	cout << "\nYou have " << (counter >= PASSING_SCORE ? "PASSED" : "FAILED") << " the test!" << endl;
	cout << "You have answered " << counter << " correctly and " << (NUM_OF_QUESTIONS - counter) << " incorrectly!" << endl;

	//if some answers were wrong, output what answer was wrong, what was the correct answer, and what was the user answer
	if (counter < NUM_OF_QUESTIONS)
	{
		cout << "The following questions were answered incorrectly: \n";
		for (int i = 0; i < NUM_OF_QUESTIONS - counter; i++)
		{
			cout << "Question #" << (incorrectlyAnsweredQuestions[i] + 1) << ". Correct answer was " <<
				correctAnswers[incorrectlyAnsweredQuestions[i]] << ". You answer was " << userAnswers[incorrectlyAnsweredQuestions[i]] << endl;
		}
	}
}

void getIncorrectlyAnsweredQuestions()
{
	int counter = 0; //index of the incorrectlyAnsweredQuestions array
	for (int i = 0; i < NUM_OF_QUESTIONS; i++)
	{
		if (correctAnswers[i] != toupper(userAnswers[i]))
		{
			incorrectlyAnsweredQuestions[counter] = i;
			counter++;
		}
	}
}

int driverTest()
{
	int counter = 0;
	for (int i = 0; i < NUM_OF_QUESTIONS; i++)
	{
		if (toupper(userAnswers[i]) == correctAnswers[i])
			counter++;
	}

	return counter;
}

bool validateInput(char answer)
{
	//only A, B, C, D is valid input
	if (toupper(answer) != 'A' && toupper(answer) != 'B' && toupper(answer) != 'C' && toupper(answer) != 'D')
	{
		cout << "\nInvalid input! ";
		return false;
	}

	return true;
}

/*
cortez@cortez-HP-Laptop-14-dk0xxx:~/Programming & Web Dev. Work/C++/Assignment 6- Driver License Test$

Welcome to your driver license test!

This test has 20 questions. These questions have been provided to you.
In order to pass this test, you must correctly answer 15 (75%) of the questions.
Answer each question. The only answers allowed are A, B, C or D.
Good luck!

Please enter your answer for question #1 B
Please enter your answer for question #2 D
Please enter your answer for question #3 A
Please enter your answer for question #4 A
Please enter your answer for question #5 C
Please enter your answer for question #6 A
Please enter your answer for question #7 B
Please enter your answer for question #8 A
Please enter your answer for question #9 C
Please enter your answer for question #10 D
Please enter your answer for question #11 B
Please enter your answer for question #12 C
Please enter your answer for question #13 D
Please enter your answer for question #14 A
Please enter your answer for question #15 D
Please enter your answer for question #16 C
Please enter your answer for question #17 A
Please enter your answer for question #18 A
Please enter your answer for question #19 A
Please enter your answer for question #20 A

You have PASSED the test!
You have answered 17 correctly and 3 incorrectly!
The following questions were answered incorrectly:
Question #17. Correct answer was C. You answer was A
Question #18. Correct answer was B. You answer was A
Question #19. Correct answer was D. You answer was A
*/
