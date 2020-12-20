#include <iostream>
#include <string>

void backwards(unsigned long long& input) {
	std::cout << input % 10;
	input /= 10;
	if (input == 0) {
		return;
	}
	backwards(input);
}

void new_line(unsigned long long& input, unsigned long long& placeholder) {
	
	if (input > 0) {
		placeholder += input % 10;
		if (input > 9) {
			placeholder *= 10;
		}
		input /= 10;
		new_line(input, placeholder);
	}
	else if (placeholder > 0){
		std::cout << placeholder % 10 << "\n";
		placeholder /= 10;
		new_line(input, placeholder);
	}
	else {
		return;
	}
}

void sum(int n, unsigned long long& summation, unsigned long long tally) {
	if (tally <= n) {
		summation += tally;
		tally++;
		sum(n, summation, tally);
	 }
	else {
		std::cout << summation << "\n";
	}

}

void squares(int n, unsigned long long& square_summation, unsigned long long tally) {
	if (tally <= n) {
		square_summation += (tally * tally);
		tally++;
		squares(n, square_summation, tally);
	}
	else {
		std::cout << square_summation << "\n";
	}
}

void divisors(unsigned long long input3, unsigned long long divisor) {
	if (input3 % divisor == 0) {
		std::cout << divisor;
		return;
	}
	else if (input3 % divisor != 0) {
		divisor--;
		divisors(input3, divisor);
	}
	else {
		return;
	}
}

void palindrome(std::string possible_palindrome, int i, bool is_palindrome) {
	if ((possible_palindrome[i] == possible_palindrome[possible_palindrome.size() - 1 - i]) && (i < (possible_palindrome.size()/2) + 1)) {
		is_palindrome = true;
		i++;
		palindrome(possible_palindrome, i, is_palindrome);
}
	else if ((possible_palindrome[i] != possible_palindrome[possible_palindrome.size() - 1 - i])) {
		is_palindrome = false;
	}
	else {
		std::cout << is_palindrome << "\n";
	}
}

void string_converter(int number, std::string converted) {
	if (number > 0) {
		converted += number % 10 + 48;
		number /= 10;
		string_converter(number, converted);
	}
	else {
		std::string new_string;
		for (int i = 0; i < converted.size(); i++) {
			new_string += converted[converted.size() - 1 - i];
		}
		std::cout << new_string << "\n";
	}
}

void binary(int integer_input, std::string binary_output) {
	if (integer_input > 0) {
		binary_output += integer_input % 2 ? "1": "0";
		integer_input /= 2;
		binary(integer_input, binary_output);
	}
	else {
		std::string new_string;
		for (int i = 0; i < binary_output.size(); i++) {
			new_string += binary_output[binary_output.size() - 1 - i];
		}
		std::cout << new_string << "\n";
	}
}

int main() {
	unsigned long long input = 12345678;
	unsigned long long input2 = 12345678;
	unsigned long long input3 = 30;
	unsigned long long divisor = input3 - 1;
	int n = 50;
	unsigned long long summation = 0;
	unsigned long long square_summation = 0;
	unsigned long long tally = 1;
	unsigned long long placeholder = 0;
	std::string possible_palindrome = "tacocat";
	int i = 0;
	bool is_palindrome = false;
	int number = 12345;
	std::string converted = "";
	int integer_input = 12;
	std::string binary_output = "";

	std::cout << "Number flipper:\n";
	backwards(input);
	std::cout << std::endl << "New line converter\n";
	new_line(input2, placeholder);
	std::cout << std::endl << "Summation calculator\n";
	sum(n, summation, tally);
	std::cout << std::endl << "Sum of squares calculator\n";
	squares(n, square_summation, tally);
	std::cout << std::endl << "Highest divisor calculator\n";
	divisors(input3, divisor);
	std::cout << std::endl << "Palindrome checker\n";
	palindrome(possible_palindrome, i, is_palindrome);
	std::cout << std::endl << "Integer to String converter\n";
	string_converter(number, converted);
	std::cout << std::endl << "Integer to binary converter\n";
	binary(integer_input, binary_output);
}