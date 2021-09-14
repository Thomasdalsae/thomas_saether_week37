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
	std::vector<std::vector<int>>board;
	char movement{};
	std::vector<int>player = { 2,5 };


	for (int row = 0; row < 10; row++)
	{
		board.push_back(std::vector<int>{});
		for (int col = 0; col < 10; col++)
		{
			board[row].push_back('-');
			std::cout << " # ";
		}
		std::cout << std::endl;
	}
	 
	char b = _getch();

	switch (b)
	{		
	case 'w' || 'W':
		player[0] += 1;
		
	default:
		break;
	}




}