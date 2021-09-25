#include <iostream>
#include <vector>
#include <conio.h>

void task1();
void task2();

int main() {
	//task1();
	task2();
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


