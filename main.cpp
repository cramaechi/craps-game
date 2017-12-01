#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int getRoll();
//Precondition:
//Returns the roll of the dices.

double winningProbability(double w, double l);
//Preconditions: w and l are both non-negative, non-zero integers.
//Returns the winning probability.

bool playerWins(int roll, int point, int numberOfRolls);
//Precondition: r is a non-negative, non-zero integer.
//Returns true if r is 7 or 11 and false if r isn't 7 or 11.

bool playerLoses(int roll, int numberOfRolls);
//Precondition: r is a non-negative, non-zero integer.
//Returns true if r is 2, 3, or 12 and false if r isn't those numbers.

bool isPointNumber(int roll);
//Precondition: r is a non-integer, non-zero number.
//Returns true if r is the "point" and false if not.

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int roll, point = 0, wins = 0, losses = 0;
	
	for(int i = 1; i <=10000; i++)
	{
        int count = 0;

        while(true)
		{ 
			++count;
			roll = getRoll();
			
			if (isPointNumber(roll) && count == 1)
				point = roll;
			else if (playerWins(roll, point, count))
            {
				++wins;
                break;
            }
			else if (playerLoses(roll, count))
            {
				++losses;
                break;
            }
		}
	}

	cout<<"The player's winning probability is: "<<winningProbability(wins, losses) * 100<<"% over the long run.\n";

	//system("pause");
	return 0;
}

int getRoll()
{
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;

	return dice1 + dice2;
}

double winningProbability(double w, double l)
{
	return (w/(w+l)); 
}

bool playerWins(int roll, int point, int numberOfRolls)
{
	return((numberOfRolls == 1 && (roll == 7 || roll == 11)) || (numberOfRolls > 1 && roll == point));
}

bool playerLoses(int roll, int numberOfRolls)
{
	return((numberOfRolls == 1 && (roll == 2 || roll == 3 || roll == 12)) || (numberOfRolls > 1 && roll == 7));
}

bool isPointNumber(int roll)
{
	return(roll == 4 || roll == 5 || roll == 6 || roll == 8 || roll == 9 || roll == 10);
}



