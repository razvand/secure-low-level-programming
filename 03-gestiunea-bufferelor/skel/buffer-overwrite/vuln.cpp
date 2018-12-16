#include <iostream>

static void leak_and_overwrite_data(void)
{
	unsigned int v = 0xAABBCCDD;
	unsigned int buffer[64];
	unsigned int r;
	int n;

	std::cout << "address of v: " << std::hex << &v << std::endl;
	std::cout << "address of buffer: " << buffer << std::endl;
	std::cout << std::dec;

	std::cout << "Provide index to leak (789 to stop)" << std::endl;
	while (1) {
		std::cout << "> ";
		std::cin >> n;
		if (std::cin.eof())
			break;
		if (n == 789)
			break;
		std::cout << "buffer[" << n << "] = 0x" << std::hex << buffer[n] << std::endl;
		std::cout << std::dec;
	}

	std::cout << "Provide index and value to overwrite (789 to stop)" << std::endl;
	while (1) {
		std::cout << "(index) > ";
		std::cin >> n;
		if (std::cin.eof())
			break;
		if (n == 789)
			break;

		std::cout << "(value) > ";
		std::cin >> r;
		if (std::cin.eof())
			break;
		buffer[n] = r;
	}

	if (v == 87654321)
		std::cout << "You've got it. Congratulations!" << std::endl;
	else
		std::cout << "Not yet. Try again!" << std::endl;
}

int main()
{
	leak_and_overwrite_data();

	return 0;
}
