#include "Math.h"

int main() {
	std::string equation;

	std::cout << "Input an equation: ";
	std::getline(std::cin, equation);
	removeWhiteSpace(equation);

	std::cout << std::endl << "You inputted the equation: " << equation << std::endl;
	printNumbers(getNumbers(equation));
	splitEquation(equation);
	std::cin.get();

	return 0;
}