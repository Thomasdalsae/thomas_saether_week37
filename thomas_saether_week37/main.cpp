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
	

	


	for (int row = 0; row < 10; row++)
	{
		board.push_back(std::vector<char>{});
		for (int col = 0; col < 10; col++)
		{
			board[row].push_back('-');
			

			
		}
		
	}
	

	board[5][5] = '\\';
	board[2][4] = '/';
	board[7][4] = 'G';
	board[playerPos[0]][playerPos[1]] = 'X';
	boardLayout(board);

	while (true)
	{
		
		
		
		
		
			board[playerPos[0]][playerPos[1]] = '-';
		
		
		char b = _getch();

		switch (b)
		{
		case 'w': case 'W':


			playerPos[1] += -1;
			

			break;

		case 's': case 'S':
			playerPos[1] += 1;
	
			break;

		case 'a': case 'A':

			playerPos[0] += -1;
			
			break;
		case 'd': case 'D':
			playerPos[0] += 1;
			
				
			break;

		default:
			break;
		}


		if (board[playerPos[0]][playerPos[1]] == '\\')
		{

			playerPos[1] += -1;

		}
		else if (board[playerPos[0]][playerPos[1]] == '/')
		{
			playerPos[1] += 1;
		}
		else if (board[playerPos[0]][playerPos[1]] == 'G')
		{
			exit(0);
		}

		board[playerPos[0]][playerPos[1]] = 'X';

		
		system("cls");
		
		boardLayout(board);
		
	}
}
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



	struct People {

		std::string name;
		int phoneNr{};

	};
	std::vector<People>Person;
	People temp1;

	char answer{};
	int i{};
	
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
for (size_t j = 0; j < i; j++) {
	std::cout << Person[j].name << std::endl;
	std::cout << Person[j].phoneNr << std::endl;
}
}


void task4() {

	std::vector<int>Dices;
	diceRoll(Dices);

	for (int j = 0; j < Dices.size(); j++)
	{
		std::cout << Dices[j] << std::endl;
		
		
	}




}




void diceRoll(std::vector<int>&Dices) {


	int dice;

	for (size_t i = 0; i < 5; i++)
	{
		
		
		Dices.push_back(randomizer());
	
	}
	
}




/*How randomizer workd
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
