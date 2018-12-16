#include <iostream>
#include <cstdlib>

static unsigned int compare = 5000;

static void trigger_func(int n)
{
	if (n * 16 > compare)
		std::cout << "You got it! Congratulations!" << std::endl;
	else
		std::cout << "Nope. Try again!" << std::endl;
}

int main()
{
	int n;

	std::cout << "Insert number (<= 100): ";
	std::cin >> n;
	if (n > 100) {
		std::cout << "Number must be less or equal to 100." << std::endl;
		exit(EXIT_FAILURE);
	}
	trigger_func(n);

	return 0;
}
