#include "Declear.h"




int main() {
	//task1();
	task2();
	//task3();
	//task4();
	return 0;
}

void task1() {

	int numberOne{};
	//this is basically where i put all the operations
	char doerer{};
	int numberTwo{};
	char input{};
	int result{};

	std::cout << "Give me the first number";
	std::cin >> numberOne;


	std::cout << "Give me the doerer : ";
	std::cin >> doerer;


	std::cout << "Give me the second number";
	std::cin >> numberTwo;

	
	switch (doerer)
	{
		case '+':
			result = numberOne + numberTwo;
			break;


		case '-':
			result = numberOne - numberTwo;
			break;
				
		case '*':
			result = numberOne * numberTwo;
			break;

		case '/':
			result = numberOne / numberTwo;
			break;
		
	}


	std::cout << numberOne << doerer << numberTwo <<" = " << result;



}
void task2() {

	void boardLayout(std::vector<std::vector<char>>board);
    std::vector<std::vector<char>>board;
	std::vector<int> playerPos = { 0,0 };
	

	

	//prepears the vector 10X10
	for (int row = 0; row < 10; row++)
	{
		board.push_back(std::vector<char>{});
		for (int col = 0; col < 10; col++)
		{
			board[row].push_back('-');
			

			
		}
		
	}
	
	//Location to the symbol (make the player go up)
	board[5][5] = '\\';
	//Location to the symbol (makes the player go down)
	board[2][4] = '/';
	//Location to the symbol (makes the player exit the program)
	board[7][4] = 'G';
	//Location start for the player
	board[playerPos[0]][playerPos[1]] = 'X';
	//Prints a copy that updates
	boardLayout(board);

	while (true)
	{
		
		
		
		
		
			board[playerPos[0]][playerPos[1]] = '-';
		
		//command that makes the player input work instantly (no need to press enter each time)
		char b = _getch();

		switch (b)
		{
			//Player goes up
		case 'w': case 'W':


			playerPos[1] += -1;
			

			break;
			//Player goes down
		case 's': case 'S':
			playerPos[1] += 1;
	
			break;
			//Player goes left
		case 'a': case 'A':

			playerPos[0] += -1;
			
			break;
			//Player goes right
		case 'd': case 'D':
			playerPos[0] += 1;
			
				
			break;

		default:
			break;
		}

		
		//This forces the player to go up a lvl. the players current location (inn the vector) pluss one in the row.
		if (board[playerPos[0]][playerPos[1]] == '\\')
		{

			playerPos[1] += -1;

		}
		//This forces the player to go down a lvl. the players current location (inn the vector) minus one in the row.
		else if (board[playerPos[0]][playerPos[1]] == '/')
		{
			playerPos[1] += 1;
		}
		//exits the program
		else if (board[playerPos[0]][playerPos[1]] == 'G')
		{
			exit(0);
		}
		//This is to keep track on where the location of the player is.
		board[playerPos[0]][playerPos[1]] = 'X';

		
		system("cls");
		
		boardLayout(board);
		
	}
}

//this is the game board
void boardLayout(std::vector<std::vector<char>> aBoard) {

	for (int i = 0; i < 10; i++)
	{
		
		for (int j = 0; j < 10; j++)
		{
			std::cout << " " << aBoard[j][i] << " ";



		}
		
		std::cout << std::endl;
	}

	
}
void task3() {


	//The struct people contains the information i want on each person.
	struct People {

		std::string name;
		int phoneNr{};

	};
	//this basically means that each person will contain the decidted information inn (people)
	std::vector<People>Person;
	People temp1;

	char answer{};
	int i{};
	//keeps the loop going aslong as needed.
	while (i < 10 && answer != 'n')
	{
		std::cout << "Do you want to add a person? ";
		std::cin >> answer;

		switch (tolower(answer))
		{


		case 'y':
				std::cout << "Enter the name :";
				std::cin >> temp1.name;
				std::cout << "Enter PhoneNr :";
				std::cin >> temp1.phoneNr;

				Person.push_back(temp1);

				i++;
				
				break;
			
		case 'n': 
			break;
		default:
			break;
		}		
	}
	//prints all the information inn the vector.
	for (size_t j = 0; j < i; j++) {
	std::cout << Person[j].name << std::endl;
	std::cout << Person[j].phoneNr << std::endl;
}
}


void task4() {
	char input{};
	char endGame = 'q';
	int holdDice{};
	int holdDicePosition = -1;
	std::vector<int>Dices;
	int diceSix{};
	int dicePair{};

	
	std::cout << "Do you want to roll the dices" << std::endl;
	std::cin >> input;
	
	
	while (true)
	{
		//resets
		Dices.clear();
		diceSix = 0;
		dicePair = 0;
	if (toupper(input) == 'Y')
	{
		
		diceRoll(Dices);
		//it's a saftey measure to avoid putting inn a held dice if not exist
		if (holdDicePosition != -1)
		{
			Dices[holdDicePosition] = holdDice;
		}
		//checks if there ar eany sixers and pairs.
		for (int i = 0; i < Dices.size(); i++)
		{
			std::cout << "Dice"<< i + 1 << " :" << Dices[i] << std::endl << std::endl;
			if (Dices[i] == 6)
			{
				diceSix++;
			}
			for (int j = i; j < Dices.size(); j++)
			{
				if (i != j)
				{

				if (Dices[i] == Dices[j])
				{

					dicePair++;

				}
				}
			}
			


			
		}
		std::cout << "How many SixDices  :" << diceSix <<std::endl;
		std::cout << "How many DicePairs  :" << dicePair <<std::endl;

		//saves the value and the position of the held dice.
		std::cout << "Which dices do you want hold" << std::endl;
		std::cin >> holdDicePosition;
		holdDicePosition = holdDicePosition - 1;
		holdDice = Dices[holdDicePosition];

	}

	std::cout << "Do you want to roll again ?" << std::endl;
	std::cin >> endGame;

	if (toupper(endGame) == 'Y')
	{
		system("cls");
	}
	else
	{
		break;
	}
	}
	
	

}


void diceRoll(std::vector<int>&Dices) {


	int dice;

	for (size_t i = 0; i < 5; i++)
	{
		
		
		Dices.push_back(randomizer());
	
	}
	
}

int randomizer() {
	std::random_device rd{};
	
	std::mt19937 engine(rd());
	
	std::uniform_int_distribution<int> dist(1, 6);
	
	int x = dist(engine);

	return x;



/*How randomizer workd(credits to anders for explaining)
// Use random_device to generate a seed for Mersenne twister engine.
std::random_device rd{};
// Use Mersenne twister engine to generate pseudo-random numbers.
std::mt19937 engine(rd());
// "Filter" MT engine's output to generate pseudo-random int values,
// **uniformly distributed** on the closed interval [0, 6].
// (Note that the range is [inclusive, inclusive].)
std::uniform_int_distribution<int> dist(0, 6);
// Generate pseudo-random number.
int x = dist(engine);*/
