#include <iostream> 
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main()
{
	//seed random number generator 
	srand(static_cast<unsigned int>(time(0)));

	//represents numbers on 8x8 grid 
	int human_searchGridLowNumber = 1;
	int human_searchGridHighNumber = 64;
	int binary_AI_searchGridLowNumber = 1;
	int binary_AI_searchGridHighNumber = 64;
	int linear_AI_searchGridLowNumber = 1;
	int linear_AI_searchGridHighNumber = 64;
	int random_AI_searchGridLowNumber = 1;
	int random_AI_searchGridHighNumber = 64;

	//Generate location of lost soul at a random number between 1 and 64 same for everyone 
	int actualTargetLocation = rand() % binary_AI_searchGridHighNumber + binary_AI_searchGridLowNumber;

	//Keeps track of search location and number of tries 
	int human_tries = 0;
	int human_attemptLocateTarget = 0;
	//Integer keeps track of number or attemps for binary AI 
	int binary_AI_tries = 0;
	//integer variable, actual number on grid the AI is currently seaching 
	int binary_AI_attemptLocateTarget = 0;
	int linear_AI_tries = 0;
	int linear_AI_attemptLocateTarget = 0;
	int random_AI_tries = 0;
	int random_AI_attemptLocateTarget = 0;
	//boolean to determine if the game will play again or not based on user input
	bool play_again = true;

	while (play_again) {
		//Title for simulation 
		cout << "\tWelcome to search and rescue\n";

		//***Human attempt to find target start*** 
		do
		{
			//This is where the human makes a guess where the target is located 

			cout << "Real target location is at a secret location\n";
			cout << "Enter a number on the grid " << human_searchGridLowNumber << "-" << human_searchGridHighNumber << " where you think the enemy is hiding at\n";
			cin >> human_attemptLocateTarget;
			++human_tries;

			//If the human guess too high this happens 
			if (human_attemptLocateTarget > actualTargetLocation)
			{
				cout << "The human attempted guess was too high!\n\n";
				//This is where we refine our search based on the last guess 
				human_searchGridHighNumber = human_attemptLocateTarget - 1;
			}
			//If the human guess too low this happens 
			else if (human_attemptLocateTarget < actualTargetLocation)
			{
				cout << "The human attempted guess was too low\n\n";
				//This is where we refine our search based on the last guess 
				human_searchGridLowNumber = human_attemptLocateTarget + 1;
			}
			//Once the human guesses the correct location this will happen 
			else
			{
				cout << "\nThat's it! You got it in " << human_tries << " guesses!\n\n";
			}
			//Maintains the loop until the AI guesses the correct location 
		} while (human_attemptLocateTarget != actualTargetLocation);
		//***Human attempt to find target end*** 

			//Pause between players
		cout << "\n\n The human is finished, to see the next player ";
		system("pause");

		//***Linear AI Start*** 
		//loop that continues until Linear AI finds target 
		do
		{
			//This is where the AI makes a guess where the target is located using the linear search pattern 
			linear_AI_attemptLocateTarget++;
			linear_AI_tries++;
			cout << "Real target location is at " << actualTargetLocation << endl;
			cout << "The linear AI guesses the lost soul is at location " << linear_AI_attemptLocateTarget << endl;

			//If the AI guess too high this happens 
			if (linear_AI_attemptLocateTarget > actualTargetLocation)
			{
				cout << "The linear AI's attempted guess was too high!\n\n";
			}
			//If the AI guess too low this happens 
			else if (linear_AI_attemptLocateTarget < actualTargetLocation)
			{
				cout << "The linear AI's attempted guess was too low\n\n";
			}
			//Once the AI guesses the correct location this will happen 
			else
			{
				cout << "\nThat's it! You got it in " << linear_AI_tries << " guesses!\n";
			}
			//Maintains the loop until the AI guesses the correct location 
		} while (linear_AI_attemptLocateTarget != actualTargetLocation);
		//***Linear AI End*** 

			//Pause between players
		cout << "\n\n The linear AI is finished, to see the next player ";
		system("pause");

		//***Randomn AI Start*** 
		//loop that continues until random AI finds target 
		do
		{
			//This is where the AI makes a guess where the target is located using the random search pattern 
			random_AI_attemptLocateTarget = rand() % random_AI_searchGridHighNumber + random_AI_searchGridLowNumber;
			random_AI_tries++;
			cout << "Real target location is at " << actualTargetLocation << endl;
			cout << "The random AI guesses the lost soul is at location " << random_AI_attemptLocateTarget << endl;
			//cout << "numbers between " << random_AI_searchGridHighNumber << "-" << random_AI_searchGridLowNumber;
			//If the AI guess too high this happens 
			if (random_AI_attemptLocateTarget > actualTargetLocation)
			{
				cout << "The random AI's attempted guess was too high!\n\n";
				//This is where we refine our search based on the last guess 
				//random_AI_searchGridHighNumber = random_AI_attemptLocateTarget - 1;
			}
			//If the AI guess too low this happens 
			else if (random_AI_attemptLocateTarget < actualTargetLocation)
			{
				cout << "The random AI's attempted guess was too low\n\n";
				//This is where we refine our search based on the last guess 
				//random_AI_searchGridLowNumber = random_AI_attemptLocateTarget + 1;
			}
			//Once the AI guesses the correct location this will happen 
			else
			{
				cout << "\nThat's it! You got it in " << random_AI_tries << " guesses!\n";
			}
			//Maintains the loop until the AI guesses the correct location 
		} while (random_AI_attemptLocateTarget != actualTargetLocation);
		//***random AI End*** 

			//Pause between players
		cout << "\n\n The random AI is finished, to see the next player ";
		system("pause");

		//***Binary AI Start*** 
		//loop that continues until Binary AI finds target 
		do
		{
			//This is where the AI makes a guess where the target is located using the binary search pattern 
			binary_AI_attemptLocateTarget = ((binary_AI_searchGridHighNumber - binary_AI_searchGridLowNumber) / 2) + binary_AI_searchGridLowNumber;;
			++binary_AI_tries;
			cout << "Real target location is at " << actualTargetLocation << endl;
			cout << "The AI guesses the lost soul is at location " << binary_AI_attemptLocateTarget << endl;

			//If the AI guess too high this happens 
			if (binary_AI_attemptLocateTarget > actualTargetLocation)
			{
				cout << "The Binary AI's attempted guess was too high!\n\n";
				//This is where we refine our search based on the last guess 
				binary_AI_searchGridHighNumber = binary_AI_attemptLocateTarget - 1;
			}
			//If the AI guess too low this happens 
			else if (binary_AI_attemptLocateTarget < actualTargetLocation)
			{
				cout << "The Binary AI's attempted guess was too low\n\n";
				//This is where we refine our search based on the last guess 
				binary_AI_searchGridLowNumber = binary_AI_attemptLocateTarget + 1;
			}
			//Once the AI guesses the correct location this will happen 
			else
			{
				cout << "\nThat's it! You got it in " << binary_AI_tries << " guesses!\n";
			}
			//Maintains the loop until the AI guesses the correct location 
		} while (binary_AI_attemptLocateTarget != actualTargetLocation);
		//***Binary AI End***

		//Pause between players
		cout << "\n\n The binary AI is finished, to see who won ";
		system("pause");

		//***Who won*** 
		cout << "\n\n The Final Results are\n";
		cout << "The human found it in " << human_tries << "guesses!\n";
		cout << "The linear AI found it in " << linear_AI_tries << "guesses!\n";
		cout << "The random AI found it in " << random_AI_tries << "guesses!\n";
		cout << "The binary AI found it in " << binary_AI_tries << "guesses!\n";

		//This is where we compare the results, looking for the lowest number of attemps
		if (human_tries < linear_AI_tries && human_tries < random_AI_tries && human_tries < binary_AI_tries)
		{
			cout << "\nThe human bested the AI...for now" << endl;
		}
		else if (linear_AI_tries < human_tries && linear_AI_tries < random_AI_tries && linear_AI_tries < binary_AI_tries)
		{
			cout << "\nThe linear AI is the winner!" << endl;
		}
		else if (random_AI_tries < human_tries && random_AI_tries < linear_AI_tries && random_AI_tries < binary_AI_tries)
		{
			cout << "\nThe Random AI is the winner" << endl;
		}
		else if (binary_AI_tries < human_tries && binary_AI_tries < linear_AI_tries && binary_AI_tries < random_AI_tries)
		{
			cout << "\nThe binary search AI is the winner" << endl;
		}
		else
		{
			cout << "There was a tie\n" << endl;
		}
		cout << "Would you like to play again? type y or n\n";
		// get user input on whether they want to play again or not
		char answer;
		cin >> answer;
		//exit the game
		if (answer != 'y')
		{
			play_again = false;
		}
		//reset the game to play again
		else if (answer = 'y')
		{
			actualTargetLocation = rand() % binary_AI_searchGridHighNumber + binary_AI_searchGridLowNumber;
			human_searchGridHighNumber = 64;
			human_searchGridLowNumber = 1;
			human_tries = 0;
			linear_AI_attemptLocateTarget = 0;
			linear_AI_tries = 0;
			random_AI_attemptLocateTarget = 0;
			random_AI_tries = 0;
			binary_AI_attemptLocateTarget = 0;
			binary_AI_searchGridHighNumber = 64;
			binary_AI_searchGridLowNumber = 1;
			binary_AI_tries = 0;
			
		}
		
	}
	return 0;
}
