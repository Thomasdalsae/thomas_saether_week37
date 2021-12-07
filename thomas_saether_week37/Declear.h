#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <random> 



void task1();
void task2();
void task3();
void task4();
int randomizer();
void diceRoll(std::vector<int>&);



int randomizer() {
	std::random_device rd{};

	std::mt19937 engine(rd());

	std::uniform_int_distribution<int> dist(0, 6);

	int x = dist(engine);

	return x;

}

