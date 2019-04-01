#include "Math.h"

#include <ctype.h>
#include <regex>

void removeWhiteSpace(std::string& str) {
	int i = str.length() - 1;
	while ((i--) > 0) {
		if (str.at(i) == ' ') {
			str.erase(i, 1);
			i++;
		}
	}
}

// Split Equation
// 1. Find first operator (using PEMDAs + going left to right)
// 2. Number to the left is the number of origin
// 3. The operator and the number on the right are a term.

// Iterating over regex matches - https://stackoverflow.com/a/39080627
void splitEquation(std::string equation) {
	std::smatch res;
	std::regex pemdas("([\+])");
	//std::string copy = equation;

	/*std::regex_search(equation, res, pemdas);
	std::cout << res.size() << std::endl;
	for (unsigned i = 0; i < res.size(); i++) {
		std::cout << res[i] << " found at position: " << res.position(i) << std::endl;
	}*/

	while (std::regex_search(equation, res, pemdas)) {
		for (auto match : res) {
			std::cout << match << std::endl;
		}
		
		equation = res.suffix().str();
	}
}

std::vector<int> getNumbers(const std::string& str) {
	std::vector<int> numbers;
	std::string number = "";
	int length = str.length();

	for (int i = 0; i < length; i++) {
		char chr = str.at(i);
		if (isdigit(chr)) {
			number += chr;
		}

		if (!isdigit(chr) || i == length - 1) {
			if (number.length() > 0) {
				numbers.push_back(std::stoi(number));
				number = "";
			}
		}
	}

	return numbers;
}

void printNumbers(std::vector<int> numbers) {
	int length = numbers.size();

	for (int i = 0; i < length; i++) {
		if (i < length - 1) {
			std::cout << numbers[i] << ", ";
		} else {
			std::cout << numbers[i];
		}
	}

	std::cout << std::endl;
}